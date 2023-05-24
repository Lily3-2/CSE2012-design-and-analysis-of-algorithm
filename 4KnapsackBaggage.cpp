//Fractional Knapsack Problem for an airport permitted baggage scenario.

#include <bits/stdc++.h>
using namespace std;

void swap_ratio(float &a,float &b){
  float temp=a;
  a=b;
  b=temp;
}

void swap_weight(int &a,int &b){
  int temp=a;
  a=b;
  b=temp;
}

int main() {
  int n;
  cout<<"Enter the number of items in the lauggage"<<endl;
  cin>>n;
  vector<int> weight;
  vector<int> cost;
  vector<float> ratio;
  cout<<"Enter the weight and cost of all the items"<<endl;
  for(int i=0;i<n;i++){
    int w,c;
    cin>>w;
    cin>>c;
    weight.push_back(w);
    cost.push_back(c);
  }

  int limit;
  cout<<"Enter the max weight allowed in the lagguage"<<endl;
  cin>>limit;
  //finding cost/wt ratio
  for(int i=0;i<n;i++){
    float x=(float)cost[i]/weight[i];
    ratio.push_back(x);
  }
  //sorting in descending order
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
      if(ratio[j]<ratio[j+1]) {
        swap_ratio(ratio[j],ratio[j+1]);
        swap_weight(weight[j],weight[j+1]);
      }
    }
  }
  
  int recovery=0,i=0;
  while(limit>0){
    if(weight[i]<=limit){
      recovery += round(ratio[i]*weight[i]);
      limit -= weight[i];
    }
    else{
      recovery +=round (limit*ratio[i]);
      limit=0;
    }
    i++;
  }
  cout<<"The max possible recovery can be items of worth: "<<recovery<<endl;
}