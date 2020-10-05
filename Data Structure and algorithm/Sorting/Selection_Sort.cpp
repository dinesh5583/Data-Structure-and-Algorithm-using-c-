#include<iostream>
using namespace std;
void selection(int [],int);
int main()
{
	int a[]={10,3,2,4,6,8,7,1,5,9},n=10;
	selection(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}
void selection(int a[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
}
