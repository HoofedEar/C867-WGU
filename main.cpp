//
//  main.cpp
//  C867
//
//  Created by Chris Vergilio on 11/21/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "student.cpp"
#include "roster.h"
#include "degree.h"

using namespace std;

const string studentData[] =
{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Christopher,Vergilio,cvergil@wgu.edu,25,60,54,72,SOFTWARE"
};

int main()
{
    // Print out requested information
    cout << "Course Title: C867 Scripting and Programming - Applications\nProgramming Language: C++\nStudent ID: 001286509\nStudent Name: Christopher Vergilio" << endl << endl;
    
    // Create a roster named classRoster
    Roster classRoster;
    
    // Add each student into the roster
    for (auto &entry : studentData)
    {
    
        vector<string> student;
        stringstream s_stream(entry);
        DegreeProgram temp_degree;
        while (s_stream.good()) {
            string substr;
            getline(s_stream, substr, ',');
            student.push_back(substr);
        }
        
        if (student.at(8) == "SOFTWARE") {
            temp_degree = SOFTWARE;
        }
        else if (student.at(8) == "NETWORK") {
            temp_degree = NETWORK;
        }
        else if (student.at(8) == "SECURITY") {
            temp_degree = SECURITY;
        }
        else {
            temp_degree = NONE;
        }
                
        classRoster.add(student.at(0), student.at(1), student.at(2), student.at(3), stoi(student.at(4)), stoi(student.at(5)), stoi(student.at(6)), stoi(student.at(7)), temp_degree);
    }

    // Demonstrate methods
    classRoster.printAll();
    classRoster.printInvalidEmails();
    
    for (int i=0; i<5; i++) {
        string current_student = classRoster.getStudentByPos(i) -> getID();
        classRoster.printAverageDaysInCourse(current_student);
    }
    
    classRoster.printByDegreeType(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");
    
    classRoster.~Roster();
    
    return 0;
}
