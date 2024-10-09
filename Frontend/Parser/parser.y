%{
#include "../Frontend/Parser/parser.h"
struct Node * root;
int numIdentifiers;
%}

%token ERROR

%token IDENTIFIER 
%token PATH 
%token INT
%token ARRAY 


%token PLUS 
%token MINUS 
%token TIMES 
%token ASSIGNMENT 
%token COMMA 
%token LPAREN 
%token RPAREN 
%token LBRACKET 
%token RBRACKET 
%token DOUBLE_EXCLAMATION

%token RESIZE 
%token ROTATE 
%token FLIP 

%token LOAD
%token SHOW   
%token GAUSSIAN_BLUR 
%token BILATERAL_BLUR 
%token MEDIAN_BLUR 
%token BINARY_THRESHOLD 
%token BINARY_INV_THRESHOLD 
%token OTSU_THRESHOLD 
%token BINARIZATION
%token COUNTOR

%token LOOP
%token COMPILE
%token DOUBLE_GREATER

%token RECOGNIZE_TEXT  
%token PRINT

%token TIMER
%token ON
%token OFF

%token SET_MODE
%token SEQUENTIAL_MODE
%token PARALLEL_MODE
%token PARALLEL_CHUNKED_MODE

%union 
{
    char *stringVal;
    int intVal;
    struct Node * node;
}

/* Data types */
%type <stringVal> IDENTIFIER PATH ARRAY
%type <intVal> INT
%type <node> command command_list  identifier_list expression expression_list func nested_func func_loop func_list mode on_off


%%

program : command_list { root = $1; }; // Define a program as a list of commands

command_list : command // A program can be a simple command or a list of them
             {
                $$ = createNode("Command", 1, 0); // Create a new Node representing a command list
                addChild($$, $1, 0); // Add the only one command as a child of the program
             }
             | command_list command // Define a command list as a sequence of commands 
             {
                 $$ = createNode("CommandList", 2, 0); // Create a new Node representing a command list
                 addChild($$, $1, 0); // Add the first command as a child of the command list Node
                 addChild($$, $2, 1); // Add the second command as a child of the command list Node
             }
             ;

command : SHOW LPAREN IDENTIFIER RPAREN // Show operation
        {
              $$ = createNode("Show", 1, 0); // Create a new Node representing a show operation
              addChild($$, createNode($3, 0, 0), 0); // Add the expression as a child of the show Node
        }
        | PRINT LPAREN IDENTIFIER RPAREN // Print operation
        {
              $$ = createNode("Print", 1, 0); // Create a new Node representing a print operation
              addChild($$, createNode($3, 0, 0), 0); // Add the identifier as a child of the print Node
        }
        | LOAD LPAREN IDENTIFIER COMMA PATH RPAREN // Load operation
        {
              $$ = createNode("Load", 2, 0); // Create a new Node representing a load operation
              addChild($$, createNode($3, 0, 0), 0); // Add the identifier as a child 
              addChild($$, createNode($5, 0, 0), 1); // Add the path as a child 
        }
        | ARRAY ASSIGNMENT LBRACKET identifier_list RBRACKET // A func can be a list of identifiers in array case
        {
            numIdentifiers = $4->num_children; // Obtém o número de identificadores na lista diretamente
            $$ = createNode("Array", 2, 0); // Define um nó como uma lista de identificadores incluída entre colchetes
            addChild($$, createNode($1, 0, 0), 0);
            addChild($$, $4, 1); // Adiciona a lista de identificadores como filho do nó da expressão
        }  
        | IDENTIFIER ASSIGNMENT expression // Define a command as an assignment operation
        {
              $$ = createNode("Assignment", 2, 0); // Create a new Node representing an assignment operation
              addChild($$, createNode($1, 0, 0), 0); // Add the identifier as a child
              addChild($$, $3, 1); // Add the expression as a child
        }
        | LOOP LPAREN ARRAY COMMA func_loop RPAREN // Define a command as a loop operation
        {
              $$ = createNode("Loop", 2, 0); // Create a new Node representing a loop operation
              addChild($$, createNode($3, 0, 0), 0); // Add the expression as a child of the loop Node
              addChild($$, $5, 1); // Add the function as a child of the loop Node
        }
        | RECOGNIZE_TEXT LPAREN IDENTIFIER COMMA IDENTIFIER RPAREN // Text recognition operation
        {
              $$ = createNode("RecognizeText", 2, 0); // Create a new Node representing a text recognition operation
              addChild($$, createNode($3, 0, 0), 0); // First identifier is the loaded image with a text
              addChild($$, createNode($5, 0, 0), 1); // Second identifier is a variable that contains the text recognized
        }
        | COMPILE DOUBLE_GREATER IDENTIFIER DOUBLE_GREATER func_list
        {
            $$ = createNode("Compile", 2, 0);
            addChild($$, createNode($3, 0, 0), 0); 
            addChild($$, $5, 1); 
        }
        | TIMER LPAREN on_off RPAREN  
        {
            $$ = createNode("Timer", 1, 0);
            addChild($$, $3, 0); 
        } 
        | SET_MODE LPAREN mode RPAREN  
        {
            $$ = createNode("Mode", 1, 0);
            addChild($$, $3, 0); 
        } 
        ;

