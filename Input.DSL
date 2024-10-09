SET_MODE(SEQUENTIAL) { setting the code generation to sequencial processing mode }

{
    load (image,"Images/um.png")
    imagem1 = flip(image)
    imagem2 = resize(1600,1080,image)
    imagem3 = gaussianBlur(5,4,image)
    imagem4 = binarization(image)
    show (image)
    show (imagem1)
    show (imagem2)
    show (imagem3)
    show (imagem4)
}
    
                    {   COUNTOR DETECTION   }
{
    load (image,"Images/um.png") 
    show (image) 
    image1 = countor(image) 
    show (image1)
}

                    {   TEXT RECOGNITION   }
{
    load (helloImg,"Images/hello.png")
    show (helloImg) 
    textRecognition (helloImg, stringText) 
    print (stringText) 
}

                    {   ARRAY MANIPULATION  }
{
    load (imagem1,"Images/um.png")
    load (imagem2,"Images/ESRG.png")
    load (imagem3,"Images/EEIC.jpg")
    _array1 = [imagem1,imagem2,imagem3]
    imagem4 = _array1 !! 2
    show (imagem4)
    loop (_array1,rotate (180))
    loop (_array1,resize(800,600))
    loop (_array1,show())
}

SET_MODE(PARALLEL) { setting the code generation to parallel processing mode }

                    {   OPERATIONS PIPELINE  }
{
    load (image,"Images/ESRG.png")              
    compile >> image >> flip() >> rotate(45) >> resize(640,400) >> binarization()
    show (image)
}