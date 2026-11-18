
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << "Node inserted successfully.\n";
    }

    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted.\n";
            return;
        }

        Node* temp = head;

        while (temp->next != NULL &&
               temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Element not found.\n";
        } else {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
            cout << "Node deleted.\n";
        }
    }

    void display() {
        Node* temp = head;

        if (temp == NULL) {
            cout << "List is empty.\n";
            return;
        }

        cout << "Linked List: ";

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    ~LinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;

            case 3:
                list.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
