//To find the kth smallest and kth largest element in a list of elements without sorting the elements. 
#include <bits/stdc++.h>
using namespace std;

int kthlargestele(vector<int> &arrl, int k) {
  //base condition
  if(arrl.size() < k) {
    return -1;
  }
//using min heap for largest kth ele
  priority_queue<int, vector<int>, greater<int>> pq(arrl.begin(), arrl.begin() + k);
  for( int i = k; i<arrl.size(); i++) {
    if(arrl[i] > pq.top() ){
      pq.pop();
      pq.push(arrl[i]);
    }
  }
  return pq.top(); 
}

int kthsmalleseele(vector<int> &arrs, int k) {
  //base condition
  if(arrs.size() < k) {
    return -1;
  }
  //priority queue for creating max heap for kth smallest ele
  priority_queue<int, vector<int>> pq(arrs.begin(), arrs.begin() + k) ;
  for(int i = k; i< arrs.size(); i++) {
    if(arrs[i] < pq.top() ) {
      pq.pop();
      pq.push(arrs[i]);
    }
  }
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