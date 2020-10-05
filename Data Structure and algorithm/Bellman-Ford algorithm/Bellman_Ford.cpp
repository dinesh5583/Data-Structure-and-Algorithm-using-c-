#include<iostream>
#include<queue>
#define V 7
using namespace std;
void bellman_ford(int graph[V][V],int s);
int main()
{
	int graph[7][7]={{0,6,5,5,0,0,0},
					 {0,0,0,0,-1,0,0},
					 {0,-2,0,0,1,0,0},
					 {0,0,-2,0,0,-1,0},
					 {0,0,0,0,0,0,3},
					 {0,0,0,0,0,0,3},
					 {0,0,0,0,0,0,0,}};
		bellman_ford(graph,0);			// 0 is source
}
void bellman_ford(int graph[V][V],int s)
{
	int dist[V],path[V];
	queue<int> q;
	for(int i=0;i<V;i++)
	{
		dist[i]=INT_MAX;
	}
	dist[s]=0;
	for(int i=0;i<V-1;i++)
	{
		q.push(s);
		while(!q.empty())
		{
			int u=q.front();
				q.pop();
		   for(int v=0;v<V;v++)
		    {
			  if(dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v] && graph[u][v])
			   {
				dist[v]=dist[u]+graph[u][v];
				path[v]=u;
				q.push(v);
		     	}
		    }
		}
	}
	
	
	
	for(int i=0;i<V;i++)
	{
		cout<<i<<"      "<<dist[i]<<"      "<<path[i]<<endl;
	}
}
