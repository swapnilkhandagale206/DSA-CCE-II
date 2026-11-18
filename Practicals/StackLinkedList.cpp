
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;

        cout << "Element pushed successfully.\n";
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow!\n";
            return;
        }

        Node* temp = top;
        cout << "Deleted element: " << top->data << endl;
        top = top->next;
        delete temp;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty.\n";
            return;
        }

        Node* temp = top;

        cout << "Stack elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
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
