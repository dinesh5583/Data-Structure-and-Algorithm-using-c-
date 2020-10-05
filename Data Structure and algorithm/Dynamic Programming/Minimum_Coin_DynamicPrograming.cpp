#include<iostream>
#include<algorithm>
using namespace std;
int getMin(int arr[],int n, int val);
int main()
{
	int arr[]={3,4,1},val=5;
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<getMin(arr,n,val);
}
int getMin(int arr[],int n,int val)
{
	int dp[val+1];
	 dp[0]=0;
	for(int i=1;i<=val;i++)
	{
		dp[i]=INT_MAX;
	}
	for(int i=1;i<=val;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[j]<=i)
			{
				int sub_res=dp[i-arr[j]];
				if(sub_res!=INT_MAX)
				{
					dp[i]=min(dp[i],sub_res+1);
				}
			}
		}
	}
	return dp[val];
	
}
