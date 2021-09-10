//Iterative inorder tree traversal using stack

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>

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
	struct node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

// An iterative process to print Inorder traversal of Binary tree
void iterativeInorder(node *root)
{
	// Base Case
	if (root == NULL)
	return;

	// Create an empty stack
	stack<node *> nodeStack;

	/*
	1. root pointing to pointer node.
	2. if stack is not empty or pointer node is not NULL do following:
        2.1 if node pointer not NULL Push pointer node to stack & point it left of node.
        2.2 If node pointer is NULL pop the iten & print it & point pointer to right of popped item.

	 */

	struct node *node;
    node=root;
	while (nodeStack.empty() == false || node!=NULL)
	{

		if(node!=NULL)
        {
		nodeStack.push(node);
		node=node->left;
        }
        else
        {
		node = nodeStack.top();
		printf ("%c ", node->data);   // Pop the top item from stack and print it
		nodeStack.pop();
		node=node->right;
        }

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
iterativeInorder(root);
return 0;
}
