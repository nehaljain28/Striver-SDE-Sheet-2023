#include <bits/stdc++.h>
bool static compare(const pair<int,int>&a,const pair<int,int>&b){
    return ((a.second*1.0/a.first)>(b.second*1.0/b.first));
} 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    
    sort(items.begin(),items.end(),compare);
    double weight=0,ans=0;
    for(int i=0;i<n;i++){
        if(weight+items[i].first<=w){
            weight+=items[i].first;
            ans+=items[i].second;
        }
        else{
            int rem=w-weight;
            ans+=(items[i].second*1.0/items[i].first*rem);
            break;
        }
    }
    return ans;
}
