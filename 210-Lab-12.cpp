//Comsc-210|Lab 12|Ethan Aylard
//IDE used: Visual Studio Code

//This program demonstates the use of c++ arrays and external data files by using them to create a data base of students in an imaginary school

#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>
#include <fstream>
using namespace std;

int main()
{
    const int SIZE = 30; //size of the array
    array<string, SIZE> names; //array to hold student names
    array<int, SIZE> scores; //array to hold student scores
    ifstream iFile; //input file stream object
    iFile.open("students.txt"); //open the input file

    //check if the file opened successfully
    if (!iFile)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    //read names and scores from the file into the arrays
    for (int i = 0; i < SIZE; i++)
    {
        iFile >> names[i] >> scores[i];
    }

    iFile.close(); //close the input file

    //display the names and scores
    cout << "Student Names and Scores:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << names[i] << ": " << scores[i] << endl;
    }

    //calculate and display the average score
    double average = static_cast<double>(accumulate(scores.begin(), scores.end(), 0)) / SIZE;
    cout << "Average Score: " << average << endl;

    //find and display the highest score
    int highestScore = *max_element(scores.begin(), scores.end());
    cout << "Highest Score: " << highestScore << endl;

    return 0;
}