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

void addBinarySearchTree(Node **p, int v);
void addBinarySearchTreeRecursively(Node **p, int v);
void displayPreOrder(Node *p);
void displayInOrder(Node *p);
void displayPostOrder(Node *p);

int countBinarySearchTreeNodes(Node *p);
int heightBinarySearchTree(Node *p);

int isStrictBinarySearchTree(Node *p);
int isCompleteBinarySearchTree(Node *p);

int binarySearchIterative(Node *p, int v);
int binarySearchRecursion(Node *p, int v);

void addBinaryTreeRecursively(Node **p, int v);
void addBinaryTreeIteratively(Node **p, int v);
int largestBinaryTree(Node *p);
int countBinaryTreeNodes(Node *p);

int main(void) {
	Node *root = NULL;
	int choice, ele;

	setbuf(stdout, NULL);

	printf("Enter choice : 1 for add Binary Search Tree Iteratively\n2 for add Binary Search Tree Recursively\n3 for display in Pre Order\n4 for display in In Order\n5 for display in Post Order\n6 to count no of BST Nodes\n7 to count Height of BST\n8 to check if it is Strict BST\n9 to check if it is Complete BST\n10 to add to Binary Tree Iteratively\11 to add to Binary Tree Recursively\n12 to find Largest element in BT\n14 to count number of nodes in BT\n");

	do{
		printf("Enter choice : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			// Add BST Iterative
			printf("Enter a value\n");
			scanf("%d", &ele);

			addBinarySearchTree(&root, ele);
			break;
		case 2:
			// Add BST Recursively
			printf("Enter a value\n");
			scanf("%d", &ele);

			addBinarySearchTreeRecursively(&root, ele);

			break;
		case 3:
			// Display Pre Order
			displayPreOrder(root);
			printf("\n");

			break;
		case 4:
			// Display In Order
			displayInOrder(root);
			printf("\n");

			break;
		case 5:
			// Display Post Order
			displayPostOrder(root);
			printf("\n");

			break;
		case 6:
			// Count Binary Search Tree Node
			ele = countBinarySearchTreeNodes(root);
			printf("%d\n",ele);

			break;
		case 7:
			// Height Binary Search Tree Node
			ele = heightBinarySearchTree(root);
			printf("%d\n", ele);

			break;
		case 8:
			// Check if Strict Binary Search Tree

			if(isStrictBinarySearchTree(root) == 1){
				printf("Is Strict Binary Search Tree\n");
			}
			else{
				printf("Not a Strict Binary Search Tree\n");
			}

			break;
		case 9:
			// Check if Complete Binary Search Tree

			if(isCompleteBinarySearchTree(root) >= 1){
				printf("Is Strict Binary Search Tree\n");
			}
			else{
				printf("Not a Strict Binary Search Tree\n");
			}

			break;
		case 10:
			// Binary Search Tree Iteratively
			printf("Enter a value to search\n");
			scanf("%d", &ele);

			if(binarySearchIterative(root, ele) == 1){
				printf("Exists\n");
			}
			else{
				printf("Does not exist\n");
			}

			break;
		case 11:
			// Add Binary Tree Iteratively

			printf("Enter a value\n");
			scanf("%d", &ele);

			addBinaryTreeIteratively(&root, ele);
			break;
		case 12:
			// Add Binary Tree Recursively

			printf("Enter a value\n");
			scanf("%d", &ele);

			addBinaryTreeRecursively(&root, ele);

			break;
		case 13:
			// Largest Binary Tree
			ele = largestBinaryTree(root);

			printf("Largest element is : %d",ele);

			break;

		case 14:
			// Count No of Binary Tree Nodes
			ele = countBinaryTreeNodes(root);
			printf("%d\n", ele);

			break;

		default:{
			choice = -1;
		}
		}


	}while(choice != -1);


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

int countBinarySearchTreeNodes(Node *p){

	if(p == NULL){
		return 0;
	}
	else{
		return 1 + countBinarySearchTreeNodes(p->left) + countBinarySearchTreeNodes(p->right);
	}

}

int heightBinarySearchTree(Node *p){

	if(p == NULL || (p->left == NULL && p->right == NULL)){
		return 0;
	}
	else{

		int x = heightBinarySearchTree(p->left);
		int y = heightBinarySearchTree(p->right);

		return (x>y)? (x + 1) : (y + 1);

	}
}

int isStrictBinarySearchTree(Node *p){

	if(p == NULL){

		return 0;

	}
	else if(p->left == NULL && p->right == NULL){

		return 1;

	}
	else{

		int x = isStrictBinarySearchTree(p->left);
		int y = isStrictBinarySearchTree(p->right);

		return x&&y;

	}
}

int isCompleteBinarySearchTree(Node *p){

	if(p == NULL){

		return 0;
	}
	else if(p->left == NULL && p->right == NULL){

		return 1;
	}
	else{

		int x = isCompleteBinarySearchTree(p->left);
		int y = isCompleteBinarySearchTree(p->right);

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

int countBinaryTreeNodes(Node *p){

	if(p == NULL){
		return 0;
	}
	else{
		return 1 + countBinaryTreeNodes(p->left) + countBinaryTreeNodes(p->right);
	}


}
