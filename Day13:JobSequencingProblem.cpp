#include <bits/stdc++.h> 

bool static compare(const vector<int>&a,const vector<int>&b){
    return a[1]>b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n=jobs.size();
    sort(jobs.begin(),jobs.end(),compare);
    int sum=0,k=0,maxi=0;
    for (int i = 0; i < n; i++) {
        maxi=max(maxi,jobs[i][0]);
    }
    vector<int>slot(maxi,-1);
    for(int i=0;i<n;i++){
        for(int j=jobs[i][0]-1;j>=0;j--){
            if(slot[j]==-1){
                slot[j]=jobs[i][1];
                sum+=jobs[i][1];
                break;
            }
        }
        
    }
    return sum;
}
