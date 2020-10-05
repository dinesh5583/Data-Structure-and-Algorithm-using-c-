#include<iostream>
using namespace std;
void DFS(int [][7],int,int);
int main()
{
	int a[7][7]={{0,1,1,1,0,0,0},
				{1,0,1,0,0,0,0},
				{1,1,0,1,1,0,0},
				{1,0,1,0,1,0,0},
				{0,0,1,1,0,1,1},
				{0,0,0,0,1,0,0},
				{0,0,0,0,1,0,0},};
	DFS(a,6,7);
}
void DFS(int a[][7],int start,int n)
{
	static int visit[7]={0};
	if(visit[start]==0)
	{	
		cout<<start;
		visit[start]=1;	
		for(int j=0;j<n;j++)
		{
			if(a[start][j]==1 && visit[j]==0)
			{
				DFS(a,j,n);
			}
		}
	}
}
