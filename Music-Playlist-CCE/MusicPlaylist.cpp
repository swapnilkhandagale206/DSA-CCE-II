
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Node class representing a song
class Node {
public:
    string title;
    string artist;

    Node* prev;
    Node* next;

    Node(string t, string a) {
        title = t;
        artist = a;
        prev = nullptr;
        next = nullptr;
    }
};

// Music Playlist Manager
class MusicPlaylistManager {
private:
    Node* head;       // Points to the first song
    Node* current;    // Points to the currently selected song

public:
    MusicPlaylistManager() {
        head = nullptr;
        current = nullptr;
    }

    // Add a new song at the end
    void addSong() {
        string title, artist;

        cout << "Enter Song Title: ";
        getline(cin, title);

        cout << "Enter Artist Name: ";
        getline(cin, artist);

        if (title.empty() || artist.empty()) {
            cout << "Title and artist cannot be empty.\n";
            return;
        }

        Node* p = new Node(title, artist);
        // p points to the newly created node.

        if (head == nullptr) {
            head = p;
            current = p;
        } else {
            Node* q = head;
            // q traverses the playlist.

            while (q->next != nullptr) {
                q = q->next;
            }

            q->next = p;
            p->prev = q;
        }

        cout << "Song added successfully!\n";
    }

    // Delete a song by title
    void deleteSong() {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        string title;
        cout << "Enter song title to delete: ";
        getline(cin, title);

        Node* q = head;

        while (q != nullptr && q->title != title) {
            q = q->next;
        }

        if (q == nullptr) {
            cout << "Song not found!\n";
            return;
        }

        Node* p = q;
        // p points to the node being deleted.

        if (p == current) {
            current = (p->next != nullptr) ? p->next : p->prev;
        }

        if (p->prev != nullptr) {
            p->prev->next = p->next;
        } else {
            head = p->next;
        }

        if (p->next != nullptr) {
            p->next->prev = p->prev;
        }

        delete p;

        cout << "Song deleted successfully!\n";
    }

    // Display playlist in forward direction
    void displayPlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        Node* q = head;

        cout << "\n--- Music Playlist ---\n";

        while (q != nullptr) {
            cout << "Song: " << q->title
                 << " | Artist: " << q->artist << endl;

            q = q->next;
        }
    }

    // Display playlist in reverse direction
    void displayReverse() {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        Node* q = head;

        while (q->next != nullptr) {
            q = q->next;
        }

        cout << "\n--- Reverse Playlist ---\n";

        while (q != nullptr) {
            cout << "Song: " << q->title
                 << " | Artist: " << q->artist << endl;

            q = q->prev;
        }
    }

    // Play current song
    void playCurrentSong() {
        if (current == nullptr) {
            cout << "No song selected!\n";
            return;
        }

        cout << "\nNow Playing: " << current->title
             << " - " << current->artist << endl;
    }

    // Play next song
    void playNextSong() {
        if (current == nullptr) {
            cout << "No song available!\n";
            return;
        }

        if (current->next == nullptr) {
            cout << "You are already at the last song!\n";
            return;
        }

        current = current->next;
        playCurrentSong();
    }

    // Play previous song
    void playPreviousSong() {
        if (current == nullptr) {
            cout << "No song available!\n";
            return;
        }

        if (current->prev == nullptr) {
            cout << "You are already at the first song!\n";
            return;
        }

        current = current->prev;
        playCurrentSong();
    }

    // Play complete playlist
    void playCompletePlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        Node* q = head;

        cout << "\n--- Playing Complete Playlist ---\n";

        while (q != nullptr) {
            cout << "Playing: " << q->title
                 << " - " << q->artist << endl;

            q = q->next;
        }
    }

    // Repeat complete playlist
    void repeatAll() {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        int repetitions;

        cout << "Enter number of repetitions: ";

        if (!(cin >> repetitions)) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (repetitions <= 0) {
            cout << "Enter a positive number!\n";
            return;
        }

        for (int i = 1; i <= repetitions; i++) {
            Node* q = head;

            cout << "\nRepetition " << i << endl;

            while (q != nullptr) {
                cout << "Playing: " << q->title
                     << " - " << q->artist << endl;

                q = q->next;
            }
        }
    }

    // Show currently selected song
    void showCurrentSong() {
        playCurrentSong();
    }

    // Free allocated memory
    ~MusicPlaylistManager() {
        Node* q = head;

        while (q != nullptr) {
            Node* p = q;
            q = q->next;
            delete p;
        }
    }
};

// Main function
int main() {
    MusicPlaylistManager playlist;
    int choice;

    do {
        cout << "\n===== MUSIC PLAYLIST MANAGER =====\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Display Playlist in Reverse\n";
        cout << "5. Play Current Song\n";
        cout << "6. Play Next Song\n";
        cout << "7. Play Previous Song\n";
        cout << "8. Play Complete Playlist\n";
        cout << "9. Repeat All\n";
        cout << "10. Show Current Song\n";
        cout << "11. Exit\n";

        cout << "\nEnter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                playlist.addSong();
                break;

            case 2:
                playlist.deleteSong();
                break;

            case 3:
                playlist.displayPlaylist();
                break;

            case 4:
                playlist.displayReverse();
                break;

            case 5:
                playlist.playCurrentSong();
                break;

            case 6:
                playlist.playNextSong();
                break;

            case 7:
                playlist.playPreviousSong();
                break;

            case 8:
                playlist.playCompletePlaylist();
                break;

            case 9:
                playlist.repeatAll();
                break;

            case 10:
                playlist.showCurrentSong();
                break;

            case 11:
                cout << "Exiting Music Playlist Manager!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 11);

    return 0;
}
