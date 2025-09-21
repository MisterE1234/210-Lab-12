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
    //declare variables:
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
        //The file is formatted with the name on one line and the score on the next line so that we can use getline to read the name and then read the score
        getline(iFile,students[i]);
        iFile >> scores[i];
        iFile.ignore(1000, '\n'); //ignore any leftover newline characters
    }

    iFile.close(); //close the input file

    //display the names and scores
    cout << "Student Names and Scores:" << endl;
    for (int i = 0; i < SIZE; i++)
    { //determine the letter grade based on the score
        grade = (scores[i] >= 90) ? 'A' :
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
    cout << "Average Score: " << grade << ", " << average << "%" << endl;

    //find and display the the student with the highest score
    int highestScore = *max_element(scores.begin(), scores.end());
    string highestStudent = students[distance(scores.begin(), max_element(scores.begin(), scores.end()))];
    //determine the letter grade based on the score
    grade = (highestScore >= 90) ? 'A' :
             (highestScore>= 80) ? 'B' :
             (highestScore >= 70) ? 'C' :
             (highestScore >= 60) ? 'D' : 'F';
    cout << "Highest Score: " << highestStudent << ": " << grade << ", " << highestScore << "%" << endl;

    //find and display the student with the lowest score
    int LowestScore = *min_element(scores.begin(), scores.end());
    string LowestStudent = students[distance(scores.begin(), min_element(scores.begin(), scores.end()))];
    //determine the letter grade based on the score
    grade = (LowestScore >= 90) ? 'A' :
             (LowestScore >= 80) ? 'B' :
             (LowestScore >= 70) ? 'C' :
             (LowestScore >= 60) ? 'D' : 'F';
    cout << "Lowest Score: " << LowestStudent << ": " << grade << ", " << LowestScore << "%" << endl;

    //Now we will sort the students by their respective scores then display them in descending order:

    sort(students.begin(),scores.end()); //sort the names and scores in ascending order based on the scores 
    reverse (scores.begin(),scores.end()); //reverse the scores to be in descending order
    reverse (students.begin(),students.end()); //reverse the names to be in descending order

    //display the names and scores
    cout << "Student Names and Scores:" << endl;
    for (int i = 0; i < SIZE; i++)
    { //determine the letter grade based on the score
        grade = (scores[i] >= 90) ? 'A' :
             (scores[i] >= 80) ? 'B' :
             (scores[i] >= 70) ? 'C' :
             (scores[i] >= 60) ? 'D' : 'F';
        cout << students[i] << ": " << grade << endl;
    }

    return 0;
}