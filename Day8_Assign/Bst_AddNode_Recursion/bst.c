#include<stdio.h>
#include<stdlib.h>
#include"bst.h"
#include"stack.h"

node *root = NULL;

node* createNode(){
	node* new_node = (node *)malloc(sizeof(node));
	new_node->left = NULL;
	new_node->data = 0;
	new_node->right = NULL;
	
	return new_node;
}



void bstAddNode(int data){
	node *new_node = createNode();
	new_node->data = data;
	
	if(root == NULL){
		root = new_node;
	}
	else{
		node *trav = root;
		while(1){
			if(data < trav->data){
				if(trav->left == NULL){
					trav->left = new_node;
					break;
				}
				else{
					trav = trav->left;
				}
			}
			else{
				if(trav->right == NULL){
					trav->right  = new_node;
					break;
				}
				else{
					trav = trav->right;
				}
			}
		}	
	}
}

void bstAddNodeRec(node **trav, int data){
	node *new_node = createNode();
	new_node->data = data;

	if(*trav == NULL)
		*trav = new_node;
	else{
		if(data < (*trav)->data)
			bstAddNodeRec(&((*trav)->left), data);
		else
			bstAddNodeRec(&((*trav)->right), data);
	}
}


void bstPreOrderNR(){
	Stack_Data S;
	initStack(&S);

	node *trav = root;
	printf("\nBST PreOrder NR:\n");
	while(trav != NULL || !isStackEmpty(&S)){
		while(trav != NULL)
		{
			printf("%4d", trav->data);
			if(trav->right != NULL)
			{
				push(&S, trav->right);
			}
			trav = trav->left;
		}
		if(!isStackEmpty(&S)){
			trav = peekSP(&S);
			pop(&S);
		}
	}
	printf("\n");
}

void preorder(struct node* trav)
{
	if(trav == NULL)
		return;

	printf("%4d",trav->data);
	preorder(trav->left);
	preorder(trav->right);
}


node* searchWithParent(int key, node **pparent){
	*pparent = NULL;
	 
	 node *trav = root;
	while(trav != NULL){
		if(key == trav->data)
	 		return trav;
		*pparent = trav;
		if(key < trav->data)
	 		trav = trav->left;
		else
			trav = trav->right;
	}
	*pparent = NULL;
	return NULL;

}


void deleteNode(int key){
	node *parent;
	node *temp = searchWithParent(key, &parent);

	if(temp == NULL)
		printf("Node not found!\n");
	else{
		if(temp->left != NULL && temp->right != NULL){ 
			node *succ = temp->right;
			parent = temp;
			while(succ->left != NULL){
				parent = succ;
				succ = succ->left;
			}
		temp->data = succ->data;
		temp = succ;
		}
	}
	
	if(temp->left == NULL){
		if(temp == root)
			root = temp->right;
		else if(temp == parent->left)
			parent->left = temp->right;
		else
			parent->right = temp->right;
	}
	else{
		if(temp == root)
			root = temp->left;
		else if(temp == parent->left)
			parent->left = temp->left;
		else 
			parent->right = temp->left;
	}
	free(temp);
	temp = NULL;
}




















