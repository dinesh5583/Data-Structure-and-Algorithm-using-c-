#include<iostream>
#include<algorithm>
using namespace std;
int editDistance(string s1,string s2,int m,int n);
int main()
{
	 string str1="cat";
	 string str2="cut";
	 int m=str1.size();
	 int n=str2.size();
	 cout<<editDistance(str1,str2,m,n);
}
int editDistance(string s1,string s2,int m,int n)
{
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		dp[0][i]=i;
	}
	for(int j=0;j<=n;j++)
	{
		dp[j][0]=j;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else{
				dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
			}
		}
	}
	return dp[m][n];
	
}
