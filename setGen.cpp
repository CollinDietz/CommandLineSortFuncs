#include<cstdlib>
#include<iostream>
#include<ctime>
#include<fstream>
#include<sstream>


using namespace std;


int main(int argc, char** argv)
{
	//comperison variable for given command line arguments
    const int ARGUMENTS = 4;

	//verify that the fuction had only 2 command lines argument passed to it
    if(argc != ARGUMENTS)
    {
        cout << "Function needs both a number of items and a save location (in that order)" << endl;
		cout << "Proper use: " << argv[0] << " <number of items>  <largest number allowed> <filename>.txt" << endl;
        return 1;
    }
    
	//open output stream and file that was given by command line arguement
    ofstream out;
    out.open(argv[3]);

	//take in the command line arguements for number of items and largest num and convert to int
    stringstream stringStream;
    stringStream << argv[1];
    int numberOfItems;
	stringStream >> numberOfItems;

	stringStream << argv[2];
	int maxNum; //highest number allowed to be generated
	stringStream >> maxNum;
    
   
    int randomNum; //temp holder for the random number
    srand(time(0)); //seed with system time 
	//generate numberOfItems numbers between 0 and maxNum
    for(int i = 0; i < numberOfItems; i++)
    {
        randomNum = rand() % maxNum;
        out << randomNum << endl; //output to opened file
    }

    out.close();
    return 0;
}

