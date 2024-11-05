#include<bits/stdc++.h>
using namespace std;

// Tabulation (Bottom-Up DP)
// Time: 𝑂(𝑁×𝑊)
// Space: 𝑂(𝑁×𝑊)

int knapsackDP1(int w, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (wt[i-1]<=w)
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i - 1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][w];
}

// Memoization (Top-Down DP)
// Time: 𝑂(𝑁×𝑊)
// Space: 𝑂(𝑁×𝑊)+O(N) for recursive stack space

int solve(int i,vector<int>& wt, vector<int>& val,int n,int w,vector<vector<int>>&dp){
    if(i==n) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
        
    int take=0,nottake=0;
    nottake=solve(i+1,wt,val,n,w,dp);
    if(wt[i]<=w) 
        take=val[i]+solve(i+1,wt,val,n,w-wt[i],dp);

    return dp[i][w]=max(take,nottake);
}

int knapsackDP2(int w, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    return solve(0,wt,val,n,w,dp);
}

int main() {
    int n=3,w=50; // Maximum capacity of knapsack
    vector<int>wt={10, 20, 30};
    vector<int>val={60, 100, 120};

    int ans1 = knapsackDP1(w,wt,val,n);
    int ans2 = knapsackDP2(w,wt,val,n);
    cout<<"\nMaximum value in knapsack1 = "<<ans1<<endl;
    cout<<"\nMaximum value in knapsack2 = "<<ans2<<endl;

    return 0;
}