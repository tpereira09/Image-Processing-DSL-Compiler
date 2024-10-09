#ifndef _SCANNER_H_
#define _SCANNER_H_

#include "../../Output/parser.tab.h" // include the Bison/Yacc generated header file
#include "../../Utils/utils.h" 
#include "stdio.h" 

extern FILE *sourceCode; // external variable for the source code file

int getToken(FILE *inputFile); // function that returns the next token in the source file
int scanner(FILE *inputFile); // feclaration of the main scanner function 

#endif 
