#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
//struct version
typedef struct node{
	struct node* parent = NULL;
	struct node* left = NULL;
	struct node* right = NULL;
	int key;
}NODE;
void level_order(NODE* tree){
	if (tree == NULL)
		return;
	cout<<tree->key<<" ";
	level_order(tree->left);
	level_order(tree->right);
}
NODE* tree_insert(NODE* tree, NODE* tmp){
	NODE* y = NULL;
	NODE* x = tree; //root of the tree
	while(x!=NULL){
		y = x;
		if(tmp->key > x->key)
			x = x->right;
		else
			x = x->left;
	}
	tmp->parent = y;
	if(y == NULL)
		tree = tmp;
	else if(tmp->key < y->key)
		y->left = tmp;
	else
		y->right = tmp;
	return tree;
}
int main(){
	NODE* root = NULL;
	/*
	 * Allocate root of the tree*/
	NODE* tmp = (NODE*)(malloc(sizeof(NODE)));
	tmp->key = 7;
	root = tree_insert(root, tmp);
	for(int i=1;i<=5;i++){
		tmp = (NODE*)(malloc(sizeof(NODE)));
		tmp->key = i*2;
		root = tree_insert(root, tmp);
	}
	/* Result
	 				7
				   / \
				  2	  8
				   \   \
				  	4  10
					 \
					  6
	 */
	level_order(root);
}
