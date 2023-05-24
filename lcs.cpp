//LCS(Least Common Subsequence)
#include<bits/stdc++.h>

using namespace std;

int lcs(string P[], string Q[], int a, int b)
{
    int LCScell[2][b+1];
    for(int i=0; i<=1; i++){
        LCScell[i][0]=0;
    }
    for(int j=0; j<=b; j++){
        LCScell[0][j]=0;
    }
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(P[i-1]==Q[j-1]){
                LCScell[i%2][j] = 1 + LCScell[(i-1)%2][j-1];
            }
            else{
                LCScell[i%2][j] = max(LCScell[(i-1)%2][j],LCScell[i%2][j-1]);
            }
        }
    }
    return LCScell[a%2][b];
}

int main()
{
    cout<<"Enter the length of first string: ";
    int a1;
    cin>>a1;
    cout<<"Enter the length of second string: ";
    int b1;
    cin>>b1;
    string s1[a1], s2[b1];
    cout<<"Enter first String: "<<endl;
    for(int i=0; i<a1; i++){
        cin>>s1[i];
    }
    cout<<"Enter second String: "<<endl;
    for(int j=0; j<b1; j++){
        cin>>s2[j];
    }
    int len = lcs(s1,s2,a1,b1);
    cout<<"Length of longest common subsequence: "<<len;
    return 0;
}