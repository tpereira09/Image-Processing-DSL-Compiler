<<<<<<< HEAD
# Image-Processing-DSL-Compiler
This is a project of a Compiler for Simplified Image Processing OpenCV operations.
=======
# Image Processing DSL Compiler

This is a project of a Compiler for Simplified Image Processing OpenCV operations.

It is organized as follows:

--> Frontend
- Scanner: This folder contains all files related to the lexical analyzer.
- Parser: This folder contains all files related to the syntactic analyzer. 
- Semantic: This folder contains all files related to the semantic analyzer. 

--> Backend
- Backend: This folder contains all files related to the code generation. 
- genCode.cpp: Contains two different types of code generation
    -> C++ OpenCV sequential code
    -> C++ OpenCV parallel code using PThreads

--> Utils
- Util: General purpose utility files, as well as some typedefs and constants.

## Makefile
The makefile included with this project allows to generate only specific
components (i.e. only the lexer, or only the parser), or to fully generate the project.
For building the complete project, just run "make all" under the project root.
To run the complete project, just run "make run" under the project root.
>>>>>>> Final commit
