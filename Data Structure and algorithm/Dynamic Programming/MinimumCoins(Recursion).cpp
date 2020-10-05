#include<iostream>
#include<algorithm>
using namespace std;
int getMin(int arr[],int n, int val);
int main()
{
	int arr[]={9,6,5,1},val=11;
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<getMin(arr,n,val);
}
int getMin(int arr[],int n, int val)
{
	if(val==0) return 0;
	int res=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<=val)
		{
			int sub_res= getMin(arr,n,val-arr[i]);
		if(sub_res!=INT_MAX)
		{
			res=min(res,sub_res+1);
		}
		}
	}
	return res;
}
