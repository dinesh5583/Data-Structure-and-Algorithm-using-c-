#include<iostream>					//FOR DIRECTED GRAPH
using namespace std;
class ListNode{
	public:
		int vertexNumber;
		ListNode *next;
};
class Graph
{
	public:
		int V;
		int E;
		ListNode **adj;
};
Graph *adjListOfGraph()
{
	int x,y;
	ListNode *temp,*t;
	Graph *G=new Graph;
	cout<<"Enter No. of Vertices and Edges";
	cin>>G->V>>G->E;
	G->adj=new ListNode*[G->V*sizeof(ListNode)];
	for(int i=0;i<G->V;i++)
	{
		G->adj[i]=new ListNode;
		G->adj[i]->vertexNumber=i;
		G->adj[i]->next=G->adj[i];
	}
	for(int i=0;i<G->E;i++)
	{
		cout<<"Enter Start and End Vertex Of Edge";
		cin>>x>>y;
		temp=new ListNode;
		temp->vertexNumber=y;
		temp->next=G->adj[x];
		t=G->adj[x];
		while(t->next!=G->adj[x])
			t=t->next;	
		t->next=temp;
		//for undirected (remove this for directed graph)
		temp=new ListNode;
		temp->vertexNumber=x;
		temp->next=G->adj[y];
		t=G->adj[y];
		while(t->next!=G->adj[y])
			t=t->next;	
		t->next=temp;
		
		
	}
	for(int i=0;i<G->V;i++)
	{
		ListNode *temp;
		temp=G->adj[i];
		cout<<G->adj[i]->vertexNumber;
		while(temp->next!=G->adj[i])
		{
			temp=temp->next;
			cout<<"->"<<temp->vertexNumber;
		}
		cout<<endl;
	}
	return G;
}
int main()
{
	adjListOfGraph();
}
