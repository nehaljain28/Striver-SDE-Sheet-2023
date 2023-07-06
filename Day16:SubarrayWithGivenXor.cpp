int Solution::solve(vector<int> &A, int B) {
    map<int,int>mp;
    int xr=0,ct=0;
    mp[0]++;
    for(int i=0;i<A.size();i++){
        xr^=A[i];
        if(mp.find(xr^B)!=mp.end()){
            ct+=mp[xr^B];
        }
        mp[xr]++;
    }
    return ct;
}
