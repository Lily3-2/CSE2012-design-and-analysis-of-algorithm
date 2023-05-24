//Ford Fulkerson - Maximum Flows Algorithm
#include <bits/stdc++.h>
using namespace std;

#define V 100

bool bfs(int rGraph[V][V], int s, int t, int parent[], int n) {
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}

int fordFulkerson(int graph[V][V], int s, int t, int n) {
    int u, v;
    int rGraph[V][V];
    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            rGraph[u][v] = graph[u][v];
    int parent[V];
    int max_flow = 0;
    while (bfs(rGraph, s, t, parent, n)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    int n, s, t;
    int graph[V][V];
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    cout << "Enter the source vertex: ";
    cin >> s;
    cout << "Enter the sink vertex: ";
    cin >> t;
    cout << "Max Flow: " << fordFulkerson(graph, s, t, n) << endl;
    return 0;
}
