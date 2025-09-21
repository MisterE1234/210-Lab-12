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
    char grade;
    array<string, SIZE> students; //array to hold student names
    array<double, SIZE> scores; //array to hold student scores
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
        iFile.ignore(1000, '\n'); //ignore any leftover newline characters
        getline(iFile,students[i]);
        iFile >> scores[i];
    }

    iFile.close(); //close the input file

    //display the names and scores
    cout << "Student Names and Scores:" << endl;
    for (int i = 0; i < SIZE; i++)
    { grade = (scores[i] >= 90) ? 'A' :
             (scores[i] >= 80) ? 'B' :
             (scores[i] >= 70) ? 'C' :
             (scores[i] >= 60) ? 'D' : 'F';
        cout << students[i] << ": " << grade << endl;
    }

    //calculate and display the average score
    double average = static_cast<double>(accumulate(scores.begin(), scores.end(), 0)) / SIZE;
    grade = (average >= 90) ? 'A' :
             (average >= 80) ? 'B' :
             (average >= 70) ? 'C' :
             (average >= 60) ? 'D' : 'F';
    cout << "Average Score: " << grade << endl;

    //find and display the highest score
    int highestScore = *max_element(scores.begin(), scores.end());
    cout << "Highest Score: " << highestScore << endl;

    return 0;
}