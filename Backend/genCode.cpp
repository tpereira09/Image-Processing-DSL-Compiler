#include <iostream>
#include <sstream>
#include <unordered_map>
#include <cstring>
#include <pthread.h>
#include "genCode.h"

using namespace std;

// function type for translation operations
using TranslationFunctionSeq = void (*)(Node*, stringstream&);
using TranslationFunctionPar = void (*)(Node*, stringstream&);

extern int numIdentifiers;
char *tempName;
int numThreads = 0;

enum genMode {
    SEQUENTIAL=0,
    PARALLEL
}mode;

// mapping of labels to corresponding translation functions
unordered_map<string, TranslationFunctionSeq> translationMapSeq = 
{
    // Timer operation translation
    {
        "Timer", 
        [](Node* node, stringstream& code) 
        {
            if (strcmp(node->children[0]->label, "On") == 0)
                code << "auto startseq = std::chrono::high_resolution_clock::now();\n";
            else if (strcmp(node->children[0]->label, "Off") == 0)
            {
                code << "auto endseq = std::chrono::high_resolution_clock::now();\n";
                code << "auto duration_seq = std::chrono::duration_cast<std::chrono::microseconds>(endseq - startseq).count();\n";
                code << "std::cout << \"Sequential execution time: \" << duration_seq << \" us\" << std::endl;\n";
            }
            else 
                return;
        }
    },
    // Load operation translation
    {
        "Load", 
        [](Node* node, stringstream& code) 
        {
            code << "ImageProcessingDsl::Image " << node->children[0]->label << "(" << node->children[1]->label << ");\n";
            code << "\n";
        }
    },
    // Show operation translation
    {
        "Show", 
        [](Node* node, stringstream& code) 
        {
            code << node->children[0]->label << ".showImage();\n";
            code << "\n";
        }
    },
    // Rotate operation translation
    {
        "Rotate", 
        [](Node* node, stringstream& code) 
        {
            code << node->children[1]->label << ".rotateImage(" << node->children[0]->value << ");\n";
            code << "\n";
        }
    },
    // Resize operation translation
    {
        "Resize", 
        [](Node* node, stringstream& code) 
        {
            code << node->children[2]->label << ".resizeImage(" << node->children[0]->value << ", " << node->children[1]->value << ");\n";
            code << "\n";
        }
    },
    // Flip operation translation
    {
        "Flip", 
        [](Node* node, stringstream& code) 
        {
            code << node->children[0]->label << ".flipImage(1);\n";
            code << "\n";
        }
    },
    // Assignment operation translation
    {
        "Assignment", 
        [](Node* node, stringstream& code) 
        {
            code << "ImageProcessingDsl::Image " << node->children[0]->label << " = ";
        }
    },
    // RecognizeText operation translation
    {
        "RecognizeText", 
        [](Node* node, stringstream& code) 
        {
            code << "std::string " << node->children[1]->label << " = textRecognition.execute(" << node->children[0]->label << ".getImage());\n";
            code << "\n";
        }
    },
    // Print operation translation
    {
        "Print", 
        [](Node* node, stringstream& code) 
        {
            code << "std::cout << std::endl;";
            code << "std::cout << \"Recognized Text: \" << " << node->children[0]->label << " << std::endl;\n";
            code << "\n";
        }
    },
    // Binarization operation translation
    {
        "Binarization", 
        [](Node* node, stringstream& code) 
        {
            code << "binarization.execute(" << node->children[0]->label << ");\n";
            code << "\n";
        }
    },
    // Contour detection operation translation
    {
        "Countor", 
        [](Node* node, stringstream& code) 
        {
            code << "countor.execute(" << node->children[0]->label << ");\n";
            code << "\n";
        }
    },
    // Gaussian Blur operation translation
    {
        "GaussianBlur", 
        [](Node* node, stringstream& code) 
        {
            code << "ImageProcessingDsl::Blur::apply(" << node->children[2]->label << ", 1, cv::Size(" << node->children[0]->value << ", " << node->children[0]->value << "), " << node->children[1]->value << ");\n";
            code << "\n";
        }
    },
    // Bilateral Blur operation translation
    {
        "BilateralBlur", 
        [](Node* node, stringstream& code) 
        {
            code << "ImageProcessingDsl::Blur::apply(" << node->children[2]->label << ", 3, cv::Size(" << node->children[0]->value << ", " << node->children[0]->value << "), " << node->children[1]->value << ");\n";
            code << "\n";
        }
    },
    // Median Blur operation translation
    {
        "MedianBlur", 
        [](Node* node, stringstream& code) 
        {
            code << "ImageProcessingDsl::Blur::apply(" << node->children[1]->label << ", 2, cv::Size(" << node->children[0]->value << ", " << node->children[0]->value << "));\n";
            code << "\n";
        }
    },
    // Binary Threshold operation translation
    {
        "BinaryThreshold", 
        [](Node* node, stringstream& code) 
        {
            code << "ImageProcessingDsl::BinaryThreshold(" << node->children[0]->value << ", 255, cv::THRESH_BINARY).execute("<< node->children[1]->label <<");\n";
            code << "\n";
        }
    },
    // Binary Inverse Threshold operation translation
    {
        "BinaryInverseThreshold", 
        [](Node* node, stringstream& code) 
        {
            code << "ImageProcessingDsl::BinaryInverseThreshold(" << node->children[0]->value << ", 255).execute("<< node->children[1]->label <<");\n";
            code << "\n";
        }
    },
    // Otsu Threshold operation translation
    {
        "OtsuThreshold", 
        [](Node* node, stringstream& code) 
        {
            code << "ImageProcessingDsl::OtsuThreshold(" << node->children[0]->value << ").execute("<< node->children[1]->label <<");\n";
            code << "\n";
        }
    },
    // Addition operation translation
    {
        "Addition", 
        [](Node* node, stringstream& code) 
        {
            code << node->children[0]->label << " + " << node->children[1]->label << ";\n";
            code << "\n";
        }
    },
    // Subtraction operation translation
    {
        "Subtraction", 
        [](Node* node, stringstream& code) 
        {
            code << node->children[0]->label << " - " << node->children[1]->label << ";\n";
            code << "\n";
        }
    },
    // Multiplication operation translation
    {
        "Multiplication", 
        [](Node* node, stringstream& code) 
        {
            code << node->children[0]->label << " * " << node->children[1]->label << ";\n";
            code << "\n";
        }
    },
    // Indexing operation translation (not implemented)
    {
        "Indexing", 
        [](Node* node, stringstream& code) 
        {
            code << node->children[0]->label << "[" << node->children[1]->value << "];\n";
        }
    },
    {
        "Array", 
        [](Node* node, stringstream& code) 
        {
            code << "std::vector<ImageProcessingDsl::Image> " << node->children[0]->label << " = {";
            for(int i=0; i < node->children[1]->num_children; i++)
            {
                code << node->children[1]->children[i]->label;
                if (i<2)
                    code << " ,";
            }
            code << "};\n";
        }
    },
    {
        "Loop", 
        [](Node* node, stringstream& code) 
        {
            code << "for (int i = 0; i < "<< numIdentifiers <<"; i++){\n"; 
            checkFunc(node,code);
            code << "}\n";
        }
    },
    // Translation Mode
    {
        "Mode", [](Node* node, stringstream& code) 
        {
            if (strcmp(node->children[0]->label, "Sequential") == 0)
                mode = SEQUENTIAL;
            else if (strcmp(node->children[0]->label, "Parallel") == 0)
                mode = PARALLEL;
            else 
                mode = SEQUENTIAL;
        }
    },
    {
        "Compile", 
        [](Node* node, stringstream& code) 
        {
            int j=0;
            std::string func;
            for(int i=0;i<node->children[1]->num_children;i++)
            {  
                func = node->children[1]->children[j]->label;
                if (func == "FlipLoop") 
                {
                    code << node->children[0]->label <<" = " << node->children[0]->label << ".flipImage(1);\n";
                } 
                else if (func == "ResizeLoop") 
                {
                    code << node->children[0]->label <<" = " << node->children[0]->label <<".resizeImage(" << node->children[1]->children[j]->children[0]->value << "," << node->children[1]->children[j]->children[1]->value << ");\n";
                } 
                else if (func == "RotateLoop") 
                {
                    code << node->children[0]->label <<" = " << node->children[0]->label <<".rotateImage(" << node->children[1]->children[j]->children[0]->value << ");\n";
                } 
                else if (func == "BinarizationLoop") 
                {
                    code << node->children[0]->label << ".setImage(binarization.execute(" << node->children[0]->label <<"));\n";
                }
                else if (func == "CountorLoop") 
                {
                    code << node->children[0]->label <<".setImage(countor.execute(" << node->children[0]->label <<"));\n";
                }
                else if (func == "GaussianBlurLoop") 
                {
                    code << node->children[0]->label << ".setImage(ImageProcessingDsl::Blur::apply(" << node->children[0]->label << ", 1, cv::Size(5, 5), 0).getImage());\n";
                }
                else if (func == "BilateralBlurLoop") 
                {
                    code << node->children[0]->label << ".setImage(ImageProcessingDsl::Blur::apply(" << node->children[0]->label << ", 3, cv::Size(5, 5), 0).getImage());\n";
                }
                else if (func == "MedianBlurLoop") 
                {
                    code << node->children[0]->label << ".setImage(ImageProcessingDsl::Blur::apply(" << node->children[0]->label << ", 2, cv::Size(5, 5), 0).getImage());\n";
                }
                else if (func == "BinaryThresholdLoop") 
                {
                    code << node->children[0]->label << ".setImage(ImageProcessingDsl::BinaryThreshold(" << node->children[1]->children[j]->children[0]->value << ", 255, cv::THRESH_BINARY).execute(" << node->children[0]->label << "));\n";
                }
                else if (func == "BinaryInverseThresholdLoop") 
                {
                    code << node->children[0]->label << ".setImage(ImageProcessingDsl::BinaryInverseThreshold(" << node->children[1]->children[j]->children[0]->value << ", 255).execute(" << node->children[0]->label << "));\n";
                }
                else if (func == "OtsuThresholdLoop") 
                {
                    code << node->children[0]->label << ".setImage(ImageProcessingDsl::OtsuThreshold(" << node->children[1]->children[j]->children[0]->value << ").execute(" << node->children[0]->label << "));\n";
                }
                else 
                {
                    std::cout << "Error function not supported!\n";
                }
                j++;
            }
        }
    },
    // CommandList translation (no action)
    {
        "CommandList", [](Node* node, stringstream& code) {}
    },
    // Command translation (no action)
    {
        "Command", [](Node* node, stringstream& code) {}
    }
};

