


//optimal recursion
void subsum(int ind,int sum,vector<int>&ans,vector<int> &num){
	if(ind==num.size()){
		ans.push_back(sum);
		return;
	}
	subsum(ind+1,sum+num[ind],ans,num);
	subsum(ind+1,sum,ans,num);
}
vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	vector<int>ans;
	subsum(0,0,ans,num);
	sort(ans.begin(),ans.end());
	return ans;	
}
