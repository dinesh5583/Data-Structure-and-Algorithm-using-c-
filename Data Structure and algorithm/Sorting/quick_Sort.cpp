#include<iostream>
using namespace std;
int partition(int a[], int p,int r);
void quickSort(int a[],int p,int r);
int main()
{
	int a[]={10,4,5,1,33,7,2,11,3,6};
	int n=10;
	quickSort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
void quickSort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quickSort(a,p,q-1);
		quickSort(a,q+1,r);
	}
}
int partition(int a[], int p,int r)
{
	int i,j,x=a[r],temp;
	i=p-1;
	for(j=p;j<r;j++)
	{
		if(a[j]<x)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return i+1;
	
}

