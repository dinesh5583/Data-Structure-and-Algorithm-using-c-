#include<iostream>
#include<algorithm>
using namespace std;
int knapsack(int W,int wt[],int val[],int n);
int main()
{
	int val[]={10,40,30,50};
	int wt[]={5,4,6,3};
	int n=4,W=10;
	cout<<knapsack(W,wt,val,n);
	
}
int knapsack(int W,int wt[],int val[],int n)
{
	if(n==0||W==0)	return 0;
	if(wt[n-1]>W)	return knapsack(W,wt,val,n-1);
	else{
		return max(knapsack(W,wt,val,n-1),val[n-1]+knapsack(W-wt[n-1],wt,val,n-1));
	}
}
