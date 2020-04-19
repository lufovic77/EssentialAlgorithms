#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
//struct version
typedef struct node{
	struct node* parent = NULL;
	struct node* left = NULL;
	struct node* right = NULL;
	int key;
}NODE;
void determine(NODE* n){
	if(n == NULL)
		cout<<"not exist"<<endl;
	else
		cout<<n->key<<"exist -> "<<n<<endl;
}
void level_order(queue<NODE*>& q){
/*
 * Level order traversal. 
 * Implement using queue.
 * Enqueue nodes of same level 
 * for each function call. 
 */
	if(q.empty())
		return ;
	NODE* tmp = q.front();
	q.pop();
	cout<<tmp -> key <<" ";
	if(tmp -> left != NULL)
		q.push(tmp->left);
	if(tmp->right !=NULL)	
		q.push(tmp->right);
	level_order(q);
	return ;
}
void inorder (NODE* node){
	if(node == NULL)
		return ;
	inorder(node->left);
	cout<<node->key;
	inorder(node->right);
}
NODE* tree_search(NODE*tree, int key){
/* 
 * Tree searching function. 
 * return the node pointer if exists or
 * return NULL if non-exists.
 */
	if(tree == NULL || tree->key == key)
		return tree;
	if(key < tree->key)
		return tree_search(tree->left, key);
	else return tree_search(tree->right, key);
}
NODE* tree_insert(NODE* tree, NODE* tmp){
/*
 * Tree insert function.
 * Search the proper place and place the new node.
 */
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
	 Allocate root of the tree
	 */
	NODE* tmp = (NODE*)(malloc(sizeof(NODE)));
	tmp->key = 7;
	//Operation 1. Insert
	root = tree_insert(root, tmp);
	for(int i=1;i<=5;i++){
		tmp = (NODE*)(malloc(sizeof(NODE)));
		tmp->key = i*2;
		root = tree_insert(root, tmp);
	}
	/* Insert Result
					7
				   / \
				  2	  8
				   \   \
				  	4  10
					 \
					  6
	 */
	queue <NODE*> q;
	q.push(root);
	level_order(q);
	cout<<endl;
	//Operation 2. Search
	NODE* ret = tree_search(root, 4);
	determine(ret);
	ret = tree_search(root, 3);
	determine(ret);

}
