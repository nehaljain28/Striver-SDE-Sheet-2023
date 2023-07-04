//set
void fun(vector < int > & nums, int index, vector < int > ds, set < vector < int >> & res) {
      if (index == nums.size()) {
        sort(ds.begin(), ds.end());
        res.insert(ds);
        return;
      }
      ds.push_back(nums[index]);
      fun(nums, index + 1, ds, res);
      ds.pop_back();
      fun(nums, index + 1, ds, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        vector<vector<int>>ans;
        vector<int>ds;
        fun(nums, 0, ds, st);
        for(auto i:st){
            ans.push_back(i);
        }
        return ans;
    }
};

//optimal
#include <bits/stdc++.h> 
void findSubsets(int ind, vector < int > & arr, vector < int > & ds, vector < vector < int >> & ans){
             ans.push_back(ds);
         for (int i = ind; i < arr.size(); i++) {
            if (i != ind && arr[i] == arr[i - 1]) continue;
            ds.push_back(arr[i]);
            findSubsets(i + 1, arr, ds, ans);
            ds.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector < vector < int >> ans;
         vector < int > ds;
         sort(arr.begin(), arr.end());
         findSubsets(0, arr, ds, ans);
         return ans;
}
