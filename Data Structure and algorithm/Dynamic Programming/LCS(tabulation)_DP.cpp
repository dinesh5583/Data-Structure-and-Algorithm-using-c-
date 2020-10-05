#include<iostream>
#include<algorithm>
using namespace std;
int Lcs(string s1,string s2,int m,int n);
int main()
{
	string s1="AXYZMNOP";
	string s2="BXYAAAAMNO";
	int m=s1.length();
	int n=s2.length();
	cout<<Lcs(s1,s2,m,n);
}
int Lcs(string str1,string str2,int m,int n)
{
	int tab[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		tab[i][0]=0;
	}
	for(int j=0;j<=n;j++)
	{
		tab[0][j]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(str1[i-1]==str2[j-1])
				tab[i][j]=1+tab[i-1][j-1];
			else{
				tab[i][j]=max(tab[i-1][j],tab[i][j-1]);
			}
		}
		
	}
	
	return tab[m][n];
}
