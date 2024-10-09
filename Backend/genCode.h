#ifndef GENCODE_CPP
#define GENCODE_CPP

#include "../Utils/utils.h"
#include "ImageProcessingDsl.h"

using namespace std;

void translateNode(Node* node, stringstream& code) ;
void checkFunc(Node* node, stringstream& code);

#endif