#include<iostream>
#include<algorithm>
using namespace std;
int egg_Drop(int e,int f);
int main()
{
	int e=3,f=6;
	cout<<egg_Drop(e,f);
}
int egg_Drop(int e,int f)
{
	if(f==0 || f==1)
		return f;
	if(e==1)
	 	return f;
	int res=INT_MAX;
	for(int i=1;i<=f;i++)
	{
		int temp=1+max(egg_Drop(e-1,i-1),egg_Drop(e,f-i));
		res=min(res,temp);
	}
	return res;
}
