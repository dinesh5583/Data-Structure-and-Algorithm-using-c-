#include<iostream>
using namespace std;
void merge(int a[],int l,int mid,int h);
void mergeSort(int a[],int l,int h); 
int main()
{
	int a[]={10,6,2,3,9,5,1},n=7;
	mergeSort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}
void mergeSort(int a[],int l,int h)
{
	if(l<h)
	{
		int mid=(l+h)/2;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,h);
		merge(a,l,mid,h);
	}
}
void merge(int a[],int l,int mid,int h)
{
	int i,j,k,b[100];
	i=l,j=mid+1,k=l;
	while(i<=mid && j<=h)
	{
		if(a[i]<a[j])
		  b[k++]=a[i++];
		else
			b[k++]=a[j++];  
	}
	for(;i<=mid;i++)
	    b[k++]=a[i];
	for(;j<=h;j++)
	    b[k++]=a[j];
	for(i=l;i<=h;i++)
	{
		a[i]=b[i];
	}
}
