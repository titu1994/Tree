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
#include <ctype.h>
#include <math.h>
#define SIZE 50


typedef struct Node{
	int data;
	struct Node *left, *right;
}Node;

typedef union Expression{
	int operand;
	char operator;
}Expression;

typedef struct ExpressionNode{
	Expression data;
	struct ExpressionNode  *left,*right;
	int type;
}ExpNode;

/*

typedef struct ArrayNode{
	int data;
	int left, right;
}ArrayNode;

typedef struct ArrayListTree{
	ArrayNode a[SIZE];
	int root; // Root = -1
	int avail; // Avail = 0
}ArrayListTree;

*/

typedef struct ThreadedNode{
	int data;
	int leftflag, rightflag;
	struct ThreadedNode *left, *right;
}ThreadedNode;


void addBinarySearchTree(Node **p, int v);
void addBinarySearchTreeRecursively(Node **p, int v);
int deleteBinarySearchTree(Node **p, int v);
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
int deleteBinaryTree(Node **p, int v);
int largestBinaryTree(Node *p);
int countBinaryTreeNodes(Node *p);
Node* searchBinaryTree(Node *p, int v);

int main(void) {
	Node *root = NULL;
	int choice, ele;

	setbuf(stdout, NULL);

	printf("Enter choice : 1 for add Binary Search Tree Iteratively\n2 for add Binary Search Tree Recursively\n3 for display in Pre Order\n4 for display in In Order\n5 for display in Post Order\n6 to count no of BST Nodes\n7 to count Height of BST\n8 to check if it is Strict BST\n9 to check if it is Complete BST\n10 for Binary Search Recursively\n11 for Binary Search Recursively\n12 to add to Binary Tree Iteratively\n13 to add to Binary Tree Recursively\n14 to find Largest element in BT\n15 to count number of nodes in BT\n");

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
			// Binary Search Tree Recursively
			printf("Enter a value to search\n");
			scanf("%d", &ele);

			if(binarySearchRecursion(root, ele) == 1){
				printf("Exists\n");
			}
			else{
				printf("Does not exist\n");
			}

			break;
		case 12:
			// Add Binary Tree Iteratively

			printf("Enter a value\n");
			scanf("%d", &ele);

			addBinaryTreeIteratively(&root, ele);
			break;
		case 13:
			// Add Binary Tree Recursively

			printf("Enter a value\n");
			scanf("%d", &ele);

			addBinaryTreeRecursively(&root, ele);

			break;
		case 14:
			// Largest Binary Tree
			ele = largestBinaryTree(root);

			printf("Largest element is : %d",ele);

			break;

		case 15:
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

void displayPreOrderIterative(Node *p){
	Node *stack[SIZE];
	int top = -1;

	while(1){

		while(p != NULL){
			printf("%d\t",p->data);
			stack[++top] = p;
		}

		if(top != -1){
			p = stack[top--];
			p = p->right;
		}
		else{
			printf("\n");
			break;
		}
	}
}

void displayInOrderIterative(Node *p){
	Node *stack[SIZE];
	int top = -1;

	while(1){

		while(p != NULL){

			stack[++top] = p;
			p = p->right;
		}

		if(top != -1){
			p = stack[top--];
			printf("%d\t",p->data);
			p = p->right;
		}
		else{
			printf("\n");
			break;
		}
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

		printf("Inserting %d\n", v);

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

			printf("Inserting after %d\n", v);


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

int deleteBinarySearchTree(Node **p, int v){

	Node *temp = *p, *previous = NULL;

	while(temp != NULL){

		if(temp->data == v)
			break;

		previous = temp;

		if(temp->data > v){
			temp = temp->left;
		}
		else{
			temp = temp->right;
		}

	}

	if(temp == NULL)
		return 0;

	if(temp->left != NULL && temp->right != NULL){

		previous = temp;
		Node *succesor = temp->right;

		while(succesor->left != NULL){
			previous = succesor;
			succesor = succesor->left;
		}

		temp->data = succesor->data;
		temp = succesor;

	}

	if(*p == temp){
		if(temp->left != NULL)
			*p = temp->left;
		else
			*p = temp->right;

	}
	else if(temp->left == NULL && temp->right != NULL){

		if(previous->left == temp)
			previous->left = temp;
		else
			previous->right = temp->right;

	}
	else if(temp->left != NULL && temp->right == NULL){

		if(previous->left == temp)
			previous->left = temp->left;
		else
			previous->right = temp->left;

	}
	else if(temp->left == NULL && temp->right == NULL){
		if(previous->left == temp)
			previous->left = NULL;
		else
			previous->right = NULL;
	}

	free(temp);
	return 1;

}


int deleteBinaryTree(Node **p, int v){

	Node *temp = *p, *previous = NULL;

	while(temp != NULL){


		if(temp->data != v){
			previous = searchBinaryTree(*p, v);

			if(previous->left->data == v)
				temp = previous->left;
			else
				temp = previous->right;

		}
		else
			break;

	}

	if(temp == NULL)
		return 0;

	if(temp->left != NULL && temp->right != NULL){

		previous = temp;
		Node *succesor = temp->right;

		while(succesor->left != NULL){
			previous = succesor;
			succesor = succesor->left;
		}

		temp->data = succesor->data;
		temp = succesor;

	}

	if(*p == temp){
		if(temp->left != NULL)
			*p = temp->left;
		else
			*p = temp->right;

	}
	else if(temp->left == NULL && temp->right != NULL){

		if(previous->left == temp)
			previous->left = temp;
		else
			previous->right = temp->right;

	}
	else if(temp->left != NULL && temp->right == NULL){

		if(previous->left == temp)
			previous->left = temp->left;
		else
			previous->right = temp->left;

	}
	else if(temp->left == NULL && temp->right == NULL){
		if(previous->left == temp)
			previous->left = NULL;
		else
			previous->right = NULL;
	}

	free(temp);
	return 1;
}


Node* searchBinaryTree(Node *p, int v){

	if(p == NULL){
		return p;
	}
	else if((p->left != NULL &&p->left->data == v) || (p->right != NULL && p->right->data == v)){
		return p;
	}
	else{
		Node *l = searchBinaryTree(p->left, v);
		Node *r = searchBinaryTree(p->right, v);

		return (l != NULL)? l : r;
	}
}


/*
 * Expression Tree
 */

void addExpressionTree(ExpNode **p, int v, int type){

	if(*p == NULL){
		ExpNode *newNode = NULL;
		newNode = (ExpNode*) calloc(1, sizeof(ExpNode));

		if(type == 1){
			newNode->data.operand = v;
		}
		else{
			newNode->data.operator = v;
		}

		*p = newNode;
	}
	else{
		int ch;

		if(type == 1){
			printf("Inserting %c\n",v);
		}
		else{
			printf("Inserting %d\n",v);
		}

		printf("Enter 1 for left or 2 for right of %c : ", (*p)->data.operator);
		scanf("%d",&ch);

		if(ch == 1){
			addExpressionTree(&(*p)->left, v, type);
		}
		else{
			addExpressionTree(&(*p)->right, v, type);
		}

	}

}

void preOrderExpressionTree(ExpNode *p){

	if(p == NULL)
		return;
	else{
		if(p->type == 1){
			printf("%c ",p->data.operator);
		}
		else{
			printf("%d ",p->data.operand);
		}

		preOrderExpressionTree(p->left);
		preOrderExpressionTree(p->right);
	}
}

void inOrderExpressionTree(ExpNode *p){

	if(p == NULL)
		return;
	else{
		preOrderExpressionTree(p->left);

		if(p->type == 1){
			printf("%c ",p->data.operator);
		}
		else{
			printf("%d ",p->data.operand);
		}

		preOrderExpressionTree(p->right);
	}
}

void postOrderExpressionTree(ExpNode *p){

	if(p == NULL)
		return;
	else{
		preOrderExpressionTree(p->left);
		preOrderExpressionTree(p->right);

		if(p->type == 1){
			printf("%c ",p->data.operator);
		}
		else{
			printf("%d ",p->data.operand);
		}

	}
}

ExpNode* createExpessionTreeFromPostFixExpression(char *a){
	int i;

	ExpNode *root = NULL;
	ExpNode *stack[SIZE];
	int top = -1;

	for(i = 0; a[i]; i++){

		ExpNode *newNode = (ExpNode*) calloc(1, sizeof(ExpNode));

		if(isdigit(a[i])){

			newNode->type = 1;
			newNode->data.operand = a[i] - 48;
			newNode->left = newNode->right = NULL;

			stack[++top] = newNode;
		}
		else{
			newNode->type = 0;
			newNode->data.operator = a[i];

			newNode->right = stack[top--];
			newNode->left = stack[top--];

			stack[++top] = newNode;
		}

	}

	root = stack[top];
	return root;
}


int evaluateExpressionTree(ExpNode *p){

	if(p == NULL)
		return 0;
	else{

		if(p->type == 1){
			return p->data.operand;
		}
		else{
			int x = evaluateExpressionTree(p->left);
			int y = evaluateExpressionTree(p->right);

			switch(p->data.operator){
			case '+':
				return x+y;
			case '-':
				return x-y;
			case '*':
				return x*y;
			case '/':
				return x/y;
			case '%':
				return x%y;
			case '^':
				return (int)pow(x,y);
			}

			return 0;
		}

	}

}


/*
 *
 * Array Implementation of Binary Tree
 *
 */

void addBinarySearchTreeArray(int *a, int p, int v){

	if(a[p] == 0){
		a[p] = v;
	}
	else{
		if(a[p] > v)
			p = 2*p+1;
		else
			p = 2*p+2;

		addBinarySearchTreeArray(a, p, v);
	}

}


void displayPreOrderArray(int *a, int p){

	if(p > SIZE)
		return;

	if(a[p] == 0)
		return;
	else{
		printf("%d\t",a[p]);
		displayPreOrderArray(a, 2*p +1);
		displayPreOrderArray(a, 2*p+2);
	}

}

void displayInOrderArray(int *a, int p){

	if(p > SIZE)
		return;

	if(a[p] == 0)
		return;
	else{

		displayInOrderArray(a, 2*p +1);
		printf("%d\t",a[p]);
		displayInOrderArray(a, 2*p+2);
	}

}

void displayPostOrderArray(int *a, int p){

	if(p > SIZE)
		return;

	if(a[p] == 0)
		return;
	else{

		displayPostOrderArray(a, 2*p +1);
		displayPostOrderArray(a, 2*p+2);
		printf("%d\t",a[p]);
	}

}


/*
 *
 * Array Implementation of Linked List of Binary Search Tree Using ArrayListTree
 *
 */

/*
void init(ArrayListTree *p){
	int i;

	for(i = 0; i < SIZE; i++){
		p->a[i].right = i+1;
		p->a[i].left = -1;
	}

	p->a[SIZE-1].right = -1;
}

int allocate(ArrayListTree *p){
	if(p->avail != -1)
		return p->a[p->avail].right;
	else
		return p->avail;
}

void addBinarySearchTreeArrayList(ArrayListTree *p, int v){

	int point = allocate(p);

	if(point == -1)
		return;

	p->a[point].data = v;
	p->a[point].left = p->a[point].right = -1;

	if(p->root == -1)
		p->root = point;
	else{

		int previous = -1, temp = p->root;

		while(temp != -1){
			previous = temp;

			if(p->a[temp].data > v)
				temp = p->a[temp].left;
			else
				temp = p->a[temp].right;
		}

		if(p->a[previous].data > v)
			p->a[previous].left = point;
		else
			p->a[previous].right = point;

	}

}

void displayPreOrderArrayList(ArrayListTree p, int t){

	if(t == -1)
		return;

	else{
		printf("%d\t", p.a[p.root].data);
		displayPreOrderArrayList(p, p.a[p.root].left);
		displayPreOrderArrayList(p, t.a[t.root].right);
	}

}

void displayInOrderArrayList(ArrayListTree t, int p){

	if(t.root == -1)
		return;

	else{

		displayInOrderArrayList(t, t.a[t.root].left);
		printf("%d\t", t.a[t.root].data);
		displayInOrderArrayList(t.a[t.root].right);
	}

}



void displayPostOrderArrayList(ArrayListTree t){

	if(t.root == -1)
		return;

	else{

		displayPostOrderArrayList(t.a[t.root].left);
		displayPostOrderArrayList(t.a[t.root].right);
		printf("%d\t", t.a[t.root].data);
	}

}

void displayPreOrderAllLeafNodesArrayList(ArrayListTree t){

	if(t.root == -1)
		return;
	else{
		if(t.a[t.root].left == -1 && t.a[t.root].right == -1)
			printf("%d\t",t.a[t.root].data);

		displayPreOrderAllLeafNodesArrayList(t.a[t.root].left);
		displayPreOrderAllLeafNodesArrayList(t.a[t.root].right);
	}

}


*/

/*
 *
 * Threaded Binary Tree
 *
 */



void addThreadedBinaryTree(ThreadedNode **p, int v){

	ThreadedNode *newNode = (ThreadedNode*) calloc(1, sizeof(ThreadedNode));
	newNode->data = v;
	newNode->leftflag = newNode->rightflag = 0;

	if(*p == NULL){
		newNode->left = newNode->right = NULL;
		*p = newNode;
	}
	else{

		ThreadedNode *temp = *p;

		while(1){
			if(temp->data > v && temp->leftflag){
				temp = temp->left;
			}
			else if(temp->data < v && temp->rightflag)
				temp = temp->right;
			else
				break;

			if(temp->data > v){
				newNode->left = temp->left;
				temp->left = newNode;
				temp->leftflag = 1;
				newNode->right = temp;
			}
			else{
				newNode->right = temp->right;
				temp->right = newNode;
				temp->rightflag = 1;
				newNode->left = temp;
			}
		}

	}

}

void displayInOrderThreadedBinaryTree(ThreadedNode *p){

	while(1){
		while(p->leftflag){
			p = p->left;

			printf("%d\t", p->data);

			while(p->rightflag == 0){
				p = p->right;

				if(p == NULL)
					return;

				printf("%d\t", p->data);
			}

			p = p->right;
		}
	}
}


int countNumberOfNodesThreadedBinaryTree(ThreadedNode *p){

	while(1){
		int count = 0;

		while(p->leftflag){
			p = p->left;

			count++;

			while(p->rightflag == 0){
				p = p->right;

				if(p == NULL)
					return count;

				count++;
			}

			p = p->right;
		}
	}

	return 0;
}

int binarySearchThreadedBinaryTree(ThreadedNode *p, int v){

	while(1){

		if(p->data == v){
			return 1;
		}

		if(p->data > v && p->leftflag)
			p = p->left;
		else if(p->data < v && p->rightflag)
			p = p->right;
		else
			return 0;
	}

	return 0;
}
