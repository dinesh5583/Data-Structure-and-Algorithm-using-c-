#include<iostream>
#include<algorithm>
using namespace std;
int noOfBst(int n);
int main()
{
	int n=4;
	cout<<noOfBst(n);
}
int noOfBst(int n)
{
	int dp[n+1];
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=0;
		for(int j=0;j<i;j++)
		{
			dp[i]+=dp[j]*dp[i-j-1];
		}
	}
	return dp[n];
}
