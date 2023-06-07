bool isPossible(vector<int>stalls,long long mid,int k)
{
    long long cowpos=stalls[0];
    int cow=1;
    for(int i=1;i<stalls.size();i++)
    {
        if((stalls[i]-cowpos)>=mid)
        {
            cow++;
            cowpos=stalls[i];
        }
    }
    if(cow<k)return false;
    return true;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    long long l=1,r=0;
    for(int i=0;i<n;i++)
    {
        r=(stalls[i]>r)?stalls[i]:r;
    }
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(isPossible(stalls,mid,k))l=mid+1;
        else r=mid-1;
    }
    return r;
    //    Write your code here.
}
