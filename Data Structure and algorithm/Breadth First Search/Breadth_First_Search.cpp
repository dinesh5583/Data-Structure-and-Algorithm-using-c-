#include<iostream>
#include<queue>
using namespace std;
void BFS(int [][7],int,int);
int main()
{
	int a[7][7]={{0,1,1,1,0,0,0},
				{1,0,1,0,0,0,0},
				{1,1,0,1,1,0,0},
				{1,0,1,0,1,0,0},
				{0,0,1,1,0,1,1},
				{0,0,0,0,1,0,0},
				{0,0,0,0,1,0,0},};
	BFS(a,4,7);
}
void BFS(int a[][7],int start,int n)
{
	int i=start,j;
	queue<int> q;
	int visit[7]={0};
	cout<<i<<"\t";
	visit[i]=1;
	q.push(i);
	while(!q.empty())
	{
		i=q.front();
		q.pop();
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==1 && visit[j]==0)
			{
				cout<<j<<"\t";
				visit[j]=1;
				q.push(j);
			}
		}
	}
}

