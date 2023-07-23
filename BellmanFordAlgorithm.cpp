vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V-1;i++){
            for(auto j:edges){
                int u=j[0];
                int v=j[1];
                int wt=j[2];
                if(dist[u]!=1e8&&dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        for(auto j:edges){
                int u=j[0];
                int v=j[1];
                int wt=j[2];
                if(dist[u]!=1e8&&dist[u]+wt<dist[v]){
                    return {-1};
                }
        }
        return dist;
    }
