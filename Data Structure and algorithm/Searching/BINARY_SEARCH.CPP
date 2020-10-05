#include<iostream>
#include<algorithm>
using namespace std;
void recursive_binary_search(int a[],int ,int ,int k);
void binary_search(int a[],int n,int k);
int main()
{
	int a[]={21,10,4,6,55,9,2,8,11,3,1,5,7};
	int n=13,l=0,h=n-1;
	binary_search(a,n,100);
	sort(a,a+n);
	recursive_binary_search(a,l,h,1);
	
}
void binary_search(int a[],int n,int k)
{
		sort(a,a+n);
		for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	int l=0,h=n-1;
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(k==a[mid])
		{
			cout<<mid<<endl<<endl;
			return;
		}
		else if(k<a[mid])
		{
			h=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<"not found"<<endl<<endl;
}
void recursive_binary_search(int a[],int l,int h,int k)
{
	if(l<=h)
	{
		int mid=(l+h)/2;
		if(k==a[mid])
		{
			cout<<mid;
			return;
		}
		else if(k<a[mid])
		{
			recursive_binary_search(a,l,mid-1,k);
		}
		else{
			recursive_binary_search(a,mid+1,h,k);
		}
	}
	else
	cout<<"not found";
}
