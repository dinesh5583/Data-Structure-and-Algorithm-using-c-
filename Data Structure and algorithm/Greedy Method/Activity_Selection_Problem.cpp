#include<iostream>
#include<algorithm>
using namespace std;
void maxActivity(int s[],int f[],int n);
int main()
{
	int s[] =  {1, 3, 0, 5, 8, 5}; 
    int f[] =  {2, 4, 6, 7, 9, 9}; 
    int n=6;
    maxActivity(s,f,n);
}
void maxActivity(int s[],int f[],int n)
{
	int i,j;
	i=0;
	cout<<i;
	for(j=1;j<n;j++)
	{
		if(s[j]>=f[i])
		{
			cout<<j;
			i=j;
		}
	}
}
