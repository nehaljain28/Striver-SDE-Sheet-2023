int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(V,0);
        pq.push({0,0});
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(!vis[node]){
                vis[node]=1;
                sum+=wt;
                //can add mst here
                for(auto it:adj[node]){
                    if(!vis[it[0]]){
                        pq.push({it[1],it[0]});
                    }
                }
            }
        }
        return sum;
        // code here
    }
