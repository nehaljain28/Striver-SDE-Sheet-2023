#include<bits/stdc++.h>

bool detect(vector<int>adj[],vector<int>&vis,vector<int>&path,int node)

{

  vis[node]=1;

  path[node]=1;

  for(auto it:adj[node])

  {

    if(!vis[it])

    {

      if(detect(adj,vis,path,it)==true)

      return true;

    }

    else if(path[it])

    {

      return true;

    }

 

  }

  path[node]=0;

  return false;

}

 

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

  // Write your code here.

     vector<int>adj[n+1];

     vector<int>vis(n+1,0);

     vector<int>path(n+1,0);

     int a=true;

     int b=false;

     for(int i =0;i<edges.size();i++)

     {

        int u=edges[i].first;

 

    int v=edges[i].second;

 

    adj[u].push_back(v);

 

     }

     for(int i =1;i<n+1;i++)

     {

       if(!vis[i])

       {

         if(detect(adj,vis,path,i))

         return 1;

 

       }

     }

return 0;

 

}
