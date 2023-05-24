//To find the kth smallest and kth largest element in a list of elements without sorting the elements. 
#include <bits/stdc++.h>
using namespace std;

int kthlargestele(vector<int> &arrl, int k) {
  //base condition
  if(arrl.size() < k) {
    return -1;
  }

// Function to find the kth largest element in an array using min-heap
  priority_queue<int, vector<int>, greater<int>> pq(arrl.begin(), arrl.begin() + k);
  for( int i = k; i<arrl.size(); i++) {
      // if the current element is more than the root of the heap
    if(arrl[i] > pq.top() ){
      // replace root with the current element
      pq.pop();
      pq.push(arrl[i]);
    }
  }
    // return the root of min-heap
  return pq.top(); 
}

int kthsmalleseele(vector<int> &arrs, int k) {
  //base condition
  if(arrs.size() < k) {
    return -1;
  }
  //priority queue for creating max heap for kth smallest ele
  // insert the first `k` array elements into the heap
  priority_queue<int, vector<int>> pq(arrs.begin(), arrs.begin() + k) ;
  for(int i = k; i< arrs.size(); i++) {
      // if the current element is less than the root of the heap
    if(arrs[i] < pq.top() ) {
       // replace root with the current element
      pq.pop();
      pq.push(arrs[i]);
    }
  }
  // return the root of max-heap
  return pq.top();
}

int main() {
  int n;
  cin>>n;
  int k;
  cin>> k;
  vector <int> arr;
  for(int i=0; i<n; i++) {
    int a;
    cin>>a;
    arr.push_back(a);
  }
  cout<<kthsmalleseele(arr, k)<<endl;
  cout<<kthlargestele(arr, k);
  return 0;
}