//optimal 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int ans=0,cur=0;
        set<int>set;
        for(int i=0;i<s.size();i++){
            if(set.find(s[i])!=set.end()){
                while(s[l]!=s[i]&&l<i){
                    set.erase(s[l]);
                    l++;
                   // cur--;
                }
                l++;//cur--;
            }
          
                set.insert(s[i]);
            
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};

//optimal 2
#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    map<char,int>mp;
    int l=0,r=0;
    int ans=0;
    for(int i=0;i<input.size();i++){
        if(mp.find(input[i])!=mp.end())l=max(l,mp[input[i]]+1);
        mp[input[i]]=i;
        ans=max(ans,i-l+1);
    }
    return ans;
}
