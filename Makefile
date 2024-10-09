all: setup lexer parser src

setup:
	mkdir -p Output

lexer: setup
	flex -o Output/lex.yy.c Frontend/Scanner/LexScanner.l

parser: setup
	bison -dv -o Output/parser.tab.c Frontend/Parser/parser.y

src: setup lexer parser
	g++ -c -o Output/genCode.o Backend/genCode.cpp -I/usr/local/include/opencv4 -I/usr/include/tesseract -I/usr/include/clang -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -ltesseract -pthread
	g++ -o Output/myComp Utils/utils.c Output/parser.tab.c Output/lex.yy.c Frontend/Semantic/semantic.c main.c Output/genCode.o -lstdc++ -I/usr/local/include/opencv4 -I/usr/include/tesseract -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -ltesseract

clean:
	rm -rf Output

prog: all
	./Output/myComp Input.DSL
	./Output/output

run: clean prog
