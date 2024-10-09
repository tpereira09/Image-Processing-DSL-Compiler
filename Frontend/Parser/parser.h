#ifndef _PARSER_H_
#define _PARSER_H_

#include "../../Output/parser.tab.h" // include the Bison/Yacc generated header file
#include "../../Utils/utils.h" 
#include "../Scanner/scanner.h" 
#include "stdio.h"

extern int line_number; // external variable to track the current line number

void yyerror(const char *s); // declaration of the function to report parsing errors
static int yylex() { return getToken(sourceCode); } // function to invoke the scanner and get the next token
int parser(FILE *inputFile); // declaration of the main parser function

#endif 
