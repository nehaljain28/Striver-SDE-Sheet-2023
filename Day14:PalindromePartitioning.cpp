class Solution {
public:
    void part(int ind,string s,vector<vector<string>>&ans,vector<string> str){
        if(ind==s.size()){
            ans.push_back(str);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(palin(s,ind,i)){
                str.push_back(s.substr(ind,i-ind+1));
                part(i+1,s,ans,str);
                str.pop_back();
            }
        }
    }
    bool palin(string s,int ind,int i){
        while(ind<=i){
            if(s[ind++]!=s[i--])return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> str;
        part(0,s,ans,str);
        return ans;
    }
};
