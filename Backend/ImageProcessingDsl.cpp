#include "ImageProcessingDsl.h" 

namespace ImageProcessingDsl 
{
    // Construtor padrão que inicializa a imagem com um Mat vazio
    Image::Image() {
        this->image = cv::Mat();
    }

    // Constructor for creating an Image object from a file path
    Image::Image(std::string path) : path(path) 
    {
        this->image = cv::imread(path); // Carrega a imagem usando a função imread do OpenCV
        if (image.empty()) // Verifica se a imagem está vazia
            throw std::runtime_error("Não foi possível abrir ou encontrar a imagem!\n");
    }

    // Constructor for creating an Image object from an OpenCV Mat object
    Image::Image(cv::Mat img) 
    {
        this->image = img; // Assign the provided Mat object to the image member variable
    }

    // Method to get the ID of the image
    int Image::getId() 
    {
        return id; // Return the ID of the image
    }

    // Method to resize the image
    Image Image::resizeImage(int width, int height) 
    {
        cv::Mat resizedImage; // Create a Mat object to store the resized image
        cv::resize(image, resizedImage, cv::Size(width, height)); // Resize the image using OpenCV's resize function
        return Image(resizedImage); // Return a new Image object with the resized image
    }

    // Method to flip the image
    Image Image::flipImage(int flipCode) 
    {
        cv::Mat flippedImage; // Create a Mat object to store the flipped image
        cv::flip(image, flippedImage, flipCode); // Flip the image using OpenCV's flip function
        return Image(flippedImage); // Return a new Image object with the flipped image
    }

