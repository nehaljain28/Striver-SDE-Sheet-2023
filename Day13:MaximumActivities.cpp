#include <bits/stdc++.h>
class meeting{
    public:
    int st;
    int end;
};
bool static compare(meeting m1,meeting m2){
    if(m1.end<m2.end)return true;
    else if(m1.end>m2.end)return false;
    else if(m1.st<m2.st)return true;
    return false;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
   
    int n = start.size();
    meeting meet[n];
    for(int i=0;i<n;i++){
        meet[i].st=start[i];
        meet[i].end=finish[i];
    }
    sort(meet,meet+n,compare);
    int ans=1;
    int limit = meet[0].end;
    for(int i=1;i<n;i++){
        if(meet[i].st>=limit){
            ans++;
            limit=meet[i].end;
        }
    }
    return ans;
}