// mapping of labels to corresponding translation functions
unordered_map<string, TranslationFunctionPar> translationMapPar = 
{
    // Timer operation translation
    {
        "Timer", 
        [](Node* node, stringstream& code) 
        {
            if (strcmp(node->children[0]->label, "On") == 0)
                code << "auto startpar = std::chrono::high_resolution_clock::now();\n";
            else if (strcmp(node->children[0]->label, "Off") == 0)
            {
                code << "auto endpar = std::chrono::high_resolution_clock::now();\n";
                code << "auto duration_par = std::chrono::duration_cast<std::chrono::microseconds>(endpar - startpar).count();\n";
                code << "std::cout << \"Parallel execution time: \" << duration_par << \" us\" << std::endl;\n";
            }
            else 
                return;
        }
    },
    // Load operation translation
    {
        "Load", 
        [](Node* node, stringstream& code) 
        {
            code << "ImageProcessingDsl::Image " << node->children[0]->label << "(" << node->children[1]->label << ");\n";
            code << "\n";
        }
    },
    // Show operation translation
    {
        "Show", 
        [](Node* node, stringstream& code) 
        {
            code << endl;
            code << "auto showImage" << numThreads << " = [&" << node->children[0]->label << "]() -> void* {\n";
            code << node->children[0]->label << ".showImage();\n";
            code << "    return nullptr;\n";
            code << "};\n";
            code << "pthread_t show_thread" << numThreads << ";\n";
            code << "pthread_create(&show_thread" << numThreads << ", nullptr, [](void* arg) { return (*static_cast<decltype(showImage" << numThreads << ")*>(arg))(); }, &showImage" << numThreads << ");\n";
            code << "pthread_join(show_thread" << numThreads << ", nullptr);\n";
            numThreads++;
        }
    },
    // Rotate operation translation
    {
        "Rotate", 
        [](Node* node, stringstream& code) 
        {
            code << "auto rotateImage" << numThreads << " = [&" << node->children[1]->label << ", &" << tempName <<"]() -> void* {\n";
            code << "    " << tempName << "=" << node->children[1]->label << ".rotateImage(" << node->children[0]->value << ");\n";
            code << "    return nullptr;\n";
            code << "};\n";
            code << "pthread_t rotate_thread" << numThreads << ";\n";
            code << "pthread_create(&rotate_thread" << numThreads << ", nullptr, [](void* arg) { return (*static_cast<decltype(rotateImage" << numThreads << ")*>(arg))(); }, &rotateImage" << numThreads << ");\n";
            code << "pthread_join(rotate_thread" << numThreads << ", nullptr);\n";
            numThreads++;
        }
    },
    // Resize operation translation
    {
        "Resize", 
        [](Node* node, stringstream& code) 
        {
            code << "auto resizeImage" << numThreads << " = [&" << node->children[2]->label << ", &" << tempName <<"]() -> void* {\n";
            code << "    " << tempName << "=" << node->children[2]->label << ".resizeImage(" << node->children[0]->value << ", " << node->children[1]->value << ");\n";
            code << "    return nullptr;\n";
            code << "};\n";
            code << "pthread_t resize_thread" << numThreads << ";\n";
            code << "pthread_create(&resize_thread" << numThreads << ", nullptr, [](void* arg) { return (*static_cast<decltype(resizeImage" << numThreads << ")*>(arg))(); }, &resizeImage" << numThreads << ");\n";
            code << "pthread_join(resize_thread" << numThreads << ", nullptr);\n";
            numThreads++;
        }
    },
    // Flip operation translation
    {
        "Flip", 
        [](Node* node, stringstream& code) 
        {
            code << "auto flipImage" << numThreads << " = [&" << node->children[0]->label << ", &" << tempName <<"]() -> void* {\n";
            code << "    " << tempName << "=" << node->children[0]->label << ".flipImage(1);\n";
            code << "    return nullptr;\n";
            code << "};\n";
            code << "pthread_t flip_thread" << numThreads << ";\n";
            code << "pthread_create(&flip_thread" << numThreads << ", nullptr, [](void* arg) { return (*static_cast<decltype(flipImage" << numThreads << ")*>(arg))(); }, &flipImage" << numThreads << ");\n";
            code << "pthread_join(flip_thread" << numThreads << ", nullptr);\n";
            numThreads++;
        }
    },
    // Assignment operation translation
    {
        "Assignment", 
        [](Node* node, stringstream& code) 
        {
            code << endl;
            tempName = node->children[0]->label;
            code << "ImageProcessingDsl::Image " << tempName << ";\n";
        }
    },
    // RecognizeText operation translation
    {
        "RecognizeText", 
        [](Node* node, stringstream& code) 
        {
            code << endl;
            code << "std::string " << node->children[1]->label << ";\n";
            code << "auto recognizeText" << numThreads << " = [&" << node->children[0]->label << ", &" << node->children[1]->label <<", &textRecognition]() -> void* {\n";
            code << node->children[1]->label << " = textRecognition.execute(" << node->children[0]->label << ".getImage());\n";
            code << "    return nullptr;\n";
            code << "};\n";
            code << "pthread_t recognize_thread" << numThreads << ";\n";
            code << "pthread_create(&recognize_thread" << numThreads << ", nullptr, [](void* arg) { return (*static_cast<decltype(recognizeText" << numThreads << ")*>(arg))(); }, &recognizeText" << numThreads << ");\n";
            code << "pthread_join(recognize_thread" << numThreads << ", nullptr);\n";
            numThreads++;
        }
    },
    // Print operation translation
    {
        "Print", 
        [](Node* node, stringstream& code) 
        {
            code << endl;
            code << "auto printText" << numThreads << " = [&" << node->children[0]->label << "]() -> void* {\n";
            code << "    std::cout << std::endl;\n";
            code << "    std::cout << \"Recognized Text: \" << std::endl << " << node->children[0]->label << " << std::endl;\n";
            code << "    return nullptr;\n";
            code << "};\n";
            code << "pthread_t print_thread" << numThreads << ";\n";
            code << "pthread_create(&print_thread" << numThreads << ", nullptr, [](void* arg) { return (*static_cast<decltype(printText" << numThreads << ")*>(arg))(); }, &printText" << numThreads << ");\n";
            code << "pthread_join(print_thread" << numThreads << ", nullptr);\n";
            numThreads++;
        }
    },
    // Binarization operation translation
    {
        "Binarization", 
        [](Node* node, stringstream& code) 
        {
            code << "auto binarizeImage" << numThreads << " = [&" << node->children[0]->label << ", &" << tempName <<", &binarization]() -> void* {\n";
            code << "    " << tempName << "=" << "binarization.execute(" << node->children[0]->label << ");\n";
            code << "    return nullptr;\n";
            code << "};\n";
            code << "pthread_t binarize_thread" << numThreads << ";\n";
            code << "pthread_create(&binarize_thread" << numThreads << ", nullptr, [](void* arg) { return (*static_cast<decltype(binarizeImage" << numThreads << ")*>(arg))(); }, &binarizeImage" << numThreads << ");\n";
            code << "pthread_join(binarize_thread" << numThreads << ", nullptr);\n";
            numThreads++;
        }
    },
    // Contour detection operation translation
    {
        "Countor", 
        [](Node* node, stringstream& code) 
        {
            code << "auto detectContour" << numThreads << " = [&" << node->children[0]->label << ", &" << tempName <<", &countor]() -> void* {\n";
            code << "    " << tempName << "=" << "countor.execute(" << node->children[0]->label << ");\n";
            code << "    return nullptr;\n";
            code << "};\n";
            code << "pthread_t contour_thread" << numThreads << ";\n";
            code << "pthread_create(&contour_thread" << numThreads << ", nullptr, [](void* arg) { return (*static_cast<decltype(detectContour" << numThreads << ")*>(arg))(); }, &detectContour" << numThreads << ");\n";
            code << "pthread_join(contour_thread" << numThreads << ", nullptr);\n";
            numThreads++;
        }
    },
    // Gaussian Blur operation translation
    {
        "GaussianBlur", 
        [](Node* node, stringstream& code) 
        {
            code << "auto applyGaussianBlur" << numThreads << " = [&" << node->children[2]->label << ", &" << tempName <<"]() -> void* {\n";
            code << "    " << tempName << "=" << "ImageProcessingDsl::Blur::apply(" << node->children[2]->label << ", 1, cv::Size(" << node->children[0]->value << ", " << node->children[0]->value << "), " << node->children[1]->value << ");\n";
            code << "    return nullptr;\n";
            code << "};\n";
            code << "pthread_t gaussian_thread" << numThreads << ";\n";
            code << "pthread_create(&gaussian_thread" << numThreads << ", nullptr, [](void* arg) { return (*static_cast<decltype(applyGaussianBlur" << numThreads << ")*>(arg))(); }, &applyGaussianBlur" << numThreads << ");\n";
            code << "pthread_join(gaussian_thread" << numThreads << ", nullptr);\n";
            numThreads++;
        }
    },
    // Bilateral Blur operation translation
    {
        "BilateralBlur", 
        [](Node* node, stringstream& code) 
        {
            code << "auto applyBilateralBlur" << numThreads << " = [&" << node->children[2]->label << ", &" << tempName <<"]() -> void* {\n";
            code << "    " << tempName << "=" << "ImageProcessingDsl::Blur::apply(" << node->children[2]->label << ", 3, cv::Size(" << node->children[0]->value << ", " << node->children[0]->value << "), " << node->children[1]->value << ");\n";
            code << "    return nullptr;\n";
            code << "};\n";
            code << "pthread_t bilateral_thread" << numThreads << ";\n";
            code << "pthread_create(&bilateral_thread" << numThreads << ", nullptr, [](void* arg) { return (*static_cast<decltype(applyBilateralBlur" << numThreads << ")*>(arg))(); }, &applyBilateralBlur" << numThreads << ");\n";
            code << "pthread_join(bilateral_thread" << numThreads << ", nullptr);\n";
            numThreads++;
        }
    },
    // Median Blur operation translation
    {
        "MedianBlur", 
        [](Node* node, stringstream& code) 
        {
            code << "auto applyMedianBlur" << numThreads << " = [&" << node->children[1]->label << ", &" << tempName <<"]() -> void* {\n";
            code << "    " << tempName << "=" << "ImageProcessingDsl::Blur::apply(" << node->children[1]->label << ", 2, cv::Size(" << node->children[0]->value << ", " << node->children[0]->value << "));\n";
            code << "    return nullptr;\n";
            code << "};\n";
            code << "pthread_t median_thread" << numThreads << ";\n";
            code << "pthread_create(&median_thread" << numThreads << ", nullptr, [](void* arg) { return (*static_cast<decltype(applyMedianBlur" << numThreads << ")*>(arg))(); }, &applyMedianBlur" << numThreads << ");\n";
            code << "pthread_join(median_thread" << numThreads << ", nullptr);\n";
            numThreads++;
        }
    },
    // Binary Threshold operation translation
    {
        "BinaryThreshold", 
        [](Node* node, stringstream& code) 
        {
            code << "auto applyBinaryThreshold" << numThreads << " = [&" << node->children[1]->label << ", &" << tempName <<"]() -> void* {\n";
            code << "    " << tempName << "=" << "ImageProcessingDsl::BinaryThreshold(" << node->children[0]->value << ", 255, cv::THRESH_BINARY).execute("<< node->children[1]->label <<");\n";
            code << "    return nullptr;\n";
            code << "};\n";
            code << "pthread_t binary_threshold_thread" << numThreads << ";\n";
            code << "pthread_create(&binary_threshold_thread" << numThreads << ", nullptr, [](void* arg) { return (*static_cast<decltype(applyBinaryThreshold" << numThreads << ")*>(arg))(); }, &applyBinaryThreshold" << numThreads << ");\n";
            code << "pthread_join(binary_threshold_thread" << numThreads << ", nullptr);\n";
            numThreads++;
        }
    },
    // Binary Inverse Threshold operation translation
    {
        "BinaryInverseThreshold", 
        [](Node* node, stringstream& code) 
        {
            code << "auto applyBinaryInverseThreshold" << numThreads << " = [&" << node->children[1]->label << ", &" << tempName <<"]() -> void* {\n";
            code << "    " << tempName << "=" << "ImageProcessingDsl::BinaryInverseThreshold(" << node->children[0]->value << ", 255).execute("<< node->children[1]->label <<");\n";
            code << "    return nullptr;\n";
            code << "};\n";
            code << "pthread_t binary_inverse_thread" << numThreads << ";\n";
            code << "pthread_create(&binary_inverse_thread" << numThreads << ", nullptr, [](void* arg) { return (*static_cast<decltype(applyBinaryInverseThreshold" << numThreads << ")*>(arg))(); }, &applyBinaryInverseThreshold" << numThreads << ");\n";
            code << "pthread_join(binary_inverse_thread" << numThreads << ", nullptr);\n";
            numThreads++;
        }
    },
    // Otsu Threshold operation translation
    {
        "OtsuThreshold", 
        [](Node* node, stringstream& code) 
        {
            code << "auto applyOtsuThreshold" << numThreads << " = [&" << node->children[1]->label << ", &" << tempName <<"]() -> void* {\n";
            code << "    " << tempName << "=" << "ImageProcessingDsl::OtsuThreshold(" << node->children[0]->value << ").execute("<< node->children[1]->label <<");\n";
            code << "    return nullptr;\n";
            code << "};\n";
            code << "pthread_t otsu_thread" << numThreads << ";\n";
            code << "pthread_create(&otsu_thread" << numThreads << ", nullptr, [](void* arg) { return (*static_cast<decltype(applyOtsuThreshold" << numThreads << ")*>(arg))(); }, &applyOtsuThreshold" << numThreads << ");\n";
            code << "pthread_join(otsu_thread" << numThreads << ", nullptr);\n";
            numThreads++;
        }
    },
    // Addition operation translation
    {
        "Addition", 
        [](Node* node, stringstream& code) 
        {
            code << node->children[0]->label << " + " << node->children[1]->label << ";\n";
        }
    },
    // Subtraction operation translation
    {
        "Subtraction", 
        [](Node* node, stringstream& code) 
        {
            code << node->children[0]->label << " - " << node->children[1]->label << ";\n";
        }
    },
    // Multiplication operation translation
    {
        "Multiplication", 
        [](Node* node, stringstream& code) 
        {
            code << node->children[0]->label << " * " << node->children[1]->label << ";\n";
        }
    },
    // Indexing operation translation 
    {
        "Indexing", 
        [](Node* node, stringstream& code) 
        {
            code << tempName << "=" << node->children[0]->label << "[" << node->children[1]->value << "];\n";
        }
    },
    {
        "Array", 
        [](Node* node, stringstream& code) 
        {
            code << "std::vector<ImageProcessingDsl::Image> " << node->children[0]->label << " = {";
            for(int i=0; i < node->children[1]->num_children; i++)
            {
                code << node->children[1]->children[i]->label;
                if (i<2)
                    code << " ,";
            }
            code << "};\n";
        }
    },
    {
        "Loop", 
        [](Node* node, stringstream& code) 
        {
            code << "for (int i = 0; i < "<< numIdentifiers <<"; i++){"; 
            checkFunc(node,code);
            code << "}\n";
        }
    },
    {
        "Compile", 
        [](Node* node, stringstream& code) 
        {
            int j=0;
            std::string func;
            for(int i=0;i<node->children[1]->num_children;i++)
            {  
                func = node->children[1]->children[j]->label;
                if (func == "FlipLoop") 
                {
                    code << node->children[0]->label <<" = " << node->children[0]->label << ".flipImage(1);\n";
                } 
                else if (func == "ResizeLoop") 
                {
                    code << node->children[0]->label <<" = " << node->children[0]->label <<".resizeImage(" << node->children[1]->children[j]->children[0]->value << "," << node->children[1]->children[j]->children[1]->value << ");\n";
                } 
                else if (func == "RotateLoop") 
                {
                    code << node->children[0]->label <<" = " << node->children[0]->label <<".rotateImage(" << node->children[1]->children[j]->children[0]->value << ");\n";
                } 
                else if (func == "BinarizationLoop") 
                {
                    code << node->children[0]->label << ".setImage(binarization.execute(" << node->children[0]->label <<"));\n";
                }
                else if (func == "CountorLoop") 
                {
                    code << node->children[0]->label <<".setImage(countor.execute(" << node->children[0]->label <<"));\n";
                }
                else if (func == "GaussianBlurLoop") 
                {
                    code << node->children[0]->label << ".setImage(ImageProcessingDsl::Blur::apply(" << node->children[0]->label << ", 1, cv::Size(5, 5), 0).getImage());\n";
                }
                else if (func == "BilateralBlurLoop") 
                {
                    code << node->children[0]->label << ".setImage(ImageProcessingDsl::Blur::apply(" << node->children[0]->label << ", 3, cv::Size(5, 5), 0).getImage());\n";
                }
                else if (func == "MedianBlurLoop") 
                {
                    code << node->children[0]->label << ".setImage(ImageProcessingDsl::Blur::apply(" << node->children[0]->label << ", 2, cv::Size(5, 5), 0).getImage());\n";
                }
                else if (func == "BinaryThresholdLoop") 
                {
                    code << node->children[0]->label << ".setImage(ImageProcessingDsl::BinaryThreshold(" << node->children[1]->children[j]->children[0]->value << ", 255, cv::THRESH_BINARY).execute(" << node->children[0]->label << "));\n";
                }
                else if (func == "BinaryInverseThresholdLoop") 
                {
                    code << node->children[0]->label << ".setImage(ImageProcessingDsl::BinaryInverseThreshold(" << node->children[1]->children[j]->children[0]->value << ", 255).execute(" << node->children[0]->label << "));\n";
                }
                else if (func == "OtsuThresholdLoop") 
                {
                    code << node->children[0]->label << ".setImage(ImageProcessingDsl::OtsuThreshold(" << node->children[1]->children[j]->children[0]->value << ").execute(" << node->children[0]->label << "));\n";
                }
                else 
                {
                    std::cout << "Error function not supported!\n";
                }
                j++;
            }
        }
    },
    // Translation Mode
    {
        "Mode", [](Node* node, stringstream& code) 
        {
            if (strcmp(node->children[0]->label, "Sequential") == 0)
                mode = SEQUENTIAL;
            else if (strcmp(node->children[0]->label, "Parallel") == 0)
                mode = PARALLEL;
            else 
                mode = SEQUENTIAL;
        }
    },
    // CommandList translation (no action)
    {
        "CommandList", [](Node* node, stringstream& code) {}
    },
    // Command translation (no action)
    {
        "Command", [](Node* node, stringstream& code) {}
    }
};

