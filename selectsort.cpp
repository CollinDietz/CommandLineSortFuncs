#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

//generic function to print a vector passed to it (by reference) using a for loop
void print(vector<int> v)
{
    for(int i =0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

int main(int argc, char** argv)
{
	//comperison variable for given command line arguments
    const int ARGUMENTS = 2;
    
	//verify that the fuction had only 1 command line argument passed to it
    if(argc != 2)
    {
		//let user know the appropriate way to call command, and exit with code 1
        cout << "Function takes one input, a file" << endl;
		cout << "Proper use: " << argv[0] << " <filename>.txt" << endl;
        return 1;
    }
    
	//create a new file input stream and open given file
    ifstream in;
    in.open(argv[1]);

	//If the file opening fails, report the failure to the user and exit with code 2
    if(!in.good())
    {
        cout << "File name is invalid" << endl;
        return 2;
    }

    vector<int> numbers; //container for the numbers in the file

    int num; //temp holder to grab the number from the file
    while(!in.eof())
    {
		//Grab number from the file and push into the vector
        in >> num;
        numbers.push_back(num);
    }
    in.close();

    print(numbers); //print the files contents on the terminal for comparison
    cout << endl;
    long int startTime = time(0);//time logging

	//Selection sort
    for(int i = 1; i < numbers.size(); i++)
    {
        int j = i;
        int  key = numbers[i];

        while( j > 0 && numbers[j-1] > key)
        {
            numbers[j] = numbers[j-1];
            j = j - 1;
        }
        numbers[j] = key;
    }

	//output time
    long int stopTime = time(0);
    print(numbers);
    cout << endl << stopTime-startTime << "s" << endl;
    return 0;
}

