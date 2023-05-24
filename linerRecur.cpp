#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int i, int k) {

  if(arr[i] == k){
    return i;
  }
  else{
    return linearSearch(arr, i+1, k);
  }
  return -1;
}

int main() {
  vector<int> arr;
  int n;
  cin>>n;
  for (int i=0; i<n; i++) {
    int a;
    cin>>a;
    arr.push_back(a);
  }
  cout<<linearSearch(arr, 0, 5)<< endl;
  
  return 0;
}