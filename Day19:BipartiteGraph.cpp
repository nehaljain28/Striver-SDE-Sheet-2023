//bfs
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>col(v,-1);
        queue<int>q;
        for(int i=0;i<v;i++){
            if(col[i]==-1){
                q.push(i);
                col[i]=0;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int i:graph[node]){
                        if(col[i]==-1){
                            col[i]=!col[node];
                            q.push(i);
                            
                        }
                        else if(col[i]==col[node])return false;
                            
                        }
                    }
            }
                
        }
        
            return true;

        }
    
};



//dfs
class Solution {
public:
    bool dfs(int node,int c,vector<int>&col,vector<vector<int>>& graph){
        col[node]=c;
        for(int i:graph[node]){
            if(col[i]==-1){
                if(dfs(i,!c,col,graph)==false)return false;
            }
            else{
                if(col[i]==c)return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>col(v,-1);
       
        for(int i=0;i<v;i++){
            if(col[i]==-1){
                if(dfs(i,0,col,graph)==false)return false;
            }
                
        }
        
            return true;

        }
    
};
