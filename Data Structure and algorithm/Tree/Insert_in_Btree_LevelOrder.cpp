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

	tree->insert(10);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);

}
