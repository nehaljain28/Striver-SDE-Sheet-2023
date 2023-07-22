//pq
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int>dist(V,1e9);
        pq.push({0,S});
        dist[S]=0;
        while(!pq.empty()){
            int dis=pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto i:adj[node]){
                int curdist=dis+i[1];
                int n = i[0];
                if(curdist<dist[n]){
                    dist[n]=curdist;
                    pq.push({curdist,n});
                }
            }
        }
        return dist;
        // Code here
    }

//set

//set
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int>dist(V,1e9);
        st.insert({0,S});
        dist[S]=0;
        while(!st.empty()){
            auto it = *(st.begin());
            int dis=it.first;
            int node = it.second;
            st.erase(it);
            for(auto i:adj[node]){
                int curdist=dis+i[1];
                int n = i[0];
                if(curdist<dist[n]){
                    
                    if(dist[n]!=1e9)st.erase({dist[n],n});
                    dist[n]=curdist;
                    st.insert({curdist,n});
                }
            }
        }
        return dist;
        // Code here
    }



//queue



//print
 vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        // Create a priority queue for storing the nodes along with distances 
        // in the form of a pair { dist, node }.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        // Create a dist array for storing the updated distances and a parent array
        //for storing the nodes from where the current nodes represented by indices of
        // the parent array came from.
        vector<int> dist(n + 1, 1e9), parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        dist[1] = 0;

        // Push the source node to the queue.
        pq.push({0, 1});
        while (!pq.empty())
        {
            // Topmost element of the priority queue is with minimum distance value.
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;

            // Iterate through the adjacent nodes of the current popped node.
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                // Check if the previously stored distance value is 
                // greater than the current computed value or not, 
                // if yes then update the distance value.
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});

                    // Update the parent of the adjNode to the recent 
                    // node where it came from.
                    parent[adjNode] = node;
                }
            }
        }

        // If distance to a node could not be found, return an array containing -1.
        if (dist[n] == 1e9)
            return {-1};

        // Store the final path in the ‘path’ array.
        vector<int> path;
        int node = n;

        // Iterate backwards from destination to source through the parent array.
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);

        // Since the path stored is in a reverse order, we reverse the array
        // to get the final answer and then return the array.
        reverse(path.begin(), path.end());
        return path;
    }
