//mem
int ans(int day,int act,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=act){
                maxi=max(maxi,points[0][i]);
            }
        }
        return dp[day][act]=maxi;
    }
    if(dp[day][act]!=-1)return dp[day][act];
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=act){
            int point = points[day][i]+ans(day-1,i,points,dp);
            maxi=max(point,maxi);
        }
    }
    return dp[day][act]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return ans(n-1,3,points,dp);
    // Write your code here.
}

//tab

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][2],max(points[0][0],points[0][1]));
    for(int day=1;day<n;day++){
        for(int act=0;act<4;act++){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(i!=act){
                    int point = points[day][i] + dp[day-1][i];
                    maxi=max(maxi,point);
                }
            }
            dp[day][act]=maxi;
        }
    }
    return dp[n-1][3];
    // Write your code here.
}

//space

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int>dp(4,-1);
    dp[0]=max(points[0][1],points[0][2]);
    dp[1]=max(points[0][0],points[0][2]);
    dp[2]=max(points[0][0],points[0][1]);
    dp[3]=max(points[0][2],max(points[0][0],points[0][1]));
    for(int day=1;day<n;day++){
        vector<int>temp(4,-1);
        for(int act=0;act<4;act++){
            
            for(int i=0;i<3;i++){
                if(i!=act){
                    int point = points[day][i] + dp[i];
                    temp[act]=max(temp[act],point);
                }
            }
            
        }
        dp=temp;
    }
    return dp[3];
    // Write your code here.
}
