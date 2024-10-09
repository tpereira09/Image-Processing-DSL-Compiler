%{
#include "../Frontend/Scanner/scanner.h"
int line_number=1;
%}

%option noyywrap 

number       [0-9]
integer      {number}+
array        _[a-zA-Z0-9_]+
identifier   [a-z_][a-zA-Z0-9_]*
path         \"(\\.|[^\\"])*\"
whitespace   [ \t]+  
comment      \{[^{}]*\}

%%

"resize"                  { return RESIZE; }
"rotate"                  { return ROTATE; }
"flip"                    { return FLIP; }

"load"                    { return LOAD; }
"show"                    { return SHOW; }
"textRecognition"         { return RECOGNIZE_TEXT; }
"print"                   { return PRINT; }

"gaussianBlur"            { return GAUSSIAN_BLUR; }
"bilateralBlur"           { return BILATERAL_BLUR; }
"medianBlur"              { return MEDIAN_BLUR; }
"binaryThreshold"         { return BINARY_THRESHOLD; }
"binaryInvThreshold"      { return BINARY_INV_THRESHOLD; }
"otsuThreshold"           { return OTSU_THRESHOLD; }
"binarization"            { return BINARIZATION; }
"countor"                 { return COUNTOR; }

"loop"                    { return LOOP; }
"compile"                 { return COMPILE; }

"timer"                   { return TIMER; }
"on"                      { return ON; }
"off"                     { return OFF; }

"="                       { return ASSIGNMENT; }
"+"                       { return PLUS; }
"-"                       { return MINUS; }
"*"                       { return TIMES; }
","                       { return COMMA; }
"("                       { return LPAREN; }
")"                       { return RPAREN; }
"["                       { return LBRACKET; }
"]"                       { return RBRACKET; }
"!!"                      { return DOUBLE_EXCLAMATION; }
">>"                      { return DOUBLE_GREATER; }

"SET_MODE"                { return SET_MODE; }
"SEQUENTIAL"              { return SEQUENTIAL_MODE; }
"PARALLEL"                { return PARALLEL_MODE; }
"MAP_REDUCE"              { return PARALLEL_CHUNKED_MODE; }

{array}                   { yylval.stringVal = strdup(yytext); return ARRAY; }
{identifier}              { yylval.stringVal = strdup(yytext); return IDENTIFIER; }
{integer}                 { yylval.intVal = atoi(yytext); return INT; }
{path}                    { yylval.stringVal = strdup(yytext); return PATH; }
{whitespace}              ; /* skip whitespace */ 
{comment}                 ; // ignore comments enclosed in curly braces
\n                        { line_number++; /*printf("\n");*/ }
<<EOF>>                   { return YY_NULL; }
.                         { fprintf(stderr, "Error: [%s] is an invalid token\n", yytext); return ERROR; }

%%

int getToken(FILE *inputFile)
{ 
  static int firstTime = TRUE;
  int currentToken;
  if (firstTime)
  { 
    //printf("\n----------------  TOKENS  ----------------\n\n");
    firstTime = FALSE;
    if (!inputFile) 
    {
      fprintf(stderr, "Error: Input file not opened.\n");
      return YY_NULL;
    }
    yyin = inputFile;
  }
  currentToken = yylex();
  /*switch (currentToken) 
  {
    case RESIZE:
        printf("RESIZE ");
        break;
    case ROTATE:
        printf("ROTATE ");
        break;
    case FLIP:
        printf("FLIP ");
        break;
    case LOAD:
        printf("LOAD ");
        break;
    case SHOW:
        printf("SHOW ");
        break;
    case GAUSSIAN_BLUR:
        printf("GAUSSIAN_BLUR ");
        break;
    case BILATERAL_BLUR:
        printf("BILATERAL_BLUR ");
        break;
    case MEDIAN_BLUR:
        printf("MEDIAN_BLUR ");
        break;
    case BINARY_THRESHOLD:
        printf("BINARY_THRESHOLD ");
        break;
    case BINARY_INV_THRESHOLD:
        printf("BINARY_INV_THRESHOLD ");
        break;
    case OTSU_THRESHOLD:
        printf("OTSU_THRESHOLD ");
        break;
    case RECOGNIZE_TEXT:
        printf("RECOGNIZE_TEXT ");
        break;
    case PRINT:
        printf("PRINT ");
        break;
    case LOOP:
        printf("LOOP ");
        break;
    case ASSIGNMENT:
        printf("ASSIGNMENT ");
        break;
    case BINARIZATION:
        printf("BINARIZATION ");
        break;   
    case COUNTOR:   
        printf("COUNTOR ");
        break;   
    case PLUS:
        printf("PLUS ");
        break;
    case MINUS:
        printf("MINUS ");
        break;
    case TIMES:
        printf("TIMES ");
        break;
    case COMMA:
        printf("COMMA ");
        break;
    case LPAREN:
        printf("LPAREN ");
        break;
    case RPAREN:
        printf("RPAREN ");
        break;
    case LBRACKET:
        printf("LBRACKET ");
        break;
    case RBRACKET:
        printf("RBRACKET ");
        break;
    case DOUBLE_EXCLAMATION:
        printf("DOUBLE_EXCLAMATION ");
        break;
    case DOUBLE_GREATER:
        printf(">> ");
        break;
    case IDENTIFIER:
        printf("IDENTIFIER ");
        break;
    case INT:
        printf("INT ");
        break;
    case PATH:
        printf("PATH ");
        break;
    case ARRAY:
        printf("ARRAY ");
        break;
    case SET_MODE:
        printf("SET_MODE ");
        break;
    case SEQUENTIAL_MODE:
        printf("SEQUENTIAL_MODE ");
        break;
    case PARALLEL_MODE:
        printf("PARALLEL_MODE ");
        break;
    case PARALLEL_CHUNKED_MODE:
        printf("PARALLEL_CHUNKED_MODE ");
        break;
    case YY_NULL:
        printf("\nEND OF FILE\n");
        break;
    case ERROR:
        printf("ERROR ");
        break;
    case COMPILE:
        printf("COMPILE ");
        break;
    case TIMER:
        printf("TIMER ");
        break;
    case ON:
        printf("ON ");
        break;
    case OFF:
        printf("OFF ");
        break;
    default:
        printf("\nError: Unknown token\n");
        break;
  }
  fflush(stdout);
  */
  return currentToken;
}


int scanner(FILE *inputFile) 
{
  int currentToken;
  while (1) 
  {
    currentToken = getToken(inputFile);
    if (currentToken == YY_NULL) 
      break;
  }
  return 0;
}
