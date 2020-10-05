#include<iostream>
#define V 9
using namespace std;
int findMin(int dist[V],bool sptset[V]);
void dijkstra(int graph[V][V],int s);
int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0); 
  
    return 0; 
}
void dijkstra(int graph[V][V],int s)
{
	int dist[V],path[V];
	bool sptset[V];
	for(int i=0;i<V;i++)
	{
		dist[i]=INT_MAX;
		sptset[i]=false;
	}
	dist[s]=0;
	path[0]=NULL;
	for(int count=0;count<V-1;count++)
	{
		int u=findMin(dist,sptset);
		sptset[u]=true;
		for(int v=0;v<V;v++)
		{
			if(!sptset[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
			{
				dist[v]=dist[u]+graph[u][v];
				path[v]=u;
			}
		}
	}
	cout<<"vertex"<<"\t\t"<<"distance from source"<<"\t"<<"previous path"<<endl;
	for(int i=0;i<V;i++)
	{
		cout<<i<<"\t\t"<<dist[i]<<"\t\t\t\t"<<path[i]<<endl;;
	}
}
int findMin(int dist[V],bool sptset[V])
{
	int min=INT_MAX,min_index;
	for(int i=0;i<V;i++)
	{
		if(sptset[i]==false && dist[i]<=min)
		{
			min=dist[i];
			min_index=i;
		}
	}
	return min_index;
}