// function to translate a node in the AST
void translateNode(Node* node, stringstream& code) 
{
    // if the node is null return 
    if (node == nullptr) 
        return;

    // check if the translation mode is sequential
    if (mode == SEQUENTIAL)
    {
        // find the node label in the sequential translation map
        auto it = translationMapSeq.find(node->label); 
        if (it != translationMapSeq.end()) 
            it->second(node, code);
        // if the node has children process them recursively
        if (node->num_children > 0 && node->children != nullptr) 
        {
            for (int i = 0; i < node->num_children; ++i) 
            {
                translateNode(node->children[i], code); // recursively translate each child node
            }
        }
    }
    // check if the translation mode is parallel
    else if (mode == PARALLEL)
    {
        // find the node label in the parallel translation map
        auto it = translationMapPar.find(node->label); 
        if (it != translationMapPar.end()) 
            it->second(node, code);
        // if the node has children process them recursively
        if (node->num_children > 0 && node->children != nullptr) 
        {
            for (int i = 0; i < node->num_children; ++i) 
            {
                translateNode(node->children[i], code); // recursively translate each child node
            }
        }
    }
    else 
        cout << "\n\nerror -> no mode selected <- \n\n"; // if no valid translation mode is selected print an error message
}


void checkFunc(Node* node, stringstream& code)
{
    std::string func = node->children[1]->label;

    if (func == "FlipLoop") 
    {
        code << node->children[0]->label <<"[i] = " << node->children[0]->label <<"[i].flipImage(1);\n";
    } 
    else if (func == "ResizeLoop") 
    {
        code << node->children[0]->label <<"[i] = " << node->children[0]->label <<"[i].resizeImage(" << node->children[1]->children[0]->value << "," << node->children[1]->children[1]->value << ");\n";
    } 
    else if (func == "RotateLoop") 
    {
        code << node->children[0]->label <<"[i] = " << node->children[0]->label <<"[i].rotateImage(" << node->children[1]->children[0]->value << ");\n";
    } 
    else if (func == "ShowLoop")
    {
        code << node->children[0]->label << "[i].showImage();\n";
    }
    else if (func == "BinarizationLoop") 
    {
        code << node->children[0]->label <<"[i].setImage(binarization.execute(" << node->children[0]->label <<"[i]));\n";
    }
    else if (func == "CountorLoop") 
    {
        code << node->children[0]->label <<"[i].setImage(countor.execute(" << node->children[0]->label <<"[i]));\n";
    }
    else if (func == "GaussianBlurLoop") 
    {
        code << node->children[0]->label << "[i].setImage(ImageProcessingDsl::Blur::apply(" << node->children[0]->label << "[i], 1, cv::Size(5, 5), 0).getImage());\n";
    }
    else if (func == "BilateralBlurLoop") 
    {
        code << node->children[0]->label << "[i].setImage(ImageProcessingDsl::Blur::apply(" << node->children[0]->label << "[i], 3, cv::Size(5, 5), 0).getImage());\n";
    }
    else if (func == "MedianBlurLoop") 
    {
        code << node->children[0]->label << "[i].setImage(ImageProcessingDsl::Blur::apply(" << node->children[0]->label << "[i], 2, cv::Size(5, 5), 0).getImage());\n";
    }
    else if (func == "BinaryThresholdLoop") 
    {
        code << node->children[0]->label << "[i].setImage(ImageProcessingDsl::BinaryThreshold(" << node->children[1]->children[0]->value << ", 255, cv::THRESH_BINARY).execute(" << node->children[0]->label << "[i]));\n";
    }
    else if (func == "BinaryInverseThresholdLoop") 
    {
        code << node->children[0]->label << "[i].setImage(ImageProcessingDsl::BinaryInverseThreshold(" << node->children[1]->children[0]->value << ", 255).execute(" << node->children[0]->label << "[i]));\n";
    }
    else if (func == "OtsuThresholdLoop") 
    {
        code << node->children[0]->label << "[i].setImage(ImageProcessingDsl::OtsuThreshold(" << node->children[1]->children[0]->value << ").execute(" << node->children[0]->label << "[i]));\n";
    }
    else 
    {
        std::cout << "Error function not supported!\n";
    }
}