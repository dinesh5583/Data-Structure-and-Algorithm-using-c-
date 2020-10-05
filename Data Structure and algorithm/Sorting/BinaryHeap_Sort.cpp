#include<iostream>
#include<conio.h>
using namespace std;
void display(int arr[],int n);
void heapsort(int arr[],int n);
void build_maxHeap(int arr[],int n);
void max_heapify(int arr[],int i,int n);

int main()
{
	int A[]={ 1, 3, 5, 4, 6,19,7, 13, 10, 9, 8, 15, 17 };
	int n=sizeof(A)/sizeof(A[0]);
	heapsort(A,n);
	display(A,n);
}
void display(int arr[],int n)
{
	for(int i=0;i<=n-1;i++)
	{
		cout<<arr[i]<<endl;
	}
}
void heapsort(int arr[],int n)
{
	build_maxHeap(arr,n);
	for(int i=n-1;i>=1;i--)
	{
		int temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		n=n-1;
		max_heapify(arr,0,n);
	}
}
void build_maxHeap(int arr[],int n)
{
	for(int i=(n-2)/2;i>=0;i--)
	{
		max_heapify(arr,i,n);
	}
}
void max_heapify(int arr[],int i,int n)
               {
                    int l,r,largest,temp;
                    l=(2*i)+1;
                    r=(2*i)+2;
                    if(arr[l]>arr[i] && l<n) 
                            largest=l;
                    else largest=i;
                    if(arr[largest]<arr[r] && r<n)
                    {
                       largest=r;
                    }
                    if(largest!=i)
                    {
                       temp=arr[i];
                       arr[i]=arr[largest];
                       arr[largest]=temp;
                    	max_heapify(arr,largest,n);
                	}
               }
