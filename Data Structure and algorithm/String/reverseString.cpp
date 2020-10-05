#include<iostream>
#include<string>
#include<stack>
using namespace std;
void fun(string s);
int main()
{
	string s;
	getline(cin,s);
	fun(s);
}
void fun(string s)
{
	stack<char> q;
	int l=s.size();
	cout<<l;
	for(int i=0;i<l;i++)
	{
		if(s[i]!=' ')
		{
		q.push(s[i]);
		}
		
		else{
		while(!q.empty())
        { 
        cout<<q.top();
        q.pop();
    	}
    	cout<<" ";
		}
	
	}
	
	
while(!q.empty())
        { 
        cout<<q.top();
        q.pop();
    }
        
	
}
