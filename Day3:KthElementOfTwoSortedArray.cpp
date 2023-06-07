int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    if(m>n)return ninjaAndLadoos(row2, row1, n, m, k);
    int l=max(0,k-n),r=min(k,m);
    while(l<=r)
    {
        int cut1=(l+r)/2;
        int cut2=k-cut1;
        int l1 = (cut1 == 0)? 0:row1[cut1-1];
        int l2 = (cut2 == 0)? 0:row2[cut2-1];
        int r1 = (cut1 == m)? 1e5:row1[cut1];
        int r2 = (cut2 == n)? 1e5:row2[cut2];
        if(l1<=r2&&l2<=r1)
        {
            return max(l1,l2);
        }
        else if(l1>r2)r=cut1-1;
        else l=cut1+1;
    }
    return 1;
}
