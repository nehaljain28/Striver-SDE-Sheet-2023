int numberOfSmaller(vector<int>arr,int n)
{
    int l=0,r=arr.size()-1;

    while(l<=r)
    {
        int mid=(r+l)/2;
        if(arr[mid]<=n)l=mid+1;
        else r=mid-1;
    }
    return l;
}
int getMedian(vector<vector<int>> &matrix)
{
    int row=matrix.size();
    int c=matrix[0].size();
    int med=(row*c)/2;
    int l=1,r=1e9;
    while(l<=r)
    {
        int mid=(r+l)/2;
        int sum=0;
        for(int i=0;i<row;i++)
        {
            sum+=numberOfSmaller(matrix[i], mid);
        }
        if(sum<=med)l=mid+1;
        else r=mid-1;
    }
    return l;
    // Write your code here.
}
