# CommandLineSortFuncs
Unix command line based sorting functions to test my own attempt at new sorting functions against popular ones

9/26/16 - First three CPP files added
SetGen.cpp which when complied is a command line function that generates a set of random numbers in a range and outputs to a specified file, used to create unsorted data for the sorting algorithims

Paramaters (in order):
number of integers to be calculated
highest number possible (makes range 0-highest number possible)
file to store the generated numbers in

countsort.cpp which reads in the name of a file, opens it, reads in the numbers there and then times the amount of time to sort the data. Uses an algorithim of my own design that places elements in the list at the posistion of the amount of elements less than itself, and then handles special cases (duplicate elements, or  no elements smaller then the current test case)

parameters:
name of file containing data

insertsort.cpp which works exactly the same way as countsort.cpp, but uses insertion sort to do the sorting instead, for comparison purposes

parameters:
name of file containing data
