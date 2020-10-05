#include<iostream>
#include<stack>
using namespace std;
bool isBalanced(string s1);
bool matching(char a,char b);
int main()
{
	string s1="{([()])}";
	if(isBalanced(s1))
	 cout<<"Balanced";
	 else
	 cout<<"not Balanced";
}
bool isBalanced(string str)
{
	stack<char> s;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='(' || str[i]=='{' || str[i]=='[')
		{
			s.push(str[i]);
		}
		else{
			if(s.empty()==true)
				return false;
			else if(matching(s.top(),str[i])==false)
					return false;
			else
				s.pop();
				
		}
	}
	return(s.empty()==true);
}
bool matching(char a,char b)
{
	if((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'))
		return true;
	else{
		return false;
	}
}

