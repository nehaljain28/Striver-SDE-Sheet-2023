#include <bits/stdc++.h> 
bool isPossible(long long mid,vector<int>time,int n,int m)
{
	long long sum=0,c=1;
	for(int i=0;i<m;i++)
	{
		if(sum+time[i]>mid)
		{
			c++;
			sum=time[i];
			if(time[i]>mid)return false;
		}
		else sum+=time[i];
	}
	if(c<=n)return true;
	return false;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{
	if(n>m)return -1;	
	long long l=time[0],r=0;
	for(int i=0;i<m;i++)
	{
		l=(l<time[i])?l:time[i];
		r+=time[i];
	}
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(isPossible(mid,time,n,m))r=mid-1;
		else l=mid+1;
	}
	return l;
	// Write your code here.
}
