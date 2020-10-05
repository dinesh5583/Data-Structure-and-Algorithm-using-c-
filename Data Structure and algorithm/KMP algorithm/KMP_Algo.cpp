#include<iostream>
#include<string.h>
using namespace std;
void fill_lpr(string,int[],int);
int main()
{
	string txt="THIS IS A TEST TEXT";
	string pat="TEXT";
	int n=txt.length();
	int m=pat.length();
	int lpr[m];
	fill_lpr(pat,lpr,m);
	int i=0,j=0;
	while(i<n)
	{
		if(txt[i]==pat[j])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			cout<<i-j<<"\t";
			j=lpr[j-1];
		}
		else if(i<n && txt[i]!=pat[j])
		{
			if(j==0) i++;
			else j=lpr[j-1];
		}
	}
}
void fill_lpr(string str,int lpr[],int n)
{
	int i=1,len=0;
	lpr[0]=0;
	while(i<n)
	{
		if(str[i]==str[len])
		{
			len++;
			lpr[i]=len;
			i++;
		}
		else 
		{
			if(len==0)   //if str[i]!=str[len]
				{
				lpr[i]=0;
				i++;
				}
			else{
				len=lpr[len-1];
				}
		}
	}
}
