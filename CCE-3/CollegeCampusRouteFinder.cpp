
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

class Graph {
private:
    static const int MAX = 10;
    char locations[MAX][30];
    int adj[MAX][MAX];
    int count;

    int findLocation(char name[]) {
        for (int i = 0; i < count; i++) {
            if (strcmp(locations[i], name) == 0)
                return i;
        }
        return -1;
    }

    void dfsUtil(int vertex, bool visited[]) {
        visited[vertex] = true;
        cout << locations[vertex] << " ";

        for (int i = 0; i < count; i++) {
            if (adj[vertex][i] > 0 && !visited[i]) {
                dfsUtil(i, visited);
            }
        }
    }

    void printPath(int parent[], int vertex) {
        if (parent[vertex] == -1) {
            cout << locations[vertex];
            return;
        }

        printPath(parent, parent[vertex]);
        cout << " -> " << locations[vertex];
    }

public:
    Graph() {
        count = 0;

        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addLocation() {
        if (count == MAX) {
            cout << "Maximum locations reached!\n";
            return;
        }

        char name[30];

        cout << "Enter location name (no spaces): ";
        cin >> name;

        if (findLocation(name) != -1) {
            cout << "Location already exists!\n";
            return;
        }

        strcpy(locations[count], name);
        count++;

        cout << "Location added successfully!\n";
    }

    void addRoad() {
        char source[30], destination[30];
        int distance;

        cout << "Enter starting location: ";
        cin >> source;

        cout << "Enter destination: ";
        cin >> destination;

        int u = findLocation(source);
        int v = findLocation(destination);

        if (u == -1 || v == -1) {
            cout << "Location not found!\n";
            return;
        }

        if (u == v) {
            cout << "Cannot connect a location to itself!\n";
            return;
        }

        cout << "Enter distance: ";
        cin >> distance;

        if (distance <= 0) {
            cout << "Distance must be positive!\n";
            return;
        }

        adj[u][v] = distance;
        adj[v][u] = distance;

        cout << "Road added successfully!\n";
    }

    void displayGraph() {
        cout << "\nCampus Network:\n";

        for (int i = 0; i < count; i++) {
            cout << locations[i] << " -> ";

            for (int j = 0; j < count; j++) {
                if (adj[i][j] > 0) {
                    cout << locations[j]
                         << "(" << adj[i][j] << ") ";
                }
            }

            cout << endl;
        }
    }

    void shortestPath() {
        char source[30], destination[30];

        cout << "Enter starting location: ";
        cin >> source;

        cout << "Enter destination: ";
        cin >> destination;

        int start = findLocation(source);
        int end = findLocation(destination);

        if (start == -1 || end == -1) {
            cout << "Location not found!\n";
            return;
        }

        int dist[MAX], parent[MAX];
        bool visited[MAX];

        for (int i = 0; i < count; i++) {
            dist[i] = INT_MAX;
            parent[i] = -1;
            visited[i] = false;
        }

        dist[start] = 0;

        for (int i = 0; i < count; i++) {
            int u = -1;
            int minimum = INT_MAX;

            for (int j = 0; j < count; j++) {
                if (!visited[j] && dist[j] < minimum) {
                    minimum = dist[j];
                    u = j;
                }
            }

            if (u == -1)
                break;

            visited[u] = true;

            for (int v = 0; v < count; v++) {
                if (adj[u][v] > 0 && !visited[v]
                    && dist[u] != INT_MAX
                    && dist[u] + adj[u][v] < dist[v]) {

                    dist[v] = dist[u] + adj[u][v];
                    parent[v] = u;
                }
            }
        }

        if (dist[end] == INT_MAX) {
            cout << "No route available!\n";
        } else {
            cout << "\nShortest Route: ";
            printPath(parent, end);

            cout << "\nTotal Distance: "
                 << dist[end] << " units\n";
        }
    }

    void bfs() {
        char name[30];

        cout << "Enter starting location: ";
        cin >> name;

        int start = findLocation(name);

        if (start == -1) {
            cout << "Location not found!\n";
            return;
        }

        bool visited[MAX] = {false};
        int queue[MAX];
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        cout << "BFS Traversal: ";

        while (front < rear) {
            int u = queue[front++];
            cout << locations[u] << " ";

            for (int v = 0; v < count; v++) {
                if (adj[u][v] > 0 && !visited[v]) {
                    visited[v] = true;
                    queue[rear++] = v;
                }
            }
        }

        cout << endl;
    }

    void dfs() {
        char name[30];

        cout << "Enter starting location: ";
        cin >> name;

        int start = findLocation(name);

        if (start == -1) {
            cout << "Location not found!\n";
            return;
        }

        bool visited[MAX] = {false};

        cout << "DFS Traversal: ";
        dfsUtil(start, visited);

        cout << endl;
    }
};

int main() {
    Graph campus;
    int choice;

    do {
        cout << "\n===== COLLEGE CAMPUS ROUTE FINDER =====\n";
        cout << "1. Add Campus Location\n";
        cout << "2. Add Road\n";
        cout << "3. Display Campus Network\n";
        cout << "4. Find Shortest Route\n";
        cout << "5. BFS Traversal\n";
        cout << "6. DFS Traversal\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                campus.addLocation();
                break;

            case 2:
                campus.addRoad();
                break;

            case 3:
                campus.displayGraph();
                break;

            case 4:
                campus.shortestPath();
                break;

            case 5:
                campus.bfs();
                break;

            case 6:
                campus.dfs();
                break;

            case 7:
                cout << "Thank you for using Campus Route Finder!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
