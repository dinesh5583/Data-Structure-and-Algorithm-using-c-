#include<iostream>
using namespace std;
void linear_Search(int a[],int n,int k);
int main()
{
	int a[10]={44,15,32,1,56,31,6,11,64,5},i;
	int n=sizeof(a)/sizeof(a[i]);
	linear_Search(a,n,99);
}
void linear_Search(int a[],int n,int k)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==k){
		cout<<"found";
		return;
	}
	}
	cout<<"not found";
}
