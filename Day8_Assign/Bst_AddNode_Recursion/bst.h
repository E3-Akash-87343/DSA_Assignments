#ifndef __BST_H
#define __BST_H


typedef struct node{
	struct node *left;
	int data;
	struct node *right;

}node;

extern node *root;

node* createNode();
void bstAddNode(int);
void bstPreOrderNR();

void preorder(struct node*);

void bstAddNodeRec(node **, int);
node* searchWithParent(int, node **);
void deleteNode(int);

#endif




