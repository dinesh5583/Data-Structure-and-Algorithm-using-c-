#include<iostream>
using namespace std;
class Graph{
	public:
	int V;
	int E;
	int adj[100][100];
};
class MATRIX
{
	public:
	Graph *adjMatrix()
	{
	int i,u,v;
	Graph *G=new Graph;
	cout<<"Enter number of edges & Vertices";
	cin>>G->V>>G->E;
	//G-=new int*[G->V*G->V];	`	//Create an Dynamic Array
	for(u=0;u<G->V;u++)
	{
		for(v=0;v<G->V;v++)
		{
			G->adj[u][v]=0;
		}
	}
	for(i=0;i<G->E;i++)
	{
		cout<<"Enter Vertices to connect Edge";
		cin>>u>>v;
		cout<<endl;
		G->adj[u][v]=1;
		G->adj[v][u]=1;
	}
	for(int i=0;i<G->V;i++)
	{
		for(int j=0;j<G->V;j++)
		{
			cout<<G->adj[i][j]<<"\t";
		}
		cout<<endl;
	}
}
};
int main()
{
	MATRIX m;
	m.adjMatrix();
}
