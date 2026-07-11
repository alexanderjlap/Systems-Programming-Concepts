Alexander Lap
CS2303 HW 05


Commands:

make: Assemble the software
make clean: Remove objects and files created from old compilation.
make docs: To produce code documentation.

./stacktest: Strings are inputted, pushed into a stack, and then the objects are popped.
Usage: ./stacktest max_elements

./stacktest2: Reverse-prints the strings from the stack
Usage: ./stacktest2 max_elements

./stacktest_dbg
./stacktest2_dbg
(These commands perform the same operations when used for debugging.)

For further information on the functions used in the programs, consult the output from doxygen.

Examples:

alexanderlap@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw05$ ./stacktest
Just one parameter should be entered into the command line.

alexanderlap@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw05$ ./stacktest -1
You have entered -1 but max_elements must be >= 0!

alexanderlap@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw05$ ./stacktest 3 < input.txt
third line
This is the second line
This is a line
alexanderlap@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw05$ ./stacktest 5 < input.txt
Fifth and final line
fourth
third line
This is the second line
This is a line

alexanderlap@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw05$ ./stacktest 10 < input.txt
Fifth and final line
fourth
third line
This is the second line
This is a line

alexanderlap@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw05$ ./stacktest2 5 < input.txt
enil lanif dna htfiF
htruof
enil driht
enil dnoces eht si sihT
enil a si sihT

alexanderlap@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw05$ ./stacktest2 10 < input.txt
enil lanif dna htfiF
htruof
enil driht
enil dnoces eht si sihT
enil a si sihT

