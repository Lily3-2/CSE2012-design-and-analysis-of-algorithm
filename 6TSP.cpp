//TSP
#include <bits/stdc++.h>

using namespace std;
#define MAX 9999
int n=4; // Number of the nodes to visit
 //Next 2D distance array will give Minimum distance through all the position
int distan[10][10] = {                
                    {0, 16, 11, 6},
                    {8, 0, 13, 16},
                    {4, 7, 0, 9},
                    {5, 15, 2, 0}
};
int completed_visit = (1<<n) -1;
int DP[16][4];
int  TSP(int mark,int pos){
  if(mark==completed_visit){   // Initially checking whether all the nodes are visited or not
    return distan[pos][0];
  }
  if(DP[mark][pos]!=-1){
     return DP[mark][pos];
  }
  //Here we go to every other nodes to take the minimum ans
  int answer = MAX;
  //Visit rest of the unvisited cities and mark then find the minimum shortest path
  for(int city=0;city<n;city++){
    if((mark&(1<<city))==0){
      int newAnswer = distan[pos][city] + TSP( mark|(1<<city),city);
      answer = min(answer, newAnswer);
    }
  }
  return DP[mark][pos] = answer;
}
int main(){
    /* initialize the DP array */
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            DP[i][j] = -1;
        }
    }
  cout<<"Minimum Distance Travelled by you is "<<TSP(1,0);
return 0;
}