//suffix
#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long arr_r[n];
    arr_r[0]=arr[0];
    long ma=arr[0];
    for(int i=1;i<n;i++){
        ma=arr[i]>ma?arr[i]:ma;
        arr_r[i]=ma;
    }
    long arr_l[n];
    arr_l[n-1]=arr[n-1];
    ma=arr[n-1];
    for(int i=n-2;i>=0;i--){
        ma=arr[i]>ma?arr[i]:ma;
        arr_l[i]=ma;
    }
    long sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=(min(arr_r[i],arr_l[i])-arr[i]);
    }
    return sum;
}

//two pointer
#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long sum=0;
    long l=0,r=n-1;
    long lm=0,rm=0;
    while(l<=r){
        if(arr[l]<=arr[r]){
            if(lm<=arr[l]){
                lm=arr[l];
            }
            else{
                sum+=(lm-arr[l]);
            }
            l++;
        }
        else{
            if(rm<=arr[r]){
                rm=arr[r];
            }
            else{
                sum+=(rm-arr[r]);
            }
            r--;
        }
    }
    return sum;
}
