#include<iostream>
using namespace std;
void linear_Search(int a[],int n,int k);
int main()
{
	int a[10]={11,19,22,24,44,56,65,76,78,99},i;
	int n=sizeof(a)/sizeof(a[i]);
	linear_Search(a,n,100);
}
void linear_Search(int a[],int n,int k)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==k){
		cout<<"found";
		return;
		}
		{
			cout<<"not found";
			return;
		}
	}
	cout<<"not found";
}
