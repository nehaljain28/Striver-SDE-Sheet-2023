#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int arr[9]={1,2,5,10,20,50,100,500,1000};
    int i=8,ans=0;
    while(i>=0){
        if(amount==0)break;
        else if(amount-arr[i]>=0){
            amount-=arr[i];
            ans++;
        }
        else if(amount-arr[i]<=0){
            i--;
        }
    }
    return ans;
    // Write your code here
}
