#include<iostream>
#define V 7
using namespace std;
int minimum(int minCost[V],bool sptVisited[V]);
void prims_algo(int graph[V][V],int s);
int main()
{
	int graph[V][V]={{0,25,0,0,0,5,0},
					{25,0,9,0,0,0,6},
					{0,9,0,10,0,0,0},
					{0,0,10,0,12,0,11},
					{0,0,0,12,0,18,16},
					{5,0,0,0,18,0,0},
					{0,6,0,11,16,0,0}};
					prims_algo(graph,0);
}
int minimum(int minCost[V],bool sptVisited[V])
{
	int min=INT_MAX,index;
	for(int i=0;i<V;i++)
	{
		if(sptVisited[i]==false && minCost[i]<min)
		{
			min=minCost[i];
			index=i;
		}
	}
	return index;
}
void prims_algo(int graph[V][V],int s)
{
	int minCost[V],parent[V];
	bool sptVisited[V];
	for(int i=0;i<V;i++)
	{
		minCost[i]=INT_MAX;
		sptVisited[i]=false;
	}
	
	minCost[s]=0;
	parent[s]=-1;
	for(int i=0;i<V-1;i++)				//E=V-1 edges for min spanning tree
	{
		int u=minimum(minCost,sptVisited);
		sptVisited[u]=true;
		for(int v=0;v<V;v++)
		{
			if(graph[u][v] && sptVisited[v]==false && graph[u][v]<minCost[v])
			{
				minCost[v]=graph[u][v];
				parent[v]=u;
			}
		}
	}
	cout<<"Edge \tWeights\n";
	for(int i=0;i<V;i++)
	{
		cout<<parent[i]<<" -> "<<i<<"\t"<<graph[i][parent[i]]<<endl;
	}
}
