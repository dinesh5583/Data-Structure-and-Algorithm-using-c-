#include <iostream>
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
	void findmax();
private:
	void insert(int key, node *leaf);
	int find(node *root);
	node *root;
};


btree::btree(){
	root = NULL;
}
void btree::findmax()
{
	cout<<find(root);
}
int btree::find(node *root)
{
int root_val,left,right,max=INT_MIN;
	if(root!=NULL)
	{
		root_val=root->value;
		left=find(root->left);
		right=find(root->right);
		if(left>right)	max=left;
		else max=right;
		if(root_val>max)
			max=root_val;
	}
	return max;
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
	tree->insert(88);
	tree->insert(11);
	tree->insert(18);
	 tree->findmax();
}
