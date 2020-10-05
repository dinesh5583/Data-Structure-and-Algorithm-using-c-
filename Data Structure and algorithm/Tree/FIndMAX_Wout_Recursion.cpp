#include<iostream>
#include<queue>
using namespace std;
class node
{
	public:
		int value;
		node *left;
		node *right;
};
class btree
{
	public:
		node *root;
		btree();
		void insert(int key);
		void SearchRec(int f)
		{
			cout<<"        "<<Search(root,f);
			
		}
		int Search(node *root,int f)
		{
			if (root==NULL)
			return 0;
			else if(root->value==f) return 1;
			else{
				int temp=Search(root->left,f);
				if(temp!=0)
				{
					return temp;
				}
				return(Search(root->right,f));
			}
			return 0;
		}
void FindMax()
{
	int max=INT_MIN;
	if(root==NULL) return;
	queue<node*> Q;
	Q.push(root);
	while(!Q.empty())
	{
		node *temp=Q.front();
		Q.pop();
		if(max<temp->value)
		{
			max=temp->value;
		}
		if(temp->left!=NULL) Q.push(temp->left);
		if(temp->right!=NULL) Q.push(temp->right);
	}
	cout<<max;
}
	private:
		void insertItem(int key,node *leaf);
		
};
btree::btree()
		{
			root=NULL;
		}
void btree::insertItem(int key, node *leaf)
{
	if(key<leaf->value)
	{
		if(leaf->left!=NULL)
		{
			insertItem(key,leaf->left);
		}
	else{
		    leaf->left=new node;
		    leaf->left->value=key;
		    leaf->left->right=NULL;
		    leaf->left->left=NULL;
	}  }else if(key>leaf->value)
	    	{
	    		if(leaf->right!=NULL)
	    		{
	    			insertItem(key,leaf->right);
				}
				else
				{
					leaf->right=new node;
					leaf->right->value=key;
					leaf->right->left=NULL;
					leaf->right->right=NULL;
				}
			}
};
void btree::insert(int key)
{
	if(root!=NULL)
	{
		insertItem(key,root);
	}
	else
	{
		root=new node;
		root->value=key;
		root->left=NULL;
		root->right=NULL;
	}
}
int main(){

	//btree tree;
	btree *tree = new btree();

	tree->insert(100);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(88);
	tree->insert(11);
	tree->insert(180);
	tree->SearchRec(9);
	tree->FindMax();
	 
}
