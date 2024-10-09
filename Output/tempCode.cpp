#include "../Backend/ImageProcessingDsl.h"
#include <iostream>
#include <pthread.h>
#include <chrono>
#include <vector>

int main() {
ImageProcessingDsl::Binarization binarization;
ImageProcessingDsl::Countor countor(cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE, cv::Scalar(0, 255, 0));
ImageProcessingDsl::TextRecognition textRecognition;

ImageProcessingDsl::Image image("Images/ESRG.png");

image = image.flipImage(1);
image = image.rotateImage(45);
image = image.resizeImage(640,400);
image.setImage(binarization.execute(image));

auto showImage0 = [&image]() -> void* {
image.showImage();
    return nullptr;
};
pthread_t show_thread0;
pthread_create(&show_thread0, nullptr, [](void* arg) { return (*static_cast<decltype(showImage0)*>(arg))(); }, &showImage0);
pthread_join(show_thread0, nullptr);
return 0;
}

