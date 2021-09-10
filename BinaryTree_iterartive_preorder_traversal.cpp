#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <malloc.h>

using namespace std;

/* A binary tree node has data, left child and right child */
struct node
{
	char data;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node with the given data and
NULL left and right pointers.*/
struct node* newNode(char data)
{
	//struct node* node = new struct node;
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

// An iterative process to print preorder traversal of Binary tree
void iterativePreorder(node *root)
{
	// Base Case
	if (root == NULL)
	return;

	// Create an empty stack and push root to it
	stack<node *> nodeStack;
	nodeStack.push(root);

	/* Pop all items one by one. Do following for every popped item
	a) print it
	b) push its right child
	c) push its left child
	Note that right child is pushed first so that left is processed first */
	while (nodeStack.empty() == false)
	{
		// Pop the top item from stack and print it
		struct node *node = nodeStack.top();
		printf ("%c ", node->data);
		nodeStack.pop();

		// Push right and left children of the popped node to stack
		if (node->right)
			nodeStack.push(node->right);
		if (node->left)
			nodeStack.push(node->left);
	}
}

// Driver program to test above functions
int main()
{
	/* Constructed binary tree is
         A
		/ \
       B   C
	  / \  /\
	 D	 E F G
	  \
       H

*/
struct node *root = newNode('A');
root->left	 = newNode('B');
root->right	 = newNode('C');
root->left->left = newNode('D');
root->left->right = newNode('E');
root->left->left->right = newNode('H');
root->right->left = newNode('F');
root->right->right= newNode('G');
iterativePreorder(root);
//free(node);
return 0;
}
