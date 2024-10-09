#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "../Parser/parser.h" 

#define MAX_VARIABLES 100 // maximum number of variables

// structure to store information about loaded variables
typedef struct 
{
    char *identifier;
    int loaded;
    int array_size;
    int isString;
} LoadedVariable;

int isImageLoaded(char *identifier); // function to check if an image is loaded
void markVariableAsLoaded(char *identifier, int loaded); // function to mark a variable as loaded
int isVariableAString(char *identifier); // function to check if a variable is a string
void markVariableAsString(char *identifier, int isString); // function to mark a variable as a string
int analyzeSemantics(Node *node); // semantic analysis function

// function declarations for semantic checks
int checkLoad(Node *node);
int checkAssignment(Node *node);
int checkShow(Node *node);
int checkPrint(Node *node);
int checkRecognizeText(Node *node);
int checkArithmeticOperation(Node *node);
int checkResize(Node *node);
int checkRotate(Node *node);
int checkUnaryOperation(Node *node);
int checkBinaryOperation(Node *node);
int checkMultiOperation(Node *node);
int checkIndexing(Node *node);

#endif 
