#include<iostream>
#include<algorithm>
using namespace std;
int getMin(int arr[],int n);
int main()
{
	int arr[]={4,1,5,3,1,3,2,1,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<getMin(arr,n);
}
int getMin(int arr[],int n)
{
	int dp[n];
	dp[0]=0;
	for(int i=1;i<n;i++)
	{
		dp[i]=INT_MAX;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]+j>=i)
				{
					if(dp[j]!=INT_MAX)
					{
						dp[i]=min(dp[i],dp[j]+1);
					}
				}
		}
	}
	return dp[n-1];
}
