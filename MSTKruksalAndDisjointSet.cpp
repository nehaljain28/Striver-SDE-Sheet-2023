class DisjointSet{
    public:
    vector<int>parent,rank,size;
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
            rank[i]=0;
        }
    }
    int findUparent(int n){
        if(n==parent[n])return n;
        return parent[n]=findUparent(parent[n]);
    }
    void unionByRank(int u,int v){
        int upperu = findUparent(u);
        int upperv = findUparent(v);
        if(upperv==upperu)return;
        if(rank[upperu]<rank[upperv]){
            parent[upperu]=upperv;
        }
        else if(rank[upperv]<rank[upperu]){
            parent[upperv]=upperu;
        }
        else{
            parent[upperv]=upperu;
            rank[upperu]++;
        }
    }
    void unionBySize(int u,int v){
        int upperu = findUparent(u);
        int upperv = findUparent(v);
        if(upperv==upperu)return;
        if(size[upperu]<size[upperv]){
            parent[upperu]=upperv;
            size[upperv]+=size[upperu];
        }
        else{
            parent[upperv]=upperu;
            size[upperu]+=size[upperv];
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum=0;
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjnode=it[0];
                int wt=it[1];
                int node = i;
                edges.push_back({wt,{i,adjnode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        for(auto it:edges){
            int u=it.second.first;
            int v=it.second.second;
            int wt=it.first;
            if(ds.findUparent(u)!=ds.findUparent(v)){
                sum+=wt;
                ds.unionByRank(u,v);
                
            }
        }
        return sum;
    }