on_off: ON
      {
        $$ = createNode("On", 1, 0);    
      }
      |
      OFF
      {
        $$ = createNode("Off", 1, 0);    
      }

mode : SEQUENTIAL_MODE
     {
        $$ = createNode("Sequential", 1, 0);    
     }
     | PARALLEL_MODE
     {
        $$ = createNode("Parallel", 1, 0);
     }
     | PARALLEL_CHUNKED_MODE
     {
        $$ = createNode("Parallel_Chunked", 1, 0);
     }
     ;


func : RESIZE LPAREN INT COMMA INT COMMA IDENTIFIER RPAREN // Resize operation
       {
           $$ = createNode("Resize", 3, 0); // Create a new Node representing a resize operation
           addChild($$, createNode("Width", 0, $3), 0); // Add a child Node representing the width
           addChild($$, createNode("Height", 0, $5), 1); // Add a child Node representing the height
           addChild($$, createNode($7, 0, 0), 2); // Add a child Node representing the identifier
       }
       | ROTATE LPAREN INT COMMA IDENTIFIER RPAREN // Rotate operation
       {
           $$ = createNode("Rotate", 2, 0); // Create a new Node representing a rotate operation
           addChild($$, createNode("Angle", 0, $3), 0); // Add a child Node representing the angle
           addChild($$, createNode($5, 0, 0), 1); // Add a child Node representing the identifier
       }
       | FLIP LPAREN IDENTIFIER RPAREN // Flip operation
       {
           $$ = createNode("Flip", 1, 0); // Create a new Node representing a flip operation
           addChild($$, createNode($3, 0, 0), 0); // Add a child Node representing the identifier
       }
       | GAUSSIAN_BLUR LPAREN INT COMMA INT COMMA IDENTIFIER RPAREN // Define a function as a gaussian blur operation
       {
           $$ = createNode("GaussianBlur", 3, 0); // Create a new Node representing a gaussian blur
           addChild($$, createNode("KernelSize", 0, $3), 0); // Add a child Node representing the kernel width 
           addChild($$, createNode("Sigma", 0, $5), 1); // Add a child Node representing the kernel height
           addChild($$, createNode($7, 0, 0), 2); // Add a child Node representing the identifier
       }
       | BILATERAL_BLUR LPAREN INT COMMA INT COMMA IDENTIFIER RPAREN // Define a function as a bilateral blur operation
       {
           $$ = createNode("BilateralBlur", 3, 0); // Create a new Node representing a 'bilateral blur' operation
           addChild($$, createNode("KernelSize", 0, $3), 0); // Add a child Node representing the diameter 
           addChild($$, createNode("Sigma", 0, $5), 1); // Add a child Node representing the sigma color
           addChild($$, createNode($7, 0, 0), 2); // Add a child Node representing the identifier
       }
       | MEDIAN_BLUR LPAREN INT COMMA IDENTIFIER RPAREN // Define a function as a median blur operation
       {
           $$ = createNode("MedianBlur", 2, 0); // Create a new Node representing a median blur operation
           addChild($$, createNode("KernelSize", 0, $3), 0); // Add a child Node representing the kernel size 
           addChild($$, createNode($5, 0, 0), 1); // Add a child Node representing the identifier
       }
       | BINARY_THRESHOLD LPAREN INT COMMA IDENTIFIER RPAREN // Define a function as a binary threshold operation
       {
           $$ = createNode("BinaryThreshold", 2, 0); // Create a new Node representing a binary threshold operation
           addChild($$, createNode("Threshold", 0, $3), 0); // Add a child Node representing the threshold
           addChild($$, createNode($5, 0, 0), 1); // Add a child Node representing the identifier
       }
       | BINARY_INV_THRESHOLD LPAREN INT COMMA IDENTIFIER RPAREN // Define a function as a binary inverse threshold operation
       {
           $$ = createNode("BinaryInverseThreshold", 2, 0); // Create a new Node representing a binary inverse threshold operation
           addChild($$, createNode("Threshold", 0, $3), 0); // Add a child Node representing the threshold
           addChild($$, createNode($5, 0, 0), 1); // Add a child Node representing the identifier 
       }
       | OTSU_THRESHOLD LPAREN INT COMMA IDENTIFIER RPAREN // Define a function as a otsu threshold operation
       {
           $$ = createNode("OtsuThreshold", 2, 0); // Create a new Node representing a otsu threshold operation
           addChild($$, createNode("Threshold", 0, $3), 0); // Add a child Node representing the threshold
           addChild($$, createNode($5, 0, 0), 1); // Add a child Node representing the identifier
       }
       | BINARIZATION LPAREN IDENTIFIER RPAREN 
       {
           $$ = createNode("Binarization", 1, 0); // Create a new Node representing a otsu binary inverse threshold operation
           addChild($$, createNode($3, 0, 0), 0); // Add a child Node representing the identifier
       }
       | COUNTOR LPAREN IDENTIFIER RPAREN 
       {
           $$ = createNode("Countor", 1, 0); // Create a new Node representing a otsu binary inverse threshold operation
           addChild($$, createNode($3, 0, 0), 0); // Add a child Node representing the identifier
       }
       ;

