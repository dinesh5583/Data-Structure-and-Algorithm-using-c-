#include<iostream>
using namespace std;
int maxSum(int arr[],int n);
int main()
{
	int arr[]={10,5,15,20};
	int n=4;
	cout<<maxSum(arr,n);
}
int maxSum(int arr[],int n)
{
	if(n==1) return arr[0];
	else if(n==2) return max(arr[0],arr[1]);
	else{
		for(int i=0;i<n;i++)
		{
			return max(maxSum(arr,n-1),maxSum(arr,n-2)+arr[n-1]);
		}
	}
}
