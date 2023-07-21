#include<bits/stdc++.h>
void dfs(int i, vector<int> &vis, vector<int> adj[], stack<int> &st){
    vis[i] = 1;
    for(auto it: adj[i]){
        if(!vis[it]){
            dfs(it, vis, adj,st);
        }
    }

    st.push(i);
}

void dfs2(int i,vector<int> &vis, vector<int> adjrev[], vector<int> &topush ){
    vis[i] = 1;
    for(auto it: adjrev[i]){
        if(!vis[it]){
            
            dfs2(it, vis, adjrev,topush);
        }
    }
  topush.push_back(i);
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj[n];
    for(auto it: edges){
        {
            adj[it[0]].push_back(it[1]);        
        }
    }

    stack<int>st;
    vector<int> vis(n,0);

    for(int i = 0 ; i <  n; i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }

    vector<int> adjrev[n];

    for(int i = 0; i < n; i++){
        vis[i] = 0;
        for(auto it: adj[i]){
            adjrev[it].push_back(i);
        }
    }


    vector<vector<int>> ans;
    while(!st.empty()){
        int a = st.top();
        st.pop();
        vector<int> topush;
        if(!vis[a]){
            dfs2(a,vis,adjrev,topush);
        }
        
        ans.push_back(topush);

    }
    
    return ans;

}
