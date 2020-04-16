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
void tree_insert(NODE* tree, NODE* tmp){
	NODE* y = NULL;
	NODE* x = tree; //root of the tree
	while(x!=NULL){

	}
	tmp->parent = NULL;
	if(y == NULL)
		tree = tmp;
	else if(tmp->key < y->key)
		y->left = tmp;
	else
		y->right = tmp;
	return;
}
int main(){
	NODE* root = NULL;
	NODE* tmp = (NODE*)(malloc(sizeof(NODE)));
	tmp->key = 6;
	cout<<tmp->key;
	tree_insert(root, tmp);
	fprintf(stderr, "what");
	cout<<root;
	cout<<root->key;
}
