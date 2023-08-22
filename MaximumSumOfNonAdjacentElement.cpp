memoization

#include <bits/stdc++.h> 
int ans(int ind,vector<int>&nums,vector<int>&dp){
    if(ind==0)return nums[ind];
    if(ind<0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int pick = nums[ind]+ans(ind-2,nums,dp);
    int notpick = ans(ind-1,nums,dp);
    return dp[ind]=max(pick,notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n,-1);
    return ans(n-1,nums,dp);
}

//space optimization
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    int prev2=0,prev=nums[0];
    for(int i=1;i<n;i++){
        int take = nums[i];
        if(i>1)take+=prev2;
        int nottake = prev;
        prev2=prev;
        prev=max(take,nottake);
    }
    return prev;
}
