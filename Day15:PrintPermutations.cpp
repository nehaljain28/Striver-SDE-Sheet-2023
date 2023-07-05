//ds space
class Solution {
public:
    void perm(int ind,vector<int>&num,vector<int>&ds,vector<vector<int>>&ans,vector<int>&freq){
        if(ds.size()==num.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<num.size();i++){
            if(!freq[i]){
                freq[i]=1;
                ds.push_back(num[i]);
                perm(i+1,num,ds,ans,freq);
                freq[i]=0;
                ds.pop_back();

            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>freq(nums.size(),0);
        perm(0,nums,ds,ans,freq);
        return ans;
    }
};

//optimal space o(1)
#include <bits/stdc++.h> 
void perm(int ind,string s,vector<string>&ans){
    if(ind==s.size()){
        ans.push_back(s);
        return;
    }
    for(int i=ind;i<s.size();i++){
        swap(s[i],s[ind]);
        perm(ind+1,s,ans);
        swap(s[i],s[ind]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>ans;
    perm(0,s,ans);
    return ans;
}
