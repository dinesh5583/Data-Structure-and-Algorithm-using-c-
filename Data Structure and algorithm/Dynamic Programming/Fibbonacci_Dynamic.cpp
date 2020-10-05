#include<iostream>
#define Nil -1
#define max 100
using namespace std;
int fib(int n);
void init_memo();

int memo[max];

int main()
{
	int n=7;
	init_memo();
	cout<<fib(n);
	
	
}
void init_memo()
{
	for(int i=0;i<max;i++)
	{
		memo[i]=Nil;
	}
}

int fib(int n)
{
	
	if(memo[n]==Nil)
	{
		
		if(n==0 || n==1)
		memo[n]=n;
		else
		memo[n]=fib(n-1)+fib(n-2);
	}
	return memo[n];
}
