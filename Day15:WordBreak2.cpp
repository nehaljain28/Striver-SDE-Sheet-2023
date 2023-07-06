#include <bits/stdc++.h> 
void f(int ind,string s,map<string,bool>&mp,vector<string>&ans,string st){
    if(ind==s.size()){
        ans.push_back(st);
        return;
    }
    for(int i=ind;i<s.size();i++){
        int size=st.size();
        if(mp[s.substr(ind,i-ind+1)]){
            st.append(s.substr(ind,i-ind+1));
            st.push_back(' ');
            f(i+1,s,mp,ans,st);
            int newsize=st.size();
            while(newsize!=size){
                st.pop_back();
                newsize--;
            }
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string>ans;
    string st="";
    map<string,bool>mp;
    for(auto i:dictionary)mp[i]=true;
    f(0,s,mp,ans,st);
    return ans;


}
