SET_MODE(SEQUENTIAL)

load (image,"Images/um.png")

image1 = countor(image)

show (image1)



{
SET_MODE(SEQUENTIAL)
    imagem1 = binarization(image)
    imagem2 = flip(imagem1)
    imagem3 = resize(1600,1080,imagem2)
    imagem4 = gaussianBlur(1,2,imagem3)
    textRecognition (textImg, stringText1)
    imagem_seq = countor(image)
    print(stringText1)
    show(imagem1)

SET_MODE(PARALLEL)
    imagem5 = binarization(image)
    imagem6 = flip(imagem5)
    imagem7 = resize(1600,1080,imagem6)
    imagem8 = gaussianBlur(1,2,imagem7)
    textRecognition (textImg, stringText2)
    imagem_par = countor(image)
    print(stringText2)
    show(imagem5)


    imagem1 = binarization(image1)
    imagem2 = flip(image2)
    imagem3 = resize(1600,1080,textImg)
    textRecognition (textImg, myVar)
    print (myVar)
    imagem4 = countor(image1)
    imagem5 = gaussianBlur(1,2,image1)
    imagem8 = binaryThreshold(127,image2)
    imagem9 = binaryInvThreshold(7,image1)
    imagem10 = otsuThreshold(8,image1)
    img1 = image1 + image2
    img2 = image1 - image2
    img3 = image1 * image2
    _my_array = [image1,image2,textImg]
    loop(_my_array,flip()) 
    testing_index = _my_array !! 2
    compile >> image2 >> binarization() >> flip() >> gaussianBlur(3,2) >> resize(640,400)
    show (image2)


SET_MODE(SEQUENTIAL)
    timer(on)
        image_seq = gaussianBlur(1,2,image1)
    timer(off)

SET_MODE(PARALLEL)
    timer(on)
        image_par = gaussianBlur(1,2,image1)
    timer(off)
    
}
