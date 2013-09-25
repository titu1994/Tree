/*
 ============================================================================
 Name        : Tree.c
 Author      : Somshubra Majumdar
 Version     :
 Copyright   : Your copyright notice
 Description : Tree - Binary and Ordinary
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *left, *right;
}Node;




int main(void) {


	setbuf(stdout, NULL);

	return EXIT_SUCCESS;
}

/*
 *
 * Binary Search Tree
 *
 */

void addBinarySearchTree(Node **p, int v){

	Node *newNode = NULL;
	newNode = (Node*) calloc(1, sizeof(Node));
	newNode->data = v;
	newNode->left = newNode->right = NULL;

	if(*p == NULL){
		*p = newNode;
	}
	else{

		Node *temp = *p, *previous;

		while(temp != NULL){

			previous = temp;

			if(temp->data > v){
				temp = temp->left;
			}
			else{
				temp = temp->right;
			}

		}

		if(previous->data > v){
			previous->left = newNode;
		}
		else{
			previous->right = newNode;
		}

	}

}

void addBinarySearchTreeRecursively(Node **p, int v){

	if(*p == NULL){

		Node *newNode = NULL;
		newNode = (Node*) calloc(1, sizeof(Node));
		newNode->data = v;
		newNode->left = newNode->right = NULL;
		*p = newNode;

	}
	else{

		if((*p)->data > v){

			addBinarySearchTreeRecursively(&(*p)->left, v);
		}
		else{

			addBinarySearchTreeRecursively(&(*p)->right, v);
		}

	}

}

void displayPreOrder(Node *p){

	if(p == NULL){
		return;
	}
	else{
		printf("%d\t", p->data);
		displayPreOrder(p->left);
		displayPreOrder(p->right);
	}

}

void displayInOrder(Node *p){

	if(p == NULL){
		return;
	}
	else{
		displayInOrder(p->left);
		printf("%d\t", p->data);
		displayInOrder(p->right);
	}

}

void displayPostOrder(Node *p){

	if(p == NULL){
		return;
	}
	else{
		displayPostOrder(p->left);
		displayPostOrder(p->right);
		printf("%d\t", p->data);
	}

}

int countBinaryTreeNodes(Node *p){

	if(p == NULL){
		return 0;
	}
	else{
		return 1 + countBinaryTreeNodes(p->left) + countBinaryTreeNodes(p->right);
	}

}

int heightBinaryTree(Node *p){

	if(p == NULL || (p->left == NULL && p->right == NULL)){
		return 0;
	}
	else{

		int x = heightBinaryTree(p->left);
		int y = heightBinaryTree(p->right);

		return (x>y)? (x + 1) : (y + 1);

	}
}

int isStrictBinaryTree(Node *p){

	if(p == NULL){

		return 0;

	}
	else if(p->left == NULL && p->right == NULL){

		return 1;

	}
	else{

		int x = isStrictBinaryTree(p->left);
		int y = isStrictBinaryTree(p->right);

		return x&&y;

	}
}

int isCompleteBinaryTree(Node *p){

	if(p == NULL){

		return 0;
	}
	else if(p->left == NULL && p->right == NULL){

		return 1;
	}
	else{

		int x = isCompleteBinaryTree(p->left);
		int y = isCompleteBinaryTree(p->right);

		return x != 0 && (x == y)? (x + 1) : 0;

	}

}

int binarySearchIterative(Node *p, int v){

	while(p != NULL){

		if(p->data == v){
			return 1;
		}
		else if(p->data > v){
			p = p->left;
		}
		else{
			p = p->right;
		}

	}

	return 0;

}

int binarySearchRecursion(Node *p, int v){

	if(p == NULL){
		return 0;
	}
	else if(p->data == v){
		return 1;
	}
	else{
		if(p->data > v){
			return binarySearchRecursion(p->left, v);
		}
		else{
			return binarySearchRecursion(p->right, v);
		}
	}
}


/*
 *
 * Binary Tree
 *
 */


void addBinaryTreeRecursively(Node **p, int v){

	if(*p == NULL){

		Node *newNode = NULL;
		newNode = (Node*) calloc(1, sizeof(Node));
		newNode->data = v;
		newNode->left = newNode->right = NULL;
		*p = newNode;

	}
	else{

		printf("Inserting %d\n", (*p)->data);

		int choice;
		printf("Enter choice : 1 for left or 2 for right insertion of %d: ", (*p)->data);
		scanf("%d", &choice);

		if(choice == 1)
			addBinaryTreeRecursively(&(*p)->left, v);
		else
			addBinaryTreeRecursively(&(*p)->right, v);

	}

}

void addBinaryTreeIteratively(Node **p, int v){

	Node *newNode = NULL;
	newNode = (Node*) calloc(1, sizeof(Node));
	newNode->data = v;
	newNode->left = newNode->right = NULL;

	if(*p == NULL){
		*p = newNode;
	}
	else{

		Node *temp = *p, *previous;
		int choice;

		while(temp != NULL){

			previous = temp;

			printf("Inserting %d\n", (*p)->data);


			printf("Enter choice : 1 for left or 2 for right insertion of %d: ", (*p)->data);
			scanf("%d", &choice);

			if(choice == 1){
				temp = temp->left;
			}
			else{
				temp = temp->right;
			}

		}

		if(choice == 1){
			previous->left = newNode;
		}
		else{
			previous->right = newNode;
		}

	}

}

int largestBinaryTree(Node *p){

	if(p == NULL){
		return 0;
	}
	else{

		int x = p->data;
		int y = largestBinaryTree(p->left);
		int z = largestBinaryTree(p->right);

		return (x > y)? (x > z? x : z) : (y > z? y : z);

	}

}


