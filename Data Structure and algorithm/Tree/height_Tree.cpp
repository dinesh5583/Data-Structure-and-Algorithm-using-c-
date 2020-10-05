#include <iostream>
#include<queue>
using namespace std;


class node{
	public:
	int value;
	node *left;
	node *right;
};

class btree{
public:
	node *root;
	btree(){
		root=NULL;
	}
	void height_T(){
		cout<<"height of tree =  "<<tree(root);
	}
	int tree(node *root)
	{
		if(root==NULL) return 0;
		else
		{
			int leftsize=tree(root->left);
			int rightsize=tree(root->right);
			if(leftsize>rightsize)
				return (leftsize+1);
			else
				return (rightsize+1);
			}	
	}
	void insert( int key) {
	if(root==NULL){
		root=new node;
		root->value=key;
		root->right=NULL;
		root->left=NULL;
		cout<<"insert"<<key<<"\n";
		return;
	}
	queue<node*> Q;
	Q.push(root);  
	while(!Q.empty()) {
		node* current = Q.front();
		Q.pop();
		if(current->left != NULL) Q.push(current->left);
		else{
			current->left=new node;
			current->left->value=key;
			current->left->left=NULL;
			current->left->right=NULL;
			cout<<"inserted"<<key<<"\n";
			return;
		}
		if(current->right != NULL) Q.push(current->right);
		else{
			current->right=new node;
			current->right->value=key;
			current->right->left=NULL;
			current->right->right=NULL;
			cout<<"inserted"<<key<<"\n";
			return;
		}
	}
}
};


int main(){

	//btree tree;
	btree *tree = new btree();

	tree->insert(3);
	tree->insert(5);
	tree->insert(2);
	tree->insert(1);
	tree->insert(4);
	tree->insert(6);
	tree->insert(7);
	tree->height_T();
}
