all: ctest

ctest: ctest.o mystring.o structhelper.o
	gcc ctest.o mystring.o structhelper.o -o ctest

ctest.o: ctest.c mystring.h
	gcc -c ctest.c

mystring.o: mystring.c mystring.h
	gcc -c mystring.c

structhelper.o: structhelper.c structhelper.h mystring.h
	gcc -c structhelper.c

clean: 
	rm -f mystring.o ctest.o structhelper.o ctest

docs:
	doxygen
	chmod 755 ./html/*
	cp -p ./html/* ~/public_html/cs2303_hw03