    // Method to rotate the image
    Image Image::rotateImage(double angle) 
    {
        cv::Mat rotatedImage; // Create a Mat object to store the rotated image
        cv::Point2f center((image.cols-1)/2.0, (image.rows-1)/2.0); // Calculate the rotation center
        cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0); // Get the rotation matrix
        cv::warpAffine(image, rotatedImage, rot, image.size()); // Rotate the image using OpenCV's warpAffine function
        return Image(rotatedImage); // Return a new Image object with the rotated image
    }

    // Method to get the image matrix
    cv::Mat Image::getImage() const 
    {
        return this->image; // Return the image matrix
    }

    // Method to set the image matrix
    void Image::setImage(cv::Mat img) 
    {
        this->image = img; // Set the image matrix
    }

    std::string Image::getImagePath() const 
    {
        return path;
    }

    // Method to display the image
    void Image::showImage() const 
    {
        cv::imshow("Image", image); // Display the image using OpenCV's imshow function
        cv::waitKey(0); // Wait indefinitely for a key press
        cv::destroyAllWindows(); // Close all OpenCV windows
    }

    // Operator overloading for image addition
    Image Image::operator+(const Image &other) 
    {
        cv::Mat resultImage; // Create a Mat object to store the result image
        cv::Mat tmp = this->getImage(); // Get the image matrix of the current object
        cv::resize(tmp, tmp, other.getImage().size()); // Resize the current image to match the size of the other image
        cv::add(tmp, other.getImage(), resultImage); // Add the two images using OpenCV's add function
        return Image(resultImage); // Return a new Image object with the result image
    }

    // Operator overloading for image subtraction
    Image Image::operator-(const Image &other) 
    {
        cv::Mat resultImage; // Create a Mat object to store the result image
        cv::Mat tmp = this->getImage(); // Get the image matrix of the current object
        cv::resize(tmp, tmp, other.getImage().size()); // Resize the current image to match the size of the other image
        cv::subtract(tmp, other.getImage(), resultImage); // Subtract the two images using OpenCV's subtract function
        return Image(resultImage); // Return a new Image object with the result image
    }

    // Operator overloading for image multiplication
    Image Image::operator*(const Image &other) 
    {
        cv::Mat resultImage; // Create a Mat object to store the result image
        cv::Mat tmp = this->getImage(); // Get the image matrix of the current object
        cv::resize(tmp, tmp, other.getImage().size()); // Resize the current image to match the size of the other image
        cv::multiply(tmp, other.getImage(), resultImage); // Multiply the two images using OpenCV's multiply function
        return Image(resultImage); // Return a new Image object with the result image
    }

    // Function loop that executes the function passed as parameter on each image in the array
    /* loop(images, numImages, &Image::resizeImage, 100, 100); // call example */
    void loop(Image images[], int numImages, Image (Image::*func)(int), int arg) 
    {
        for (int i = 0; i < numImages; ++i) 
            (images[i].*func)(arg); // Execute the function on the current image in the array
    }

    // Destructor for the Image class
    Image::~Image() {}

    // Destructor for the ImageOperation class
    ImageOperation::~ImageOperation() {}

    // Method to execute binarization
    cv::Mat Binarization::execute(const Image &input) const 
    {
        cv::Mat grayImage; // Create a Mat object to store the grayscale image
        cv::cvtColor(input.getImage(), grayImage, cv::COLOR_BGR2GRAY); // Convert the input image to grayscale
        return grayImage; // Return the binarized image
    }

    // Constructor for Blur class with parameters
    Blur::Blur(int mode, cv::Size size, double sigma) 
    {
        // Validate the provided size
        if(size.width <= 0 || size.height <= 0)
            throw std::invalid_argument("Invalid size. Must be Positive!\n"); 
        else if(size.width % 2 == 0 || size.height % 2 == 0)
            throw std::invalid_argument("Invalid size. Must be odd!\n"); 
        this->size = size; // Assign the provided size
        this->sigma = sigma; // Assign the provided sigma
        this->mode = mode; // Assign the provided mode
    }

    // Constructor for Blur class with kernel size
    Blur::Blur(int mode, int ksize) 
    {
        if (mode != MEDIAN_BLUR) // Check if mode is not median blur
        {
            throw std::invalid_argument("Invalid mode for this constructor!\n"); 
        }
        this->mode = mode; // Assign the provided mode
        this->ksize = ksize; // Assign the provided ksize
    }

    // Constructor for Blur class with kernel size and sigma
    Blur::Blur(int mode, int ksize, int sigma) 
    {   
        if (mode != BILATERAL_BLUR) // Check if mode is not bilateral blur
            throw std::invalid_argument("Invalid mode for this constructor!\n"); 
        this->mode = mode; // Assign the provided mode
        this->ksize = ksize; // Assign the provided ksize
        this->sigma = sigma; // Assign the provided sigma
    }

    // Static method to create an instance of Blur and execute the operation in one call
    Image ImageProcessingDsl::Blur::apply(const Image &input, int mode, const cv::Size &size, double sigma) 
    {
        Blur blur(mode, size, sigma); // Create an instance of Blur
        cv::Mat blurredMat = blur.execute(input); // Execute the blur operation and get the blurred image as an OpenCV matrix
        return Image(blurredMat); // Convert the OpenCV matrix to an Image object and return
    }


    // Method to execute blur operation
    cv::Mat Blur::execute(const Image &input) const 
    {
        cv::Mat blurredImage; // Create a Mat object to store the blurred image
        if(mode == GAUSSIAN_BLUR) // Check if mode is Gaussian blur
        {
            cv::GaussianBlur(input.getImage(), blurredImage, size, sigma); // Apply Gaussian blur using OpenCV's GaussianBlur function
        }
        else if(mode == MEDIAN_BLUR) // Check if mode is median blur
        {
            cv::medianBlur(input.getImage(), blurredImage, ksize); // Apply median blur using OpenCV's medianBlur function
        }
        else if(mode == BILATERAL_BLUR) // Check if mode is bilateral blur
        {
            cv::bilateralFilter(input.getImage(), blurredImage, ksize, sigma, sigma); // Apply bilateral blur using OpenCV's bilateralFilter function
        }
        return blurredImage; // Return the blurred image
    }

    // Constructor for Threshold class with parameters
    Threshold::Threshold(double threshold, double maxVal, int type) 
    {
        this->threshold = threshold; // Assign the provided threshold
        this->maxVal = maxVal; // Assign the provided maximum value
        this->type = type; // Assign the provided type
    }

    // Method to execute thresholding operation
    cv::Mat Threshold::execute(const Image &input) const 
    {
        cv::Mat thresholdedImage; // Create a Mat object to store the thresholded image
        cv::threshold(input.getImage(), thresholdedImage, threshold, maxVal, type); // Apply thresholding using OpenCV's threshold function
        return thresholdedImage; // Return the thresholded image
    }

    // Constructor for Countor class with parameters
    Countor::Countor(int mode, int method, cv::Scalar color) 
    {
        this->mode = mode; // Assign the provided mode
        this->method = method; // Assign the provided method
        this->color = color; // Assign the provided color
    }

    // Method to draw contours
    cv::Mat Countor::drawContours(const Image &input, const std::vector<std::vector<cv::Point>> &contours) const 
    {
        cv::Mat drawing = input.getImage().clone(); // Create a copy of the input image
        cv::drawContours(drawing, contours, -1, color, 2); // Draw contours on the image copy
        return drawing; // Return the image with contours drawn
    }

    // Method to execute contour detection
    cv::Mat Countor::execute(const Image &input) const 
    {
        // Converter a imagem para escala de cinza
        cv::Mat grayImage;
        cv::cvtColor(input.getImage(), grayImage, cv::COLOR_BGR2GRAY);

        // Aplicar um desfoque para suavizar a imagem e reduzir o ruído
        cv::GaussianBlur(grayImage, grayImage, cv::Size(5, 5), 0);

        // Detectar as bordas na imagem usando o algoritmo Canny
        cv::Mat edges;
        cv::Canny(grayImage, edges, 50, 150);

        // Encontrar os contornos na imagem
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(edges, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        // Desenhar os contornos na imagem original
        cv::Mat contourImage = cv::Mat::zeros(input.getImage().size(), CV_8UC3);
        cv::drawContours(contourImage, contours, -1, cv::Scalar(0, 255, 0), 2);

        return contourImage; // Retornar a imagem com os contornos desenhados
    }

    // Method to execute text recognition
    std::string TextRecognition::execute(const cv::Mat &input) const 
    {
        cv::Mat gray, binary;
        cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
        
        // Apply bilateral filtering for noise removal
        cv::Mat smoothed;
        cv::bilateralFilter(gray, smoothed, 5, 50, 50);

        // Adaptive thresholding
        cv::adaptiveThreshold(smoothed, binary, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY_INV, 11, 15);

        // Invert colors to prepare for OCR
        cv::bitwise_not(binary, binary);
        
        // Resize image to 300 DPI (optional)
        cv::Size newSize(input.cols * 300 / input.rows, 300);
        cv::resize(binary, binary, newSize);

        // Create Tesseract OCR object
        tesseract::TessBaseAPI ocr;
        ocr.Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
        ocr.SetPageSegMode(tesseract::PSM_AUTO);
        
        // Set image resolution to 300 DPI
        ocr.SetVariable("user_defined_dpi", "300");

        // Set image for OCR
        ocr.SetImage(binary.data, binary.cols, binary.rows, 1, binary.step);

        // Get recognized text
        char* outText = ocr.GetUTF8Text();
        std::string result(outText);
        
        delete[] outText;
        return result;
    }

    // Method to print recognized text
    void TextRecognition::printText(const std::string input)
    {
        std::cout << "\n" <<  input << std::endl; // Print the recognized text
    }
    
    // Constructor for the DSL class
    Dsl::Dsl() {}

    // Method to apply image operation
    cv::Mat Dsl::applyOperation(const Image &input, const ImageOperation &operation) const 
    {
        return operation.execute(input); // Execute the provided image operation
    }

    // Constructor for binary thresholding class
    BinaryThreshold::BinaryThreshold(double threshold, double maxVal, int type)
        : threshold(threshold), maxVal(maxVal), type(type) {}

    // Method to execute binary thresholding operation
    cv::Mat BinaryThreshold::execute(const Image &input) const
    {
        cv::Mat thresholdedImage; // Create a Mat object to store the thresholded image
        cv::threshold(input.getImage(), thresholdedImage, threshold, maxVal, type); // Apply thresholding using OpenCV's threshold function
        return thresholdedImage; // Return the thresholded image
    }

    // Constructor for BinaryInverseThreshold class with parameters
    BinaryInverseThreshold::BinaryInverseThreshold(double threshold, double maxVal) 
    {
        this->threshold = threshold; // Assign the provided threshold
        this->maxVal = maxVal; // Assign the provided maximum value
    }

    // Method to execute binary inverse thresholding operation
    cv::Mat BinaryInverseThreshold::execute(const Image &input) const 
    {
        cv::Mat thresholdedImage; // Create a Mat object to store the thresholded image
        cv::threshold(input.getImage(), thresholdedImage, threshold, maxVal, cv::THRESH_BINARY_INV); // Apply binary inverse thresholding using OpenCV's threshold function
        return thresholdedImage; // Return the thresholded image
    }

    // Constructor for OtsuThreshold class with parameters
    OtsuThreshold::OtsuThreshold(double maxValue) 
    {
        this->maxValue = maxValue; // Assign the provided maximum value
    }

    // Method to execute Otsu thresholding operation
    cv::Mat OtsuThreshold::execute(const Image &input) const 
    {
        cv::Mat grayImage; // Create a Mat object to store the grayscale image
        cv::cvtColor(input.getImage(), grayImage, cv::COLOR_BGR2GRAY); // Convert the input image to grayscale
        
        cv::Mat thresholdedImage; // Create a Mat object to store the thresholded image
        cv::threshold(grayImage, thresholdedImage, 0, maxValue, cv::THRESH_BINARY | cv::THRESH_OTSU); // Apply Otsu thresholding using OpenCV's threshold function
        return thresholdedImage; // Return the thresholded image
    }

}
