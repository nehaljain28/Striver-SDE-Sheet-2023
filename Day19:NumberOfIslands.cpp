//bfs
class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        int h[4]={-1,0,+1,0};
        int v[4]={0,+1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
                for(int i=0;i<4;i++){
                    int newr=r+h[i];
                    int newc=c+v[i];
                    if(newr>=0&&newr<n&&newc>=0&&newc<m&&grid[newr][newc]=='1'&&!vis[newr][newc]){
                        vis[newr][newc]=1;
                        q.push({newr,newc});
                    }
                }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    ans++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return ans;
    }
};

//dfs
class Solution {
public:
    void DFS(vector<vector<char>>&grid, int m, int n, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0')return;
        if(grid[i][j]=='1'){
            grid[i][j]='0';
            DFS(grid,m,n,i-1,j);
            DFS(grid,m,n,i+1,j);
            DFS(grid,m,n,i,j+1);
            DFS(grid,m,n,i,j-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    DFS(grid,m,n,i,j);
                }
            }
        }
        return cnt;
    }
};
