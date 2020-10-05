#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >vec;
void dfs(int val)
{
	cout<<val;
	for(const int& node:vec[val])
	{
		dfs(node);
	}
}
int main()
{
	int N,E,u,v,s;
	cout<<"Enter number of nodes and edges ";
	cin>>N>>E;
	vec.resize(N+1);
	while(E--)
	{
		cout<<"enter parent node and their child node";	
		cin>>u>>v;
		vec[u].push_back(v);
	}
		dfs(1);
	return 0;
}
