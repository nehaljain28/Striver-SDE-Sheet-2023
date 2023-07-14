//dfs
#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
map<graphNode*,graphNode*>mp;
graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	if(!node)return NULL;
	if(mp.find(node)==mp.end()){
		mp[node]=new graphNode(node->data);
		for(graphNode *i:node->neighbours){
			mp[node]->neighbours.push_back(cloneGraph(i));
		}
	}
	return mp[node];
}

//bfs
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        unordered_map<Node*,Node*>mp;
        queue<Node*>q;
        Node *copy=new Node(node->val);
        mp[node]=copy;
        q.push(node);
        while(!q.empty()){
            Node *cur=q.front();
            q.pop();
            for(Node *i:cur->neighbors){
                if(mp.find(i)==mp.end()){
                    mp[i] = new Node(i->val);
                    q.push(i);
                }
                mp[cur]->neighbors.push_back(mp[i]);
            }
        }
        return mp[node];
    }
};
