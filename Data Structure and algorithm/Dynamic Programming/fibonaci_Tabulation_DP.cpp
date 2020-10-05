#include<iostream>
using namespace std;
int fib(int n,int tab[]);
int main()
{
	int n=7;
	int tab[n];
	cout<<fib(n,tab);
}
int fib(int n,int tab[])
{
	tab[0]=0,tab[1]=1;
	for(int i=2;i<=n;i++)
	{
		tab[i]=tab[i-1]+tab[i-2];
		cout<<tab[i];
	}
	return tab[n];
}
