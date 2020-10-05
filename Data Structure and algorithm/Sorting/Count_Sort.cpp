#include<iostream>
using namespace std;
int findmax(int a[],int n);
void countSort(int a[],int );
int main()
{
	int a[]={10,4,1,4,9,11,10,4,3,5,11,3};
	int n=12;
	countSort(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}
void countSort(int a[],int n)
{  
	int i,j,max;
	int *c;
	max=findmax(a,n);
	c=new int[max+1];
	for(j=0;j<max+1;j++)
	{
		c[j]=0;
	}
	for(i=0;i<n;i++)
	{
		c[a[i]]++;
	}
	i=0;j=0;
	while(j<max+1)
	{
		if(c[j]>0)
		{
			a[i++]=j;
			c[j]--;
		}
		else
		{
			j++;
		}
	}
	
}
int findmax(int a[],int n)
{
	int i,max=-1;
	for(i=0;i<n;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	return max;
}
