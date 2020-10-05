#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n=5,a=6,b=3,c=3;
	int cut[n+1];
	cut[0]=0;
	for(int i=1;i<=n;i++)
	{
		cut[i]=-1;
		if(i-a>=0) cut[i]=max(cut[i],cut[i-a]);
		if(i-b>=0) cut[i]=max(cut[i],cut[i-b]);
		if(i-c>=0) cut[i]=max(cut[i],cut[i-c]);
		if(cut[i]!=-1)
			cut[i]++;
	}
	cout<<cut[n];

}
