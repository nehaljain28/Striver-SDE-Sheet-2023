#include <bits/stdc++.h> 
class heap{
    public:
    vector<int>ans;
    vector<int>hp;
    int size=0;
    void insert(int val){
        size+=1;
        hp.push_back(val);
        int ind=size-1;
        while(ind>0){
            int parent=(ind-1)/2;
            if(hp[parent]>hp[size-1]){
                swap(hp[parent],hp[size-1]);
                ind=parent;
            }
            else return;
        }
    }
    void deleter(){
        if(size==0)return;
        ans.push_back(hp[0]);
        hp[0]=hp[size-1];
        size--;
        int i=0;
        while(i<size){
            int left=2*i+1;
            int right=2*1+2;
            if(left<size&&hp[left]<hp[i]){
                swap(hp[left],hp[i]);
                i=left;
            } else if (right < size && hp[right] < hp[i]) {
                swap(hp[right], hp[i]);
                i = right;
            } else
                return;
        }
    }
};
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    heap h;
    for(int i=0;i<n;i++){
        if(q[i][0]==0){
            h.insert(q[i][1]);
        }
        else{
            h.deleter();
        }
    }
    return h.ans;

}
