#ifndef _IMAGEPROCESSINGDSL_H_
#define _IMAGEPROCESSINGDSL_H_

#include <opencv2/opencv.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/highgui.hpp>
#include <string>
#include <vector>

namespace ImageProcessingDsl 
{
    #define GAUSSIAN_BLUR 1
    #define MEDIAN_BLUR 2
    #define BILATERAL_BLUR 3
    #define BINARY_THRESHOLD 4

    class Image;
    class ImageOperation;
    class Binarization;
    class Blur;
    class Threshold;
    class Countor;
    class Dsl;
    class BinaryThreshold;

    class Image
    {
    private:
        int id;
        cv::Mat image;
        std::string path;
    public:
        Image();
        Image(std::string path);
        Image(cv::Mat img);
        int getId();
        Image resizeImage(int width, int height);
        Image flipImage(int flipCode);
        Image rotateImage(double angle);
        cv::Mat getImage() const;
        std::string getImagePath() const;
        void setImage(cv::Mat img);
        void showImage() const;
        Image operator+(const Image &other);
        Image operator-(const Image &other);
        Image operator*(const Image &other);
        void loop(Image images[], int numImages, Image (Image::*func)(int), int arg);
        ~Image();
    };

    class ImageOperation
    {
    public:
        virtual cv::Mat execute(const Image &inputs) const = 0;
        virtual ~ImageOperation();
    };

    class Binarization : public ImageOperation
    {
    public:
        cv::Mat execute(const Image &input) const;
    };

    class Blur : public ImageOperation
    {
    private:
        cv::Size size;
        double sigma;
        int mode;
        int ksize;
    public:
        Blur(int mode, cv::Size size = cv::Size(5, 5), double sigma = 0);
        Blur(int mode, int ksize);
        Blur(int mode, int ksize, int sigma);
        cv::Mat execute(const Image &input) const;
        static Image apply(const Image &input, int mode, const cv::Size &size, double sigma);
    };

    class Threshold : public ImageOperation
    {
    private:
        double threshold;
        double maxVal;
        int type;
    public:
        Threshold(double threshold = 0, double maxVal = 255, int type = cv::THRESH_BINARY_INV | cv::THRESH_OTSU);
        cv::Mat execute(const Image &input) const;
    };

    class Countor : public ImageOperation
    {
    private:
        int mode;
        int method;
        cv::Scalar color;
    public:
        Countor(int mode = cv::RETR_EXTERNAL, int method = cv::CHAIN_APPROX_SIMPLE, cv::Scalar color = cv::Scalar(0, 0, 255));
        void findContours(const Image &input, std::vector<std::vector<cv::Point>> &contours, std::vector<cv::Vec4i> &hierarchy) const;
        cv::Mat drawContours(const Image &input, const std::vector<std::vector<cv::Point>> &contours) const;
        cv::Mat execute(const Image &input) const;
    };

    class TextRecognition
    {
    public:
        std::string execute(const cv::Mat &input) const;
        void printText(const std::string input);
    };

    class Dsl
    {
    public:
        Dsl();
        cv::Mat applyOperation(const Image &input, const ImageOperation &operation) const;
    };

    class BinaryThreshold : public ImageOperation
    {
    private:
        double threshold;
        double maxVal;
        int type;
    public:
        BinaryThreshold(double threshold = 0, double maxVal = 255, int type = cv::THRESH_BINARY_INV | cv::THRESH_OTSU);
        cv::Mat execute(const Image &input) const;
    };

    class BinaryInverseThreshold : public ImageOperation
    {
    private:
        double threshold;
        double maxVal;
    public:
        BinaryInverseThreshold(double threshold = 0, double maxVal = 255);
        cv::Mat execute(const Image &input) const override;
    };

    class OtsuThreshold : public ImageOperation
    {
    private:
        double maxValue;
    public:
        OtsuThreshold(double maxValue = 255);
        cv::Mat execute(const Image &input) const override;
    };
}

#endif