#include "semantic.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

extern int numIdentifiers;
LoadedVariable loaded_variables[MAX_VARIABLES]; // array to store loaded variables
int num_loaded_variables = 0;

// function to check if a variable is a string for "print"
int isVariableAString(char *identifier) 
{
    for (int i = 0; i < num_loaded_variables; i++) 
    {
        if (strcmp(loaded_variables[i].identifier, identifier) == 0) 
            return loaded_variables[i].isString;
    }
    return 0; // returns 0 if the variable is not found or not loaded
}

// function to mark a variable as a string
void markVariableAsString(char *identifier, int isString) 
{
    for (int i = 0; i < num_loaded_variables; i++) 
    {
        if (strcmp(loaded_variables[i].identifier, identifier) == 0) 
        {
            loaded_variables[i].loaded = isString;
            return;
        }
    }
    // if the variable is not found, add a new entry
    if (num_loaded_variables < MAX_VARIABLES) 
    {
        loaded_variables[num_loaded_variables].identifier = strdup(identifier);
        loaded_variables[num_loaded_variables].isString = isString;
        num_loaded_variables++;
    }
}

// function to check if an image is loaded
int isImageLoaded(char *identifier) 
{
    for (int i = 0; i < num_loaded_variables; i++) 
    {
        if (strcmp(loaded_variables[i].identifier, identifier) == 0) 
            return loaded_variables[i].loaded;
    }
    return 0; // returns 0 if the variable is not found or not loaded
}

// function to mark a variable as loaded
void markVariableAsLoaded(char *identifier, int loaded) 
{
    for (int i = 0; i < num_loaded_variables; i++) 
    {
        if (strcmp(loaded_variables[i].identifier, identifier) == 0) 
        {
            loaded_variables[i].loaded = loaded;
            return;
        }
    }
    // if the variable is not found, add a new entry
    if (num_loaded_variables < MAX_VARIABLES) 
    {
        loaded_variables[num_loaded_variables].identifier = strdup(identifier);
        loaded_variables[num_loaded_variables].loaded = loaded;
        num_loaded_variables++;
    }
}

// define a structure for mapping operation labels to check functions
typedef struct 
{
    const char *label;
    int (*checkFunc)(Node *);
} SemanticCheck;

// array of semantic checks
SemanticCheck semanticChecks[] = {
    {"Load", checkLoad},
    {"Assignment", checkAssignment},
    {"Show", checkShow},
    {"Print", checkPrint},
    {"RecognizeText", checkRecognizeText},
    {"Subtraction", checkArithmeticOperation},
    {"Addition", checkArithmeticOperation},
    {"Multiplication", checkArithmeticOperation},
    {"Resize", checkResize},
    {"Rotate", checkRotate},
    {"Flip", checkUnaryOperation},
    {"Binarization", checkUnaryOperation},
    {"Countor", checkUnaryOperation},
    {"Indexing", checkIndexing},
    {"GaussianBlur", checkMultiOperation},
    {"BilateralBlur", checkMultiOperation},
    {"MedianBlur", checkBinaryOperation},
    {"BinaryThreshold", checkBinaryOperation},
    {"BinaryInverseThreshold", checkBinaryOperation},
    {"OtsuThreshold", checkBinaryOperation}
};

// semantic analysis function
int analyzeSemantics(Node *node) 
{
    if (node == NULL)
        return 0; // return 0 in case of null node

    // loop through semantic checks and apply the appropriate ones based on node label
    for (int i = 0; i < sizeof(semanticChecks) / sizeof(semanticChecks[0]); i++) 
    {
        if (strcmp(node->label, semanticChecks[i].label) == 0) 
        {
            // if there's an error, stop semantic analysis
            if (semanticChecks[i].checkFunc(node) != 0) 
                return 1; // return 1 in case of semantic error
        }
    }

    // recursively analyze children of the current node
    for (int i = 0; i < node->num_children; i++) 
    {
        if (analyzeSemantics(node->children[i]) != 0) 
            return 1; // return 1 if any of the children has semantic error
    }

    return 0; // return 0 if there's no semantic error
}

