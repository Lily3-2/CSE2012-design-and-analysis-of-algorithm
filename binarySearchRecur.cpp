#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int s, int e, int k) {
  int mid = s + (e-s)/2;
    if(arr[mid] == k) {
      return mid;
    }

    else if(arr[mid]>k) {
      return binarySearch(arr, s, mid-1, k);
    }
    else{
      return binarySearch(arr, mid+1, e, k);
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
  cout<<binarySearch(arr, 0, n-1, 5)<< endl;
  
  return 0;
}