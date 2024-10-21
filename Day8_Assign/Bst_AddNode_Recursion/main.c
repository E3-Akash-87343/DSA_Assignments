#include<stdio.h>
#include"stack.h"
#include "bst.h"
int main(){
	
	bstAddNodeRec(&root,50);
    bstAddNode(25);
    bstAddNode(66);
    bstAddNode(88);
    bstAddNode(20);
    bstAddNode(22);
    bstAddNodeRec(&root,90);
    bstAddNode(50);
    bstAddNode(80);
    bstAddNode(36);
	
	printf("Preorder using recursion.\n");
	preorder(root);

	bstPreOrderNR();
	
	node *parent;
	searchWithParent(22, &parent);
	
	printf("Parent node of %d is %d.\n", 22, parent->data);

	

	return 0;
}



