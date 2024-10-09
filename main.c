#include <iostream> 
#include <fstream> 
#include <cstdio> 
#include <sstream>
#include "Frontend/Scanner/scanner.h" 
#include "Frontend/Parser/parser.h"
#include "Frontend/Semantic/semantic.h"
#include "Backend/genCode.h" 

extern struct Node * root; // external declaration of the root node of the AST
FILE *sourceCode; // file pointer for the source code
static size_t lineNumber = 1; // line number tracker

// function for AST generation
int myFrontend(FILE *file) 
{
    parser(file); // perform syntactic analysis on the source file
    //printf("\n----------------  AST  ----------------\n\n"); 
    //printTree(root, 0); 
    return analyzeSemantics(root); // return 0 if there are no semantic errors
}

// function for code generation
#ifdef __cplusplus
extern "C" 
{
#endif

// function to process each node in the AST
void processNode(Node *node, std::stringstream& code) 
{
    if (node == nullptr) // check if the node is null
        return;
    translateNode(node, code); // call translateNode with stringstream code
}

// function to generate code from the AST
std::string generateCode(Node *root) 
{
    std::stringstream code;
    code << "#include \"../Backend/ImageProcessingDsl.h\"\n";
    code << "#include <iostream>\n"; 
    code << "#include <pthread.h>\n"; 
    code << "#include <chrono>\n";
    code << "#include <vector>\n\n"; 

    code << "int main() {\n"; 
    code << "ImageProcessingDsl::Binarization binarization;\n"; 
    code << "ImageProcessingDsl::Countor countor(cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE, cv::Scalar(0, 255, 0));\n";
    code << "ImageProcessingDsl::TextRecognition textRecognition;\n\n";


    processNode(root, code); // process the root node to generate code
    
    code << "return 0;\n"; 
    code << "}\n"; 
    return code.str(); // return generated code as string
}

// function to compile the generated code
int compileCode(const std::string& cCode) 
{
    std::ofstream tempFile("Output/tempCode.cpp"); // create a temporary file
    if (tempFile.is_open()) 
    {
        tempFile << cCode << std::endl; // write the generated code to a temporary file
        tempFile.close();
    } 
    else 
    {
        std::cerr << "Error: Failed to open tempCode.cpp for writing" << std::endl; // error message if file opening fails
        return 1; // return error code if file opening fails
    }

    // compilation command with necessary flags and libraries
    std::string compileCommand = "g++ Output/tempCode.cpp Backend/ImageProcessingDsl.cpp -o Output/output ";
    compileCommand += "$(pkg-config --cflags --libs opencv4) "; 
    compileCommand += "-ltesseract -llept"; 

    int compileResult = system(compileCommand.c_str()); // execute the compilation command

    return 0; // return 0 if compilation is successful
}

#ifdef __cplusplus
}
#endif


int main(int argc, char *argv[]) 
{
    std::stringstream codeStream; 
    sourceCode = fopen(argv[1], "r"); // open the source file
    if (!sourceCode) 
    {
        printf("Failed to open source file: %s\n", argv[1]); // error message if file cannot be opened
        exit(-1); // exit if the source file cannot be opened
    }

    // perform lexical, syntactic, and semantic analysis
    int semanticError = myFrontend(sourceCode); // call myFrontend function
    if (semanticError) 
    {
        fclose(sourceCode); 
        return 1; // return 1 in case of semantic errors
    }

    std::string code = generateCode(root); // generate code from the AST only if there are no semantic errors
    
    int compileResult = compileCode(code); // compile the generated code
    if (compileResult != 0) 
        return compileResult; // handle compilation error

    return 0;
}
