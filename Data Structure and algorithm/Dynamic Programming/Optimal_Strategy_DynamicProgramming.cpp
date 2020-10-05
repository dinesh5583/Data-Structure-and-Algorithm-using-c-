#include<iostream>
#include<algorithm>
using namespace std;
int optimal_strategy(int arr[],int n);
int main()
{
	int arr[]={20,5,4,6,8,3};
	int n=6;
	cout<<optimal_strategy(arr,n);
}
int optimal_strategy(int arr[],int n)
{
	int dp[n+1][n+1],j;
	for(int i=0;i<n-1;i++)
		dp[i][i+1]=max(arr[i],arr[i+1]);
	for(int gap=3;gap<n;gap=gap+2)
	{
		for(int i=0;i+gap<n;i++)
		{
			 j=i+gap;
			dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),arr[j]+min(dp[i+1][j-1],dp[i][j-2]));
		}
	}
	return dp[0][n-1];
}
