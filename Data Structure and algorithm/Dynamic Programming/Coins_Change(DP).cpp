#include<iostream>
using namespace std;
int count(int coin[],int n,int amount);
int main()
{
	int coin[]={1,2,3};
	int sum=4,n=3;
	cout<<count(coin,n,sum);
	
}
int count(int coin[],int n,int amount)
{
	int dp[n+1][amount+1];
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=1;
	}
	for(int i=1;i<=amount;i++)
	{
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=amount;j++)
		{
			if(coin[i-1]<=j)
				dp[i][j]=dp[i][j-coin[i-1]]+dp[i-1][j];
			else{
				dp[i][j]=dp[i-1][j];
			}
			
			
		}
	}
	return dp[n][amount];
	
}
