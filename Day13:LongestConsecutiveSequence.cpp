#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    set<int>set;
    for(int i:arr){
        set.insert(i);
    }
    int ans=0,cur_num=0,cur_streak=0;
    for(int i:arr){
        if(!set.count(i-1)){
            cur_num=i;
            cur_streak=1;
            while(set.count(cur_num+1)){
                cur_streak++;
                cur_num++;
            }
            ans=max(ans,cur_streak);
        }
    }
    return ans;
    
}
