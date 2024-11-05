#include<bits/stdc++.h>
using namespace std;

int knapSack1(int w, vector<int>&wt,vector<int>&val, int n){
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(wt[i-1]<=w)
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][w];
}

int solve(int i,int w, vector<int>&wt, vector<int>&val, int n,vector<vector<int>>&dp){
    if(i==n) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
    
    int take=0,nottake=0;
    nottake=solve(i+1,w,wt,val,n,dp);
    if(wt[i]<=w) take=val[i]+solve(i+1,w-wt[i],wt,val,n,dp);

    return dp[i][w]=max(take,nottake);
}

int knapSack2(int w, vector<int>&wt,vector<int>&val, int n){
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    return solve(0,w,wt,val,n,dp);
}

int main(){
    int n=3,w=50;
    vector<int>wt={10,20,30};
    vector<int>val={60,100,120};

    int ans1=knapSack1(w,wt,val,n);
    int ans2=knapSack2(w,wt,val,n);
    cout<<"\nMax value in knapsack1: "<<ans1<<endl;
    cout<<"\nMax value in knapsack2: "<<ans2<<endl;

    return 0;
}