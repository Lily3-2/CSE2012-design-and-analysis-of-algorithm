#include <bits/stdc++.h>
using namespace std;
int TravellingSalesman(int **total_edges, int num_nodes)
{
  int source = 0;
  vector<int> nodes;
  for (int i = 0; i < num_nodes; i++)
  {
    if (i != source)
    {
      nodes.push_back(i);
    }
  }
  int n = nodes.size();
  int shortest_dist = INT_MAX;
  while (next_permutation(nodes.begin(), nodes.end()))
  {
    int dist_weight = 0;
    int j = source;
    for (int i = 0; i < n; i++)
    {
      dist_weight += total_edges[j][nodes[i]];
      j = nodes[i];
    }
    dist_weight += total_edges[j][source];
    shortest_dist = min(shortest_dist, dist_weight);
  }
  return shortest_dist;
}

int main()
{
  // Getting the number of nodes and number of edges as input
  cout << "Enter the number of nodes" << endl;
  int num_nodes, num_edges;
  cin >> num_nodes;
  cout << "Enter the number of edges" << endl;
  cin >> num_edges;
  // creating a multi-dimensional array
  int **total_edges = new int *[num_nodes];
  for (int i = 0; i < num_nodes; i++)
  {
    total_edges[i] = new int[num_nodes];
    for (int j = 0; j < num_nodes; j++)
    {
      total_edges[i][j] = 0;
    }
  }
  cout << "Enter first node, second node and weight between them" <<
  endl;
  // adjacent matrix filling mechanism
  for (int i = 0; i < num_edges; i++)
  {
    int first_node, second_node, weight;
    cin >> first_node >> second_node >> weight;
    total_edges[first_node][second_node] = weight;
    total_edges[second_node][first_node] = weight;
  }
  cout << "The adjacency matrix is" << endl;
  for (int i = 0; i < num_nodes; i++)
  {
    for (int j = 0; j < num_nodes; j++)
    {
      cout << total_edges[i][j] << " ";
    }
    cout << endl;
  }
  cout<<endl;
  cout << "The shortest path for travelling and coming back is "<< TravellingSalesman(total_edges, num_nodes) << endl;
  return 0;
}