#include<bits/stdc++.h>
class MedianFinder {
public:
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxh.empty()||maxh.top()>=num)maxh.push(num);
        else minh.push(num);
        if(maxh.size()>minh.size()+1){
            int a=maxh.top();
            maxh.pop();
            minh.push(a);
        }
        else if(minh.size()>maxh.size()){
            int a=minh.top();
            minh.pop();
            maxh.push(a);
        }

    }
    
    int findMedian() {
        if(maxh.size()==minh.size())return (maxh.top()+minh.top())/2;
        else return maxh.top();
    }
};
vector<int> findMedian(vector<int> &arr, int n){
	MedianFinder m;
	// Write your code here 
	vector<int>ans;
	for(auto i:arr){
		m.addNum(i);
		ans.push_back(m.findMedian());
	}
	return ans;
}
