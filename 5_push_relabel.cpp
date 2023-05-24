// Push Relabel Algorithm - Maximum Flows Algorithm
#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;
// Define the number of vertices as a global variable
int num_vertices;
// Define the capacity, flow, height, excess, and seen arrays as global variables
vector<vector<int>> capacity, flow;
vector<int> height, excess, seen;
// Define a queue to keep track of excess vertices
queue<int> excess_vertices;

// Define the push function, which pushes flow from vertex u to vertex v
void push_flow(int u, int v) {
    int d = min(excess[u], capacity[u][v] - flow[u][v]);
     // Update the flow on the edge (u, v)
    flow[u][v] += d;
    flow[v][u] -= d;
    // Update the excess flow at vertex u and v
    excess[u] -= d;
    excess[v] += d;
     // If v becomes an excess vertex, add it to the queue
    if (d && excess[v] == d)
        excess_vertices.push(v);
}

// Define the relabel function, which sets the height of vertex u to the minimum height of its neighbours
void relabel_height(int u) {
  // Initialize d to a large value
    int d = INF;
    // Find the minimum height of u's neighbours that still have available capacity
    for (int i = 0; i < num_vertices; i++) {
        if (capacity[u][i] - flow[u][i] > 0)
            d = min(d, height[i]);
    }
     // If a neighbour with available capacity is found, set the height of u to 1 + that neighbour's height
    if (d < INF)
        height[u] = d + 1;
}
// Define the discharge function, which pushes excess flow out of a vertex until it has no excess flow
void discharge_vertex(int u) {
  // While there is still excess flow at vertex u
    while (excess[u] > 0) {
        if (seen[u] < num_vertices) {
            int v = seen[u];
            if (capacity[u][v] - flow[u][v] > 0 && height[u] > height[v])
                push_flow(u, v);
            else
                seen[u]++;
        } else {
            relabel_height(u);
            seen[u] = 0;
        }
    }
}

// Define the max_flow function, which calculates the maximum flow from a source vertex s to a sink vertex t
int max_flow(int source, int sink) {
   // Initialize height, flow, excess, and seen arrays
    height.assign(num_vertices, 0);
    height[source] = num_vertices;
    flow.assign(num_vertices, vector<int>(num_vertices, 0));
    excess.assign(num_vertices, 0);
    excess[source] = INF;
    for (int i = 0; i < num_vertices; i++) {
        if (i != source)
            push_flow(source, i);
    }
    seen.assign(num_vertices, 0);
     // Find excess vertices and discharge them
    while (!excess_vertices.empty()) {
        int u = excess_vertices.front();
        excess_vertices.pop();
        if (u != source && u != sink)
            discharge_vertex(u);
    }
    int max_flow = 0;
    for (int i = 0; i < num_vertices; i++)
        max_flow += flow[i][sink];
    return max_flow;
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> num_vertices;
    capacity.resize(num_vertices, vector<int>(num_vertices));
    cout << "Enter the capacity matrix:\n";
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            cin >> capacity[i][j];
        }
    }
    int source, sink;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the sink vertex: ";
    cin >> sink;
    cout << "Maximum flow: " << max_flow(source, sink) << endl;
    return 0;
}
