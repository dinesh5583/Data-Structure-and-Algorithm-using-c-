#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maximum=100;

int Lcs(string s1,string s2,int m,int n,int memo[][maximum])
{
	if(m==0 || n==0)
	{
		 return 0;
	}
	if(memo[m-1][n-1]!=-1)
		return memo[m-1][n-1];
	if(s1[m-1]==s2[n-1])
		{
			memo[m-1][n-1]=1+Lcs(s1,s2,m-1,n-1,memo);
			return memo[m-1][n-1];
		}
		else{
		memo[m-1][n-1]=max(Lcs(s1,s2,m,n-1,memo),Lcs(s1,s2,m-1,n,memo));
		return memo[m-1][n-1];	
		}
	
}


int main()
{
	string s1="AXYZ";
	string s2="BXYAJZG";
	int m=s1.length(),n=s2.length();
	int memo[m][maximum];
	memset(memo,-1,sizeof(memo));
	cout<<Lcs(s1,s2,m,n,memo);
}
