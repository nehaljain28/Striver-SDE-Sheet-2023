#include <algorithm>
void comb(int ind,int target,vector<int>&arr,int n,vector<vector<int>>&ans,vector<int>&ds){
	if(target==0){
		ans.push_back(ds);
		return;
	}
	for(int i=ind;i<n;i++){
		if(i>ind&&arr[i]==arr[i-1])continue;
		if(arr[i]>target)break;
		ds.push_back(arr[i]);
		comb(i+1,target-arr[i],arr,n,ans,ds);
		ds.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>>ans;
	vector<int>ds;
	comb(0,target,arr,n,ans,ds);
	return ans;
}
