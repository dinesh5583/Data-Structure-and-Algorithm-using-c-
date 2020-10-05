#include<iostream>
#include<algorithm>
using namespace std;
int optimal_strategy(int arr[],int i,int j);
int main()
{
	int arr[]={20,5,4,6};
	int i=0,j=3;
	cout<<optimal_strategy(arr,i,j);
}
int optimal_strategy(int arr[],int i,int j)
{
	if(i+1==j)
	  return max(arr[i],arr[j]);
	else{
		return max(arr[i]+min(optimal_strategy(arr,i+2,j),optimal_strategy(arr,i+1,j-1)),arr[j]+min(optimal_strategy(arr,i+1,j-1),optimal_strategy(arr,i,j-2)));
	}
}
