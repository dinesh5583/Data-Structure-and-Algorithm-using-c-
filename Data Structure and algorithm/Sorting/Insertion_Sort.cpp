#include<iostream>
using namespace std;
void insertion(int [],int);
int main()
{
	int a[]={8,4,2,1,10,3,9,7,5,6},n=10;
	insertion(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}
void insertion(int a[],int n)
{
	int j,x;
	for(int i=1;i<n;i++)
	{
		j=i-1;
		x=a[i];
		while(j>-1 && a[j]>x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
