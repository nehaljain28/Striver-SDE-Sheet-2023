//mem
int f(int ind,int s,vector<int>&price,vector<vector<int>>&dp){
	if(ind==0){
		return s*price[0];
		
	}
	if(dp[ind][s]!=-1)return dp[ind][s];
	int nottake=f(ind-1,s,price,dp);
	int take=INT_MIN;
	int rod=ind+1;
	if(rod<=s)take=price[ind]+f(ind,s-rod,price,dp);
	return dp[ind][s]=max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	return f(n-1,n,price,dp);
	// Write your code here.
}


//tab
 vector<vector<int>> dp(N,vector<int>(N+1,-1));
    
    for(int i=0; i<=N; i++){
        dp[0][i] = i*price[0];
    }
    
    for(int ind=1; ind<N; ind++){
        for(int length =0; length<=N; length++){
        
             int notTaken = 0 + dp[ind-1][length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + dp[ind][length-rodLength];
        
             dp[ind][length] = max(notTaken,taken);   
        }
    }
    
    return dp[N-1][N];

//space
vector<int> cur (N+1,0);
    
    for(int i=0; i<=N; i++){
        cur[i] = i*price[0];
    }
    
    for(int ind=1; ind<N; ind++){
        for(int length =0; length<=N; length++){
        
             int notTaken = 0 + cur[length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + cur[length-rodLength];
        
             cur[length] = max(notTaken,taken);   
        }
    }
    
    return cur[N];
