void solve(vector<int> arr, int n, int k,int index,vector<vector<int>>& ans,

 vector<int>&ds){

    if(index>=n){

        if(k==0){

            ans.push_back(ds);

        }

        return;

    }

    // Take

  //  sum+=arr[index];

    ds.push_back(arr[index]);

    solve(arr,n,k-arr[index],index+1,ans,ds);

    // Not Take

  //  sum-=arr[index];

    ds.pop_back();

    solve(arr,n,k,index+1,ans,ds);

    return;

}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)

{

    // Write your code here.

    vector<vector<int>> ans;

    int sum =0;

    vector<int> ds;

    int index = 0;

    solve(arr,n,k,index,ans,ds);

    return ans;

}

