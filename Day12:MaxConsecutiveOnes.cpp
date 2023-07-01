int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int l=0,r=0;
    int ans=0,ct=0;
    while(l<=r&&l<n&&r<n){
        
        if(arr[r]==0){
            ct++;
        }
        while(ct>k){
            if(arr[l]==0){
                ct--;
            }
            l++;
        }
        ans=max(ans,r-l+1);
        r++;
    }
    return ans;
}
