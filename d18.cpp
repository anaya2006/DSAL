#include <iostream>
#include <climits> // For INT_MAX
using namespace std;
#define SIZE 10

class OBST {
    int p[SIZE]; // Probabilities of finding a key
    int q[SIZE]; // Probabilities of missing a key
    int a[SIZE]; // Keys
    int w[SIZE][SIZE]; // Weight matrix
    int c[SIZE][SIZE]; // Cost matrix
    int r[SIZE][SIZE]; // Root matrix
    int n; // Number of keys

public:
    // Function to accept input
    void get_data() {
        cout << "\nOptimal Binary Search Tree\n";
        cout << "\nEnter the number of nodes (max " << SIZE - 1 << "): ";
        cin >> n;
        
        if (n >= SIZE) {
            cout << "Error: Number of nodes exceeds allowed size!" << endl;
            return;
        }

        cout << "\nEnter the keys:\n";
        for (int i = 1; i <= n; i++) {
            cout << "a[" << i << "]: ";
            cin >> a[i];
        }

        cout << "\nEnter probabilities of successful search:\n";
        for (int i = 1; i <= n; i++) {
            cout << "p[" << i << "]: ";
            cin >> p[i];
        }

        cout << "\nEnter probabilities of unsuccessful search:\n";
        for (int i = 0; i <= n; i++) {
            cout << "q[" << i << "]: ";
            cin >> q[i];
        }
    }

    // Function to compute the optimal root index
    int Min_Value(int i, int j) {
        int min_cost = INT_MAX, k = 0;
        for (int m = r[i][j - 1]; m <= r[i + 1][j]; m++) {
            int cost = c[i][m - 1] + c[m][j];
            if (cost < min_cost) {
                min_cost = cost;
                k = m;
            }
        }
        return k;
    }

    // Function to build the OBST
    void build_OBST() {
        for (int i = 0; i <= n; i++) {
            w[i][i] = q[i];
            c[i][i] = 0;
            r[i][i] = 0;
        }

        for (int i = 0; i < n; i++) {
            w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
            c[i][i + 1] = w[i][i + 1];
            r[i][i + 1] = i + 1;
        }

        for (int m = 2; m <= n; m++) {
            for (int i = 0; i <= n - m; i++) {
                int j = i + m;
                w[i][j] = w[i][j - 1] + p[j] + q[j];
                int k = Min_Value(i, j);
                c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
                r[i][j] = k;
            }
        }
    }

    // Function to build and display the OBST structure
    void build_tree() {
        cout << "\nThe Optimal Binary Search Tree for the Given Nodes is:\n";
        cout << "\nRoot of OBST: " << r[0][n];
        cout << "\nCost of OBST: " << c[0][n];
        cout << "\n\n\tNODE\tLEFT CHILD\tRIGHT CHILD\n";

        int queue[20], front = -1, rear = -1;
        queue[++rear] = 0;
        queue[++rear] = n;

        while (front != rear) {
            int i = queue[++front];
            int j = queue[++front];
            int k = r[i][j];

            cout << "\n\t" << k;
            if (r[i][k - 1] != 0) {
                cout << "\t\t" << r[i][k - 1];
                queue[++rear] = i;
                queue[++rear] = k - 1;
            } else {
                cout << "\t\t-";
            }

            if (r[k][j] != 0) {
                cout << "\t" << r[k][j];
                queue[++rear] = k;
                queue[++rear] = j;
            } else {
                cout << "\t-";
            }
        }
        cout << "\n";
    }
};

int main() {
    OBST obj;
    obj.get_data();
    obj.build_OBST();
    obj.build_tree();
    return 0;
}
