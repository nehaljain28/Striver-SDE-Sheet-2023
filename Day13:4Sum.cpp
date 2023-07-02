#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int l=j+1;
            int r=n-1;
            int t=target-arr[i]-arr[j];
            while(l<=r){
                if(arr[l]+arr[r]==t){
                    return "Yes";
                }
                else if(arr[l]+arr[r]<t)l++;
                else r--;
            }
        }
    }
    return "No";
}
