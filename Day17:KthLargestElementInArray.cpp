//max heap
priority_queue<int> pq;
        int n = v.size();

        for(int i = 0;i < n;i++) pq.push(v[i]);
        while(--k) pq.pop();
        
        return pq.top();


//min heap
class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = v.size();

        for(int i = 0;i < n;i++){
            pq.push(v[i]);
            if(pq.size()>k)pq.pop();
        } 
        
        return pq.top();
    }
};
