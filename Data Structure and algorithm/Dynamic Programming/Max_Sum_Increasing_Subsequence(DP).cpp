#include<iostream>
#include<algorithm>
using namespace std;
int msis(int arr[],int n);
int main()
{
	int arr[]={3,20,4,6,7,30};
	int n=6;
	cout<<msis(arr,n);
}
int msis(int arr[],int n)
{
	int msis[n];
	for(int i=0;i<n;i++)
		msis[i]=arr[i];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && msis[i]<msis[j]+arr[i])
				msis[i]=msis[j]+arr[i];
		}
	}
	int res=msis[0];
	for(int i=1;i<n;i++)
	{
		res=max(res,msis[i]);
	}
	return res;
}
