#include<iostream>
#include<conio.h>
using namespace std;
class node{
	public:
	int data;
	node *left;
	node *right;
};
class BST
{
	public:
		node *root;
		BST()
		{
			root=NULL;
		}
		node *ins(node *root,int x)
		{
			node *temp;
			if(root==NULL)
			{
				node *temp=new node;
				temp->data=x;
				temp->left=temp->right=NULL;
				cout<<"inserted"<<temp->data<<endl;
				return temp;
			}
			else{
				if(x<root->data)
				{
					root->left=ins(root->left,x);
				}
				else if(x>root->data)
				{
					root->right=ins(root->right,x);
				}
			}
			return root;
		}
		void Inorder(node* root) 
			{ 
    		if (root!= NULL) 
    		{ 
        		Inorder(root->left); 
        		cout << root->data << " "; 
        		Inorder(root->right); 
    		 } 
		}
		node *del(node *p,int x)
		{
			node *q;
			if(p==NULL)
				return NULL;
			if(p->left==NULL && p->right==NULL)
			{
				if(p==root)
				{
					root=NULL;
				}
				delete p;
				return NULL;
			}
			//search element to delete
			if(x<p->data)
			{
				p->left=del(p->left,x);
			}
			else if(x>p->data)
			{
				p->right=del(p->right,x);
			}
			else
			{
				if(Height(p->left)>Height(p->right))
				{
					q=Inpre(p->left);
					p->data=q->data;
					p->left=del(p->left,q->data);
				}
				else
				{
					q=Insuc(p->right);
					p->data=q->data;
					p->right=del(p->right,q->data);
				}
			}
			return p;
		}
		int Height(node *p)
		{
			int X,Y;
			if(p==NULL) return 0;
			X=Height(p->left);
			Y=Height(p->right);
			return X>Y?X+1:Y+1;
		}
		node *Inpre(node *p)
		{
			while(p && p->left!=NULL)
			{
				p=p->right;
			}
			return p;
		}
		node *Insuc(node *p)
		{
			while(p && p->right!=NULL)
			{
				p=p->left;
			}
			return p;
		}
		void search(node *root,int x)
		{
			node *t=root;
			if(t==NULL)
			{
				cout<<"Tree is empty";
			}
			else
			{
				while(t!=NULL)
				{
					if(x==t->data)
					{
						cout<<"found"<<t->data;
						return;
					}
					else if(x<t->data)
					{
						t=t->left;
					}
					else
					t=t->right;
				}
			}
			cout<<"not found";
		}
};

main()
{
	BST t;
	node *root=NULL;
	root=t.ins(root,30);
	t.ins(root,15);
	t.ins(root,7);
	t.ins(root,22);
	t.ins(root,60);
	t.ins(root,45);
	t.ins(root,8);
	t.ins(root,3);
	t.del(root,22);
	t.Inorder(root);
	t.search(root,22);
}

