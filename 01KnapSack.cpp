//mem
#include <bits/stdc++.h>
int f(int ind,vector<int> weight, vector<int> value, int n, int maxWeight,vector<vector<int>>&dp){
	if(ind==0){
		if(weight[0]<=maxWeight)return value[0];
		else return 0;
	}
	if(dp[ind][maxWeight]!=-1)return dp[ind][maxWeight];
	int nottake=f(ind-1,weight,value,n,maxWeight,dp);
	int take=0;
	if(weight[ind]<=maxWeight)take=value[ind]+f(ind-1,weight,value,n,maxWeight-weight[ind],dp);
	return dp[ind][maxWeight]=max(take,nottake);
	
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return f(n-1,weight,value,n,maxWeight,dp);
	// Write your code here
}

//tab
#include <bits/stdc++.h>

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
	for(int i=weight[0];i<maxWeight+1;i++){
		dp[0][i]=value[0];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<maxWeight+1;j++){
			int nottake=dp[i-1][j];
			int take=INT_MIN;
			if(weight[i]<=j)take=value[i]+dp[i-1][j-weight[i]];
			dp[i][j]=max(take,nottake);
		}
	}
	return dp[n-1][maxWeight];
	// Write your code here
}

//space
vector<int> prev(W+1,0);
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        prev[i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=W; cap>=0; cap--){
            
            int notTaken = 0 + prev[cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];
                
            prev[cap] = max(notTaken, taken);
        }
    }
    
    return prev[W];
