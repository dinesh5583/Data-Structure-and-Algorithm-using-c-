#include<iostream>
#include<algorithm>
using namespace std;
int Edit_Distance(string s1,string s2,int m,int n);
int main()
{
	string str1="sunday";
	string str2="saturday";
	int m=str1.length();
	int n=str2.length();
	 cout<<Edit_Distance(str1,str2,m,n);
}
int Edit_Distance(string s1,string s2,int m,int n)
{
	if(m==0) return n;
	if(n==0) return m;
	if(s1[m-1]==s2[n-1])
	{
		return Edit_Distance(s1,s2,m-1,n-1);
	}
	else{
		return 1+min({Edit_Distance(s1,s2,m,n-1),Edit_Distance(s1,s2,m-1,n),Edit_Distance(s1,s2,m-1,n-1)});
	}
	
}
