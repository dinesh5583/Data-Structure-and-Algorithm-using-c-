#include<iostream>
using namespace std;
class trieNode
{
	public:
	trieNode* child[26];
	bool isEnd;
	trieNode()
	{
		isEnd=false;
		for(int i=0;i<26;i++)
		{
			child[i]=NULL;
		}
	}
};
class Trie
{
	trieNode *root;
	public:
		Trie(){
		root=NULL;
	    }
	void insert(string str)
	{
		if(root==NULL)
		{
			root=new trieNode;
		}
		trieNode* curr=root;
		for(int i=0;i<str.length();i++)
		{
			int index=str[i]-'a';
			if(curr->child[index]==NULL)
			{
				curr->child[index]=new trieNode;
			}
			curr=curr->child[index];
		}
		curr->isEnd=true;
	}
	bool search(string str)
	{
		trieNode* curr=root;
		if(root==NULL)
		{
			cout<<"empty";
		}
		else{
		for(int i=0;i<str.length();i++)
		{
			int index=str[i]-'a';
			if(curr->child[index]==NULL)
			{
				return false;
			}
			curr=curr->child[index];
		}
		 return curr->isEnd;
		}
	}
	void del(string str)
	{
		int i=0;
		deleted(root,str,i);
	}
	trieNode* deleted(trieNode* root,string str,int i)
	{
		if(root==NULL) 
		{
		return NULL;
		}
		if(i==str.length())
		{
			root->isEnd=false;
			if(isEmpty(root)==true)
			{
				delete root;
				root=NULL;
			}
			return root;
		}
		int index=str[i]-'a';
		root->child[index]=deleted(root->child[index],str,i+1);
		if(isEmpty(root)==true && root->isEnd==false)
		{
			delete root;
			root=NULL;
		}
		return root;
	}
	bool isEmpty(trieNode* root)
	{
		for(int i=0;i<26;i++)
		{
			if(root->child[i]!=NULL)
			{
				return false;
			}
		}
		return true;
	}
	
};
int main()
{
	Trie t;
	t.insert("geek");
	t.insert("geeks");
	t.insert("cat");
	t.insert("zoo");
	t.insert("coat");
	t.del("geek");
	if(t.search("geek"))
	{
		cout<<"found";
	}else{
		cout<<"not found";
	}
}
