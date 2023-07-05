bool safe(int i,int node,vector<int>&color,vector<vector<int>>&mat,int n){
    for(int j=0;j<n;j++){
        if(j!=node&&mat[j][node]==1&&color[j]==i)return false;
    }
    return true;
}
bool solve(int node,vector<vector<int>>&mat,int m,int n,vector<int>&color){
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(safe(i,node,color,mat,n)){
            color[node]=i;
            if(solve(node+1,mat,m,n,color))return true;
            else color[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    vector<int> color(mat.size(),0);
    if (solve(0,mat,m,mat.size(),color))return "YES";
    return "NO";
}
