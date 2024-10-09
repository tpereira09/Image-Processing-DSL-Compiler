#ifndef _UTILS_H_
#define _UTILS_H_

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

// structure definition for a node
typedef struct Node 
{
    char *label; // label of the node
    int value; // value associated with the node
    struct Node **children; // array of pointers to children nodes
    int num_children; // number of children nodes
    struct Node *identifier_list; // pointer to a list of identifiers
} Node;

Node* createNode(const char* label, int num_children, int value); // function to create a new node
void addChild(Node *parent, Node *child, int index); // function to add a child to a parent node
void printTree(Node *root, int depth); // function to print the tree structure

#endif
