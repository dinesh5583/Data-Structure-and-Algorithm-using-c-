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
	btree();

	void insert(int key);
	void LevelOrder() {
	if(root == NULL) return;
	queue<node*> Q;
	Q.push(root);  
	//while there is at least one discovered node
	while(!Q.empty()) {
		node* current = Q.front();
		Q.pop();
	//	Q.pop(); // removing the element at front
		cout<<current->value<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}

private:
	void insert(int key, node *leaf);
	node *root;
};


btree::btree(){
	root = NULL;
}


void btree::insert(int key, node *leaf){

	if(key < leaf->value){
		if(leaf->left != NULL){
			insert(key, leaf->left);
		}else{
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}else if(key >= leaf->value){
		if(leaf->right != NULL){
			insert(key, leaf->right);
		}else{
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}

void btree::insert(int key){
	if(root != NULL){
		insert(key, root);
	}else{
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}
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
	tree->LevelOrder();

}
