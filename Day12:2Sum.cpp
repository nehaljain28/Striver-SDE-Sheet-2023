class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=n-1;
        sort(nums.begin(),nums.end());
        while(left<right)
        {
            if(nums[left]+nums[right]==target)break;
            else if(nums[left]+nums[right]<target)left++;
            else right--;
        }
        return {left,right};
    }
};
