//Floyd Warshall Algorithm - All pair shortest path Algorithm
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // infinite distance
const int N = 1e2 + 5; // maximum number of vertices

int n; // number of vertices
int dist[N][N]; // dist[i][j] stores the shortest distance from i to j

void floydWarshall() {
    // initialize dist matrix with edge weights and INF for non-existing edges
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0; // distance to self is 0
            } else if (dist[i][j] == INF) {
                dist[i][j] = INF; // initialize with infinite distance for non-existing edges
            }
        }
    }

    // update dist matrix with intermediate vertices
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) { // check for path through k
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // update distance
                }
            }
        }
    }

    // print the shortest distances
    cout << "Shortest distances between all pairs of vertices:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    // read input
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }

    // find all pair shortest paths using Floyd Warshall algorithm
    floydWarshall();

    return 0;
}
