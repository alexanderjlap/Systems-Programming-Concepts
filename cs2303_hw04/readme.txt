Alexander Lap

Run make, then either./sorttest or./sorttest2 to run the scripts.
Sorttest uses a set of numbers from the command line as inputs. Always use arrays to sort.
A random number generator will be used in Sorttest 2 to create a large number of values. Two flags are also needed. run "p" to sort with pointers and "a" to sort with arrays. To reseed the RNG, add the letter "s" after the sort type flag.

alexanderlap@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw04$ ./sorttest 1 2
Unsorted array:
1
2
sorting using arrays
Sorted array (descending order):
2
1
Timestamp before sorting: Seconds: 1676156275 Mircroseconds: 780113
Timestamp after sorting: Seconds: 1676156275 Mircroseconds: 780114
Time spent sorting: Seconds: 0 Mircroseconds: 1

alexanderlap@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw04$ ./sorttest2 1 2
Flag character is 2
Unsorted array:
9383
sorting using pointers
Sorted array (descending order):
9383
Timestamp before sorting: Seconds: 1676155798 Mircroseconds: 3493
Timestamp after sorting: Seconds: 1676155798 Mircroseconds: 3494
Time spent sorting: Seconds: 0 Mircroseconds: 1

They are essentially similar for tiny arrays, with array sort having a minor advantage.
Pointers exhibit a significant benefit for larger datasets.

