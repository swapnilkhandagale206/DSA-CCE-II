
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node *head = NULL;

void insert() {
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    cout << "Node inserted successfully!\n";
}

void display() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head;

    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void deleteNode() {
    int value;
    cout << "Enter value to delete: ";
    cin >> value;

    Node *temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node not found!\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "Node deleted successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insert(); break;
            case 2: deleteNode(); break;
            case 3: display(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