func_loop : RESIZE LPAREN INT COMMA INT RPAREN // Resize operation
        {
            $$ = createNode("ResizeLoop", 3, 0); // Create a new Node representing a resize operation
            addChild($$, createNode("Width", 0, $3), 0); // Add a child Node representing the width
            addChild($$, createNode("Height", 0, $5), 1); // Add a child Node representing the height
        }
        | ROTATE LPAREN INT RPAREN // Rotate operation
        {
            $$ = createNode("RotateLoop", 2, 0); // Create a new Node representing a rotate operation
            addChild($$, createNode("Angle", 0, $3), 0); // Add a child Node representing the angle
        }
        | FLIP LPAREN RPAREN // Flip operation
        {
            $$ = createNode("FlipLoop", 0, 0); // Create a new Node representing a flip operation
        }
        | SHOW LPAREN RPAREN // Flip operation
        {
            $$ = createNode("ShowLoop", 0, 0); // Create a new Node representing a show operation
        }
        | GAUSSIAN_BLUR LPAREN INT COMMA INT RPAREN // Define a function as a gaussian blur operation
       {
           $$ = createNode("GaussianBlurLoop", 2, 0); // Create a new Node representing a gaussian blur
           addChild($$, createNode("KernelSize", 0, $3), 0); // Add a child Node representing the kernel width 
           addChild($$, createNode("Sigma", 0, $5), 1); // Add a child Node representing the kernel height
       }
       | BILATERAL_BLUR LPAREN INT COMMA INT RPAREN // Define a function as a bilateral blur operation
       {
           $$ = createNode("BilateralBlurLoop", 2, 0); // Create a new Node representing a 'bilateral blur' operation
           addChild($$, createNode("KernelSize", 0, $3), 0); // Add a child Node representing the diameter 
           addChild($$, createNode("Sigma", 0, $5), 1); // Add a child Node representing the sigma color
       }
       | MEDIAN_BLUR LPAREN INT RPAREN // Define a function as a median blur operation
       {
           $$ = createNode("MedianBlurLoop", 1, 0); // Create a new Node representing a median blur operation
           addChild($$, createNode("KernelSize", 0, $3), 0); // Add a child Node representing the kernel size 
       }
       | BINARY_THRESHOLD LPAREN INT RPAREN // Define a function as a binary threshold operation
       {
           $$ = createNode("BinaryThresholdLoop", 1, 0); // Create a new Node representing a binary threshold operation
           addChild($$, createNode("Threshold", 0, $3), 0); // Add a child Node representing the threshold
       }
       | BINARY_INV_THRESHOLD LPAREN INT RPAREN // Define a function as a binary inverse threshold operation
       {
           $$ = createNode("BinaryInverseThresholdLoop", 1, 0); // Create a new Node representing a binary inverse threshold operation
           addChild($$, createNode("Threshold", 0, $3), 0); // Add a child Node representing the threshold
       }
       | OTSU_THRESHOLD LPAREN INT RPAREN // Define a function as a otsu threshold operation
       {
           $$ = createNode("OtsuThresholdLoop", 1, 0); // Create a new Node representing a otsu threshold operation
           addChild($$, createNode("Threshold", 0, $3), 0); // Add a child Node representing the threshold
       }
       | BINARIZATION LPAREN RPAREN 
       {
           $$ = createNode("BinarizationLoop", 0, 0); // Create a new Node representing a otsu binary inverse threshold operation
       }
       | COUNTOR LPAREN RPAREN 
       {
           $$ = createNode("CountorLoop", 0, 0); // Create a new Node representing a otsu binary inverse threshold operation
       }
       ;

