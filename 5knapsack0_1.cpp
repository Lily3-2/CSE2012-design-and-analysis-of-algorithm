//Dynamic Programming - 0/1 Knapsack


#include <bits/stdc++.h>
using namespace std;

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, vector<int> weight, vector<int> value, int n) {
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
                K[i][w] = max(value[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int W = 5;    // Maximum weight of knapsack
    int n;
    cout<<"Enter the number of weights: ";
    cin>>n;
    cout<<"Enter the weights with their values: "<<endl;
    vector<int> weight;
    vector<int> value;
    for(int i=0; i<n; i++) {
      int w;
      int v;
      cin>>w;
      cin>>v;
      weight.push_back(w);
      value.push_back(v);
    }

    cout << "Value achieved: "<< knapsack(W, weight, value, n) << endl;

    return 0;
}
