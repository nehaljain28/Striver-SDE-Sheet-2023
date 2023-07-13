#include <bits/stdc++.h> 

vector<int> mergeKSortedArrays(vector<vector<int>> arr, int K)
    {
        // {element, {array position, element position}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> q;
        
        for(int i=0; i<arr.size(); i++)
            q.push({arr[i][0], {i, 0}});
         
        vector<int> ans;  
        while(!q.empty())
        {
            int element = q.top().first;
            int apos = q.top().second.first; // array position
            int epos = q.top().second.second; // element position
            q.pop();
            
            ans.push_back(element);
            if(epos+1 < arr[apos].size())
                q.push({arr[apos][epos+1], {apos, epos+1}});
        }
        
        return ans;
    }
