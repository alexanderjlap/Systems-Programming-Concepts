# CS2303-Homework-3

##Compiling
Simply enter the project directory and type:

    make

Run the following command in the project directory to remove previously generated objects:

    make clean

Run the following command to create the doxygen folder under public html:

    make docs

##Programs

##ctest.c

Simply compile the code and execute the following command in the project directory to run ctest. The output sample is also provided below.

    alexanderlap@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw03$ ./ctest
Pointers: a1 = 0x7fffc31c6ce0, a2 = 0x7fffc31c6e12, a3 = 0x7fffc31c6cc0
          p1 = 0x563b693f600c p2 = (nil)
a1 = Hi
a2 = Hello
a3 = Hello, also
a1 = HiHello
a1 = HiHelloHello
a1 = HiHelloHelloHello, a
Before dup, pointer a2 = 0x7fffc31c6e12, contents = Hello
Pointer p2 = 0x563b6b36d6b0, contents = Hello

Testing mystrcat and mystrncat
a4 = Testing mystrcpyHell

Testing mystrncpy and mystrndup
a5 (too long to fit) = This is a long strin
a5 = This is a long
p3 (copy of a5, truncated to 4 chars) = This

Testing student creation and printing methods.
Printing premade students
Student Jesse Pinkman:
	Grade: 2
	GPA: 3.500000
Student Saul Goodman:
	Grade: 4
	GPA: 4.000000
Student Walter White:
	Grade: 5
	GPA: 2.000000
Printing random students
Student CJNXFGAZOK:
	Grade: 3
	GPA: 1.000000
Printing random student array
Student WOSDYKHCFZ:
	Grade: 4
	GPA: 4.000000
Student AKDIXYFAIS:
	Grade: 11
	GPA: 3.000000
Student YXNNITNEIF:
	Grade: 4
	GPA: 2.000000
Student QPJVPRUPCX:
	Grade: 12
	GPA: 1.000000
Student WDAFVYTUVG:
	Grade: 4
	GPA: 1.000000
Student AUIIAQPQFY:
	Grade: 6
	GPA: 4.000000
Student QFKSDITALT:
	Grade: 3
	GPA: 2.000000
Student SZBNFIRGDZ:
	Grade: 8
	GPA: 1.000000
Student QFTVDFPULZ:
	Grade: 7
	GPA: 3.000000
Student IGPTAVASUC:
	Grade: 3
	GPA: 1.000000
Printing duplicate student array
Student WOSDYKHCFZ:
	Grade: 4
	GPA: 4.000000
Student AKDIXYFAIS:
	Grade: 11
	GPA: 3.000000
Student YXNNITNEIF:
	Grade: 4
	GPA: 2.000000
Student QPJVPRUPCX:
	Grade: 12
	GPA: 1.000000
Student WDAFVYTUVG:
	Grade: 4
	GPA: 1.000000
Student AUIIAQPQFY:
	Grade: 6
	GPA: 4.000000
Student QFKSDITALT:
	Grade: 3
	GPA: 2.000000
Student SZBNFIRGDZ:
	Grade: 8
	GPA: 1.000000
Student QFTVDFPULZ:
	Grade: 7
	GPA: 3.000000
Student IGPTAVASUC:
	Grade: 3
	GPA: 1.000000
Printing deep copied student array.
Student WOSDYKHCFZ:
	Grade: 4
	GPA: 4.000000
Student AKDIXYFAIS:
	Grade: 11
	GPA: 3.000000
Student YXNNITNEIF:
	Grade: 4
	GPA: 2.000000
Student QPJVPRUPCX:
	Grade: 12
	GPA: 1.000000
Student WDAFVYTUVG:
	Grade: 4
	GPA: 1.000000
Student AUIIAQPQFY:
	Grade: 6
	GPA: 4.000000
Student QFKSDITALT:
	Grade: 3
	GPA: 2.000000
Student SZBNFIRGDZ:
	Grade: 8
	GPA: 1.000000
Student QFTVDFPULZ:
	Grade: 7
	GPA: 3.000000
Student IGPTAVASUC:
	Grade: 3
	GPA: 1.000000

Printing emptied pointer in s6[0] and s6[8]: (nil), (nil)
