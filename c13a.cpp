// Adjacency List
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MAX 10 // Maximum number of vertices

class Graph {
private:
    struct Node {
        int vertex;
        Node* next;
    };
    
    Node* adjList[MAX]; // Array of linked lists for adjacency list
    bool visited[MAX];  // Visited array for traversals
    int vertices;       // Number of vertices

public:
    Graph(int V) {
        vertices = V;
        for (int i = 0; i < V; i++) {
            adjList[i] = nullptr;
        }
    }

    // Function to add an edge in adjacency list
    void addEdge(int v1, int v2) {
        // Add v1 to v2’s list
        Node* newNode = new Node{v1, adjList[v2]};
        adjList[v2] = newNode;

        // Add v2 to v1’s list (since the graph is undirected)
        newNode = new Node{v2, adjList[v1]};
        adjList[v1] = newNode;
    }

    // Function to display adjacency list
    void displayList() {
        cout << "\nAdjacency List Representation:\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            Node* temp = adjList[i];
            while (temp) {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // Depth-First Search (DFS) using adjacency list (Iterative)
    void DFS(int start) {
        stack<int> stk;
        fill(visited, visited + vertices, false); // Reset visited array

        stk.push(start);
        visited[start] = true;
        cout << "DFS Traversal: ";

        while (!stk.empty()) {
            int v = stk.top();
            stk.pop();
            cout << v << " ";

            Node* temp = adjList[v];
            while (temp) {
                if (!visited[temp->vertex]) {
                    stk.push(temp->vertex);
                    visited[temp->vertex] = true;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    // Breadth-First Search (BFS) using adjacency list
    void BFS(int start) {
        queue<int> q;
        fill(visited, visited + vertices, false); // Reset visited array

        q.push(start);
        visited[start] = true;
        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            Node* temp = adjList[v];
            while (temp) {
                if (!visited[temp->vertex]) {
                    q.push(temp->vertex);
                    visited[temp->vertex] = true;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph graph(vertices);

    cout << "Enter the edges (v1 v2):\n";
    for (int i = 0; i < edges; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph.addEdge(v1, v2);
    }

    graph.displayList();

    int start;
    cout << "Enter the starting vertex for traversal: ";
    cin >> start;

    graph.DFS(start);        // DFS using stack (iterative)
    graph.BFS(start);        // BFS using queue

    return 0;
}

/*OUTPUT
C:\Users\HP\Desktop\DSAL>g++ ll.cpp

C:\Users\HP\Desktop\DSAL>a.exe
Enter the number of vertices: 5
Enter the number of edges: 6
Enter the edges (v1 v2):
0 1
0 2
1 3
2 3
1 4
3 4

Adjacency List Representation:
0: 2 1
1: 4 3 0
2: 3 0
3: 4 2 1
4: 3 1
Enter the starting vertex for traversal: 0
DFS Traversal: 0 1 3 4 2
BFS Traversal: 0 2 1 3 4

C:\Users\HP\Desktop\DSAL> */