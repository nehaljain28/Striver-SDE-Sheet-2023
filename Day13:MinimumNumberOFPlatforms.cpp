int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    int ans=1,ct=1;
    sort(at,at+n);
    sort(dt,dt+n);
    int i=1,j=0;
    while(i<n&&j<n){
        if(at[i]>dt[j]){
            i++;
            j++;
        }
        else{
            ct++;
            i++;
        }
        ans=max(ans,ct);
    }
    return ans;
}
