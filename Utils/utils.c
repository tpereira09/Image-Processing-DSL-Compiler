#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to create a new node
Node* createNode(const char* label, int num_children, int value) 
{
    Node *node = (Node*)malloc(sizeof(Node)); // cast the pointer returned by malloc to Node*
    if(node != NULL) 
    {
        node->label = strdup(label); // duplicate the label string
        node->num_children = num_children; // set the number of children
        node->value = value; // set the value
        node->children = (Node**)malloc(num_children * sizeof(Node*)); // allocate memory for the children pointers and cast to Node**
        if (node->children == NULL) 
        {               
            free(node); // free the node if memory allocation for children fails
            return NULL;
        }
        return node; // return the created node
    }
    return NULL; // return NULL if memory allocation for the node fails
}

// function to add a child to a parent node
void addChild(Node *parent, Node *child, int index) 
{
    parent->children[index] = child; // assign the child to the specified index of the parent's children array
}

// function to print the tree structure
void printTree(Node *root, int depth) 
{
    if (root == NULL)
        return; // if the root is NULL, return

    if (strcmp(root->label, "CommandList") == 0 || strcmp(root->label, "Command") == 0) //ignore CommandList and Command 
    {
        for (int i = 0; i < root->num_children; i++) 
        {
            if (root->children[i] != NULL)
                printTree(root->children[i], depth); // recursively print the children without increasing depth
        }
    }
    else 
    {
        for (int i = 0; i < depth; i++)
            printf("\t"); // print tabs to represent depth
        
        printf("%s\n", root->label); // print the label of the current node

        for (int i = 0; i < root->num_children; i++) 
        {
            if (root->children[i] != NULL)
                printTree(root->children[i], depth + 1); // recursively print the children with increased depth
        }
    }
}