func_list : func_loop
            {
                $$ = createNode("func", 1, 0); // Define an function list with a single function
                addChild($$, $1, 0); // Add the function as a child of the function list Node
            }
            | func_list DOUBLE_GREATER func_loop 
            {
                Node *temp = createNode("funcList", $$->num_children + 1, 0); 
                for (int i = 0; i < $$->num_children; i++) 
                {
                    addChild(temp, $$->children[i], i); 
                }
                addChild(temp, $3, $$->num_children);
                $$ = temp; 
            }
            ;

expression : func { $$ = $1; } // Define an expression as a function call
           | IDENTIFIER TIMES IDENTIFIER 
           {
                $$ = createNode("Multiplication", 2, 0); // Define an expression as a multiplication operation
                addChild($$, createNode($1, 0, 0), 0); // Add the first identifier as a child of the multiplication Node
                addChild($$, createNode($3, 0, 0), 1); // Add the second identifier as a child of the multiplication Node
           }
           | IDENTIFIER PLUS IDENTIFIER 
           {
                  $$ = createNode("Addition", 2, 0); // Define an expression as an addition operation
                  addChild($$, createNode($1, 0, 0), 0); // Add the first identifier as a child of the addition Node
                  addChild($$, createNode($3, 0, 0), 1); // Add the second identifier as a child of the addition Node
           }
           | IDENTIFIER MINUS IDENTIFIER 
           {
                  $$ = createNode("Subtraction", 2, 0); // Define an expression as a subtraction operation
                  addChild($$, createNode($1, 0, 0), 0); // Add the first identifier as a child of the subtraction Node
                  addChild($$, createNode($3, 0, 0), 1); // Add the second identifier as a child of the subtraction Node
           }
           | ARRAY DOUBLE_EXCLAMATION INT 
            {
                $$ = createNode("Indexing", 2, 0); // Define an expression as an indexing operation
                addChild($$, createNode($1, 0, 0), 0); // Add the identifier as a child of the indexing Node
                addChild($$, createNode("Index", 0, $3), 1); // Add a child Node representing the index
            } 
           | nested_func { $$ = $1; } // Define an expression as a nested function call
           ;

nested_func : IDENTIFIER LPAREN expression_list RPAREN 
            {
                  $$ = createNode($1, $3->num_children, 0); // Define a nested function as a function call
                  for (int i = 0; i < $3->num_children; i++) 
                  {
                    addChild($$, $3->children[i], i); // Add each expression in the list as a child of the nested function Node
                  }
            }
            ;

expression_list : expression 
                {
                      $$ = createNode("Expression", 1, 0); // Define an expression list with a single expression
                      addChild($$, $1, 0); // Add the expression as a child of the expression list Node
                }
                | expression_list COMMA expression 
                {
                      Node *temp = createNode("ExpressionList", $$->num_children + 1, 0); // Define an expression list with multiple expressions
                      for (int i = 0; i < $$->num_children; i++) 
                      {
                          addChild(temp, $$->children[i], i); // Add each expression from the existing list to the new list
                      }
                      addChild(temp, $3, $$->num_children); // Add the new expression to the end of the list
                      $$ = temp; // Set the result to the new expression list Node
                }
                ;

identifier_list : IDENTIFIER 
                {
                    $$ = createNode("Identifier", 1, 0); // Define an identifier list with a single identifier
                    addChild($$, createNode($1, 0, 0), 0); // Add the identifier as a child of the identifier list Node
                }
                | identifier_list COMMA IDENTIFIER 
                {
                    Node *temp = createNode("IdentifierList", $$->num_children + 1, 0); // Define an identifier list with multiple identifiers.
                    for (int i = 0; i < $$->num_children; i++) 
                    {
                        addChild(temp, $$->children[i], i); // Add each identifier from the existing list to the new list.
                    }
                    addChild(temp, createNode($3, 0, 0), $$->num_children); // Add the new identifier to the end of the list.
                    $$ = temp; // Set the result to the new identifier list Node.
                }
                ;

%%


void yyerror(const char *s) 
{
  fprintf(stderr, "Error: %s in line %d \n\n", s, line_number);
}

int parser(FILE *inputFile) 
{
    if (!inputFile)
    {
        printf("Error: Input file not opened.\n");  
        return 1;
    }
    yyparse();
    return 0;
}
