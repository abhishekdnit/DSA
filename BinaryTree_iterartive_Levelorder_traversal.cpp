//Iterative Level order tree traversal using queue

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <queue>

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

// An iterative process to print Levelorder traversal of Binary tree
void iterativeLevelorder(node *root)
{
	// Base Case
	if (root == NULL)
	return;

	// Create an empty queue
	queue<node *> nodequeue;

	/*
	1. root pointing to pointer node & push root to queue.
	2. Do the following until queue is empty
	   2.1: node pointer pointing to front & then print the front pointer value.
	   2.2: if left or right node of front is not NULL push to queue
	   2.3: Then pop the front to next address of front.

	 */

	struct node *node;
    node=root;
    nodequeue.push(node);
	while (nodequeue.empty() == false)
    {
        node=nodequeue.front();
        printf("%c ",node->data);

        if(node->left)
            nodequeue.push(node->left);
        if(node->right)
            nodequeue.push(node->right);

        nodequeue.pop();

    }
delete node;
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
iterativeLevelorder(root);
return 0;
}
