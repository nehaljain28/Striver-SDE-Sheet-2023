int singleNonDuplicate(vector<int>& arr)
{
	int l=0;
	int n=arr.size();
	int r=n-2;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(mid%2==0)
		{
			if(arr[mid]!=arr[mid+1])r=mid-1;
			else l=mid+1;
		}
		else
		{
			if(arr[mid]==arr[mid+1])r=mid-1;
			else l=mid+1;
		}
	}
	return arr[l];
	// Write your code here
}
