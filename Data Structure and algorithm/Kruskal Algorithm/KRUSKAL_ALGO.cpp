#include<iostream>
#define V 5
using namespace std;
void Union(int i, int j,int []);
int find(int i,int []);
void kruskal_algo(int graph[V][V]);
int main()
{
	 int graph[V][V] = { 
        { 0, 2, 0, 6, 0 }, 
        { 2, 0, 3, 8, 5 }, 
        { 0, 3, 0, 0, 7 }, 
        { 6, 8, 0, 0, 9 }, 
        { 0, 5, 7, 9, 0 }};
		kruskal_algo(graph);
}

void kruskal_algo(int graph[V][V])
{
	int parent[V];
	int edge_cost=0,mincost=0;
	for(int i=0;i<V;i++)
	{
		parent[i]=i;
	}
	while(edge_cost<V-1)
	{
		int min=INT_MAX,a=-1,b=-1;
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				if(find(i,parent)!=find(j,parent) && graph[i][j] && graph[i][j]<min)
				{
				    min=graph[i][j];
				    a=i;
				    b=j;
				}
			}
		}
		Union(a,b,parent);
		cout<<"Edges :   "<<edge_cost++<<" : ("<<a<<b<<")"<<"\t weight"<<min<<endl;
		mincost=mincost+min;
	}
	
	cout<<"MInimum Cost  "<<mincost;
}
int find(int i,int parent[V])
{
	while(parent[i]!=i)
	{
		i=parent[i];
	}
	return i;
}
void Union(int i, int j,int parent[V])
{
	int a=find(i,parent);
	int b=find(j,parent);
	parent[a]=b;
}
