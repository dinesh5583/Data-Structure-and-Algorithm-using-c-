#include<iostream>
#include<algorithm>
using namespace std;
int LarIncSub(int arr[],int n);
int main()
{
	int arr[]={3,4,2,8,10,5,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<LarIncSub(arr,n);
}
int LarIncSub(int arr[],int n)
{
	int lis[n];
	lis[0]=1;
	for(int i=1;i<n;i++)
	{
		lis[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
			{
				lis[i]=max(lis[i],lis[j]+1); 
			}
		}	
	}
	int res=lis[0];
	for(int i=0;i<n;i++)
	{
		res=max(res,lis[i]);
	}
	
	return res;
}
