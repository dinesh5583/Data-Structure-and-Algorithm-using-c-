#include<iostream>
using namespace std;
int ceiling(int tail[],int l,int r,int x);
int LarIncSub(int arr[],int n);
int main()
{
	int arr[]={3,10,20,4,6,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<LarIncSub(arr,n);
}
int LarIncSub(int arr[],int n)
{
	int tail[n],len=1;
	tail[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]>tail[len-1])
		{
			tail[len]=arr[i];
			len++;
		}
		else{
			int c=ceiling(tail,0,len-1,arr[i]);
			tail[c]=arr[i];
		}
	}
	return len;
}
int ceiling(int tail[],int l,int r,int x)
{
	while(l<r)
	{
		int m=(l+(r-l))/2;
		if(tail[m]>=x)
			r=m;
		else{
			l=m+1;
		}
	}
	return r;
}
