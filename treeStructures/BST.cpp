#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
/* Struct version
 * Will implement 7 basic operations
 * Search, Minimum, Maximum, Predecessor, 
 * Successor, Insert and Delete.
 */
typedef struct node{
	struct node* parent = NULL;
	struct node* left = NULL;
	struct node* right = NULL;
	int key;
}NODE;
void determine(NODE* n){
	if(n == NULL)
		cout<<"not exists"<<endl;
	else
		cout<<n->key<<" exists -> "<<n<<endl;
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
/*
 * Evidence of maximum & minimum function
 * lies in the BST property. 
 */
NODE* tree_minimum(NODE* node){
	while(node->left!=NULL)
		node=node->left;
	return node;
}
NODE* tree_maximum(NODE* node){
	while(node->right!=NULL)
		node=node->right;
	return node;
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
NODE* tree_successor(NODE* node){
/*
 * Successor of x indicates the smallest key
 * among the keys larger than x.
 * Case1: When right subtree of x exists
 * ->Find the minimum on the right subtree.
 * Case2: Otherwise
 * -> Find the parent of subtree which x belongs. 
 */
	if(node->right !=NULL)
		return tree_minimum(node->right);
	NODE* tmp = node->parent;
	while(tmp !=NULL && node == tmp->right){
		node = tmp;
		tmp = tmp->parent;
	}
	return tmp;
}
NODE* tree_predecessor(NODE* node){
/*
 * Finding a predecessor is a symmetric of 
 * finding a successor. 
 */
	if(node->left !=NULL)
		return tree_maximum(node->left);
	NODE* tmp = node->parent;
	while(tmp!=NULL && node == tmp->left){
		node = tmp;
		tmp = tmp->parent;
	}
	return tmp;
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
	//Operation1. Insert
	cout<<"----Operation1: Insert----"<<endl;
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
	//Operation2. Search
	cout<<"----Operation2: Search----"<<endl;
	NODE* ret = tree_search(root, 4);
	determine(ret);
	ret = tree_search(root, 3);
	determine(ret);
	//Operation3. Maximum * Minimum
	cout<<"----Operation3. Max & Min----"<<endl;
	NODE* maxi = tree_maximum(root);
	NODE* mini = tree_minimum(root);
	determine(maxi);
	determine(mini);
	//Operation4. Successor & Predecessor
	cout<<"----Operation4. Succ * Predec----"<<endl;
	NODE* tmp2 = root->right;
	NODE* suc = tree_successor(tmp2);
	NODE* pre = tree_predecessor(tmp2);
	determine(suc);
	determine(pre);
}

