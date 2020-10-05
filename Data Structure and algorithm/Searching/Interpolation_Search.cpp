#include<iostream>
using namespace std;

int interpolationSearch(int a[],int  n,int  x);
int main() 
{  
	int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	int x = 19; 
	int index = interpolationSearch(arr, n, x); 

	// If element was found 
	if (index != -1) 
		cout << "Element found at index " << index; 
	else
		cout << "Element not found."; 
	return 0; 
} 
int interpolationSearch(int a[],int  n,int  x)
{
	int l=0,h=n-1;
	while(l<=h && x>=a[l] && x<=a[h])
	{
		int pos = l + (((double)(h - l) /(a[h] - a[l])) * (x - a[l])); 
		if(x==a[pos])
		    return pos;
		if(x>a[pos])
		{
			l=pos+1;
		}
		else
		{
			h=pos-1;
		}
	}
	
	return -1;
}
