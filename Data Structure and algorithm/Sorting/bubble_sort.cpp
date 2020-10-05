#include<iostream>
using namespace std;
void bubble(int [],int);
int main()
{
	int a[]={10,4,6,22,7,12,2,34,2,1},n=10;
	bubble(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
void bubble(int a[],int n)
{
	for(int i=0;i<n-1;i++)		//comparison
	{
		int flag=0,temp;
		for(int j=0;j<(n-1)-i;j++)
		{
			if(a[j]>a[j+1])
			{
				flag=1;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		if(flag==0)
		{
			break;
		}
	}	
}

