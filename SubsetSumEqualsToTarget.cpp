//mem
#include <bits/stdc++.h> 
bool f(int ind,int k,vector<int>&arr,vector<vector<int>>&dp){
    if(k==0)return true;
    if(ind==0)return arr[0]==k;
    if(dp[ind][k]!=-1)return dp[ind][k];
    bool nottake=f(ind-1,k,arr,dp);
    bool take=false;
    if(arr[ind]<=k)take=f(ind-1,k-arr[ind],arr,dp);
    return dp[ind][k]=nottake||take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}

//tab
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    if(arr[0]<=k)dp[0][arr[0]]=true;
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool nottake=dp[i-1][j];
            bool take=false;
            if(arr[i]<=j)take=dp[i-1][j-arr[i]];
            dp[i][j]=take||nottake;
        }
    }
    return dp[n-1][k];
}

//space
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<int>dp(k+1,0);
    dp[0]=1;
    if(arr[0]<=k)dp[arr[0]]=true;
    
    for(int i=1;i<n;i++){
        vector<int>temp(k+1,0);
        for(int j=0;j<=k;j++){
            if(j==0)dp[j]=true;
            bool nottake=dp[j];
            bool take=false;
            if(arr[i]<=j)take=dp[j-arr[i]];
            temp[j]=take||nottake;
        }
        dp=temp;
    }
    return dp[k];
}
