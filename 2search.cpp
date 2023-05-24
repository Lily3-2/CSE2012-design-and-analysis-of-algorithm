//To search for an element using recursive linear or binary search based on the option given by the user. The number of comparisons taken to find the element also must be found. 

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr,int s,int e,int ele,int &count) {
  int mid = (s+e)/2;
  count++;
  if(ele==arr[mid]){
    return mid;
  }
  else if(ele>arr[mid]){
    return binarySearch(arr, mid+1 ,e,ele,count);
  }
  else{
    return binarySearch(arr,s,mid-1,ele,count);
  }
  return -1;
}
int linearSearch(vector<int> arr,int i,int ele,int &count) {
  count++;
  if(arr[i]==ele){
    return i;
  }
  else
    return linearSearch(arr,i+1,ele,count);
}

int main() {
    vector<int> arr;
    int n;
    char opt;
    int ele;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++){
      int x;
      cin>>x;
      arr.push_back(x);
    }
    cout<<"Enter the searching method B for binary and L for linear"<<endl;
    cin>>opt;
    cout<<"Enter the element to be searched"<<endl;
    cin>>ele;
    int count=0,p;
    if(opt=='B') {
      p=binarySearch(arr,0,n-1,ele,count);
    }
    else if(opt=='L'){
      p=linearSearch(arr,0,ele,count);
    }
    else{
      cout<<"Enter a valid searching method";
    }
    cout<<"The element "<<ele<<" was found at position "<<p<<" in the given array in "<<count<<" comparisons"<<endl;
}