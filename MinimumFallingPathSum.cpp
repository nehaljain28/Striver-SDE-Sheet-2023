//mem
class Solution {
public:
    int f(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(j<0||j>=matrix[0].size())return 1e9;
        if(i==0)return matrix[0][j];
        
        if(dp[i][j]!=-1)return dp[i][j];
        int up=matrix[i][j]+f(i-1,j,matrix,dp);
        int ld=matrix[i][j]+f(i-1,j-1,matrix,dp);
        int rd=matrix[i][j]+f(i-1,j+1,matrix,dp);
        return dp[i][j]=min(up,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=1e9;
        for(int i=0;i<m;i++){
            ans=min(ans,f(n-1,i,matrix,dp));
        }
        return ans;
    }
};

//tab
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
            int ans=1e9;
            for(int j=0;j<m;j++){
                dp[0][j]=matrix[0][j];
            }
            for(int i=1;i<n;i++){
                for(int j=0;j<m;j++){
                   
                        int up = matrix[i][j] + dp[i-1][j];
            
                        int ld= matrix[i][j];
                        if(j-1>=0) ld += dp[i-1][j-1];
                        else ld += 1e9;
                        
                        int rd = matrix[i][j];
                        if(j+1<m) rd += dp[i-1][j+1];
                        else rd += 1e9;
                        dp[i][j]=min(up,min(ld,rd));
                    
                }
                
            }
            for(int i=0;i<m;i++){
                ans=min(ans,dp[n-1][i]);
            }
            
        
        return ans;
    }
    
};

//space
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>dp(m,-1);
            int ans=1e9;
            for(int j=0;j<m;j++){
                dp[j]=matrix[0][j];
            }
            for(int i=1;i<n;i++){
                vector<int>temp(m,-1);
                for(int j=0;j<m;j++){
                   
                        int up = matrix[i][j] + dp[j];
            
                        int ld= matrix[i][j];
                        if(j-1>=0) ld += dp[j-1];
                        else ld += 1e9;
                        
                        int rd = matrix[i][j];
                        if(j+1<m) rd += dp[j+1];
                        else rd += 1e9;
                        temp[j]=min(up,min(ld,rd));
                    
                }
                dp=temp;
                
            }
            for(int i=0;i<m;i++){
                ans=min(ans,dp[i]);
            }
            
        
        return ans;
    }
    
};