// implementation of semantic check functions

int checkLoad(Node *node) 
{
    char *identifier = node->children[0]->label;
    markVariableAsLoaded(identifier, 1);
    return 0; // no error
}

int checkAssignment(Node *node) 
{
    char *identifier = node->children[0]->label;
    markVariableAsLoaded(identifier, 1);
    return 0; // no error
}

int checkShow(Node *node) 
{
    char *identifier = node->children[0]->label;
    if (!isImageLoaded(identifier)) 
    {
        printf("variable %s not loaded\n", identifier);
        return 1; // error detected
    }
    return 0; // no error
}

int checkPrint(Node *node) 
{
    char *identifier = node->children[0]->label;
    if (!isVariableAString(identifier)) 
    {
        printf("variable %s is not a string\n", identifier);
        return 1; // error detected
    }
    return 0; // no error
}

int checkRecognizeText(Node *node) 
{
    char *identifier1 = node->children[0]->label;
    if (!isImageLoaded(identifier1)) 
    {
        printf("variable %s not loaded\n", identifier1);
        return 1; // error detected
    }
    char *identifier2 = node->children[1]->label;
    markVariableAsString(identifier2, 1);
    return 0; // no error
}

int checkArithmeticOperation(Node *node) 
{
    char *identifier1 = node->children[0]->label;
    char *identifier2 = node->children[1]->label;
    if (!isImageLoaded(identifier1)) 
    {
        printf("variable %s not loaded\n", identifier1);
        return 1; // error detected
    } 
    else if (!isImageLoaded(identifier2)) 
    {
        printf("variable %s not loaded\n", identifier2);
        return 1; // error detected
    }
    return 0; // no error
}

int checkResize(Node *node) 
{
    char *identifier = node->children[2]->label;
    if (!isImageLoaded(identifier)) 
    {
        printf("variable %s not loaded\n", identifier);
        return 1; // error detected
    }
    return 0; // no error
}

int checkRotate(Node *node) 
{
    char *identifier = node->children[1]->label;
    if (!isImageLoaded(identifier)) 
    {
        printf("variable %s not loaded\n", identifier);
        return 1; // error detected
    } 
    else 
    {
        int angle = node->children[0]->value;
        if (angle < 1 || angle > 359) 
        {
            printf("error: angle for 'rotate' function must be between 1 and 359 degrees.\n");
            return 1; // error detected
        }
    }
    return 0; // no error
}

int checkUnaryOperation(Node *node) 
{
    char *identifier = node->children[0]->label;
    if (!isImageLoaded(identifier)) 
    {
        printf("variable %s not loaded\n", identifier);
        return 1; // error detected
    }
    return 0; // no error
}

int checkBinaryOperation(Node *node) 
{
    char *identifier = node->children[1]->label;
    if (!isImageLoaded(identifier)) 
    {
        printf("variable %s not loaded\n", identifier);
        return 1; // error detected
    }
    return 0; // no error
}

int checkMultiOperation(Node *node) 
{
    char *identifier = node->children[2]->label;
    if (!isImageLoaded(identifier)) 
    {
        printf("variable %s not loaded\n", identifier);
        return 1; // error detected
    }
    return 0; // no error
}

int checkIndexing(Node *node) 
{
    char *identifier = node->children[0]->label;
    int index = node->children[1]->value;
    int array_size = numIdentifiers;
    if (array_size == -1) 
    {
        printf("error: variable '%s' not found.\n", identifier);
        return 1; // error detected
    } 
    else if (index < 0 || index >= array_size) 
    {
        printf("error: index out of bounds for variable '%s'.\n", identifier);
        return 1; // error detected
    }
    return 0; // no error
}
