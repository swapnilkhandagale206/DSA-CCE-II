
#include <iostream>
using namespace std;

#define SIZE 10

class HashTable {
    int table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    void insert(int key) {
        int index = key % SIZE;

        for (int i = 0; i < SIZE; i++) {
            int pos = (index + i) % SIZE;

            if (table[pos] == -1) {
                table[pos] = key;
                cout << "Inserted successfully.\n";
                return;
            }
        }

        cout << "Hash table is full!\n";
    }

    void search(int key) {
        int index = key % SIZE;

        for (int i = 0; i < SIZE; i++) {
            int pos = (index + i) % SIZE;

            if (table[pos] == key) {
                cout << "Key found at index " << pos << endl;
                return;
            }

            if (table[pos] == -1)
                break;
        }

        cout << "Key not found.\n";
    }

    void display() {
        cout << "\nHash Table:\n";

        for (int i = 0; i < SIZE; i++)
            cout << i << " -> " << table[i] << endl;
    }
};

int main() {
    HashTable h;
    int choice, key;

    do {
        cout << "\n1. Insert\n2. Search\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                h.insert(key);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                h.search(key);
                break;

            case 3:
                h.display();
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
