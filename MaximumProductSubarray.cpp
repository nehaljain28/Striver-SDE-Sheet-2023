 int maxProduct(vector<int>& nums) {
        int ans=INT_MIN,prefix=1,suffix=1;
        bool zpresent=false;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                prefix=1;
                zpresent=true;
            }
            else{
                prefix*=nums[i];
                ans=max(prefix,ans);
            }
        }
        if(zpresent&&ans<0)ans=0;
        zpresent=false;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0){
                suffix=1;
                zpresent=true;
            }
            else{
                suffix*=nums[i];
                ans=max(suffix,ans);
            }
        }
        if(zpresent&&ans<0)ans=0;
        return ans;
    }
