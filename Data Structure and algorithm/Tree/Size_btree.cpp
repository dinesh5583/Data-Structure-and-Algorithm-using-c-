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
	void size()
	{
		cout<<"number of element= "<<count(root);
	}
	int count(node *root)
	{
		if(root==NULL)
		{
		return 0; 
		}
		else {
			return(count(root->left)+1+count(root->right));
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
	//while there is at least one discovered node
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

	tree->insert(10);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	//tree->insert(18);
	tree->size();

}
