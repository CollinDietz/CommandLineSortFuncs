#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

//generic function to print a vector passed to it (by reference) using a for loop
void print(vector<int> &v)
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
    long int startTime = time(0); //time logging

    //begining of sorting algorithim
    int numbersSmallerThan; //holds the count of numbers smaller then the current
    int startingPlace = 0; //starting place for the counting
    //while there is still another number smaller then the one in front of it
    while(startingPlace < numbers.size() - 1)
    {
        //count how many other numbers in the list are smaller than it
        numbersSmallerThan = 0;
        for(int j = startingPlace + 1; j < numbers.size(); j++)
        {
            if(numbers[startingPlace] > numbers[j])
            {
                numbersSmallerThan++;
            }

        }
        
        //if there are no numbers smaller then it, it is the smallest number in the remaining list,
        //so advance the starting place one
        if(numbersSmallerThan == 0)
        {
            startingPlace++;
        }
        else
        {
            //else the number is not the smallest one in the remaining list, and must be swapped
            //The number belongs in the place equal to the number of items smaller then it
            //i.e. numbers smaller than shifted by the current starting posistion
            int newPos = startingPlace + numbersSmallerThan; 
            //make sure the number isnt equal to the number already in that posistion
            while(numbers[startingPlace] == numbers[newPos])
             {
                 //if it is scoot its targetslot until it isnt 
                 newPos++;
             }
            //swap the number at startingplace and the newPos
             int temp = numbers[startingPlace];
             numbers[startingPlace] = numbers[newPos];
             numbers[newPos] = temp;
        }

    }
    //output time
    long int stopTime = time(0);
    print(numbers);
    cout << endl << stopTime-startTime << "s" << endl;
    return 0;
}

