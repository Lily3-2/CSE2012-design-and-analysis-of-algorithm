//Maximum and minimum element in an array
#include <bits/stdc++.h>
using namespace std;

pair <int, int> max_min(int arr[], int i, int j) {
  pair <int, int> maxiMini;
  if(i==j) {
    maxiMini.first = arr[i];
    maxiMini.second = arr[i];
    return maxiMini;
    
  }
  else if(i==j-1) {
    if (arr[i]>arr[j]) {
      maxiMini.first = arr[i];
      maxiMini.second = arr[j];
    }
    else {
      maxiMini.first = arr[j];
      maxiMini.second = arr[i];
    }
    return maxiMini;
  }
  else{
    int mid = (i+j)/2;

    pair <int, int> left = max_min(arr, i, mid);
    pair <int, int> right = max_min(arr, mid+1, j);
//maximum value
    if(left.first>right.first) {
      maxiMini.first = left.first;
    }
    else{
      maxiMini.first = right.first;
    }
//minimum value
    if(left.second<right.second) {
      maxiMini.second = left.second;
    }
    else {
      maxiMini.second = right.second;
    }
  }
  return maxiMini;
}


int main() {
  int n;
   //enter the number of elements
  cout<<"Enter the number of elements: ";
  cin>>n;
  int arr[n];
  //enter the array elements
  cout<<"Enter the array elements: ";
  for (int i=0; i<n; i++) {
    cin>>arr[i];
  }
  //passing values to the function
  pair<int, int> result = max_min(arr, 0, n-1);
  cout<<"Maximum value in the array: "<<result.first<<endl;
  cout<<"Minimum value in the array: "<<result.second<<endl;


}