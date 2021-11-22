//
//  roster.cpp
//  C867
//
//  Created by Chris Vergilio on 11/21/21.
//

#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"


void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysincourse1, int daysincourse2, int daysincourse3, DegreeProgram degree) {
    // Add a student to the roster.
    
    int daysincourse[3] = {daysincourse1, daysincourse2, daysincourse3};
    
    for (auto &entry : classRosterArray) {
        if (entry == nullptr) {
            entry = new Student(studentID, firstName, lastName, emailAddress, age, daysincourse, degree);
            break;
        }
    }
}

void Roster::printAll() {
    // Prints student information from the roster.
    for (auto &entry : classRosterArray) {
        if (entry != nullptr) {
            std::cout << entry->getID() << "    First Name: " << entry->getFirstName() << "    Last Name: " << entry->getLastName() << "    Age: " << entry->getAge() << "    Days in Course: " << entry->getCourseDaysStr() << "    Degree Program: " << entry->getDegreeName() << std::endl;
        }
    }
    std::cout << std::endl;
}

void Roster::remove(std::string ID) {
    // Remove a student from the roster.
    bool studentFound = false;
    for (auto &entry : classRosterArray) {
        if (entry != nullptr && entry->getID() == ID) {
            entry = nullptr;
            studentFound = true;
            std::cout << "Student successfully removed from roster." << std::endl << std::endl;
            break;
        }
    }
    if (not studentFound) {
        std::cout << "ERROR: Student ID not found!" << std::endl << std::endl;
    }
}


void Roster::printAverageDaysInCourse(std::string ID) {
    // Print out the average days in courses for the requested student.
    for (auto &entry : classRosterArray) {
        if (entry != nullptr && entry->getID() == ID) {
            int *tempcourses = entry->getCourseDays();
            int sum = 0;
            for (int i=0; i<3; i++)
            {
                sum += tempcourses[i];
            }
            std::cout << "Average number of days in courses: " << sum/3 << std::endl;
        }
    }
    std::cout << std::endl;
}

void Roster::printInvalidEmails() {
    // Print out each invalid email address. Validity defined by PA requirements.
    for (auto &entry : classRosterArray) {
        if (entry != nullptr)
        {
            std::string temp_email = entry -> getEmail();
            if (temp_email.find("@") == std::string::npos or temp_email.find(".") == std::string::npos or temp_email.find(" ") != std::string::npos)
            {
                std::cout << temp_email << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

void Roster::printByDegreeType(DegreeProgram degree) {
    // Print out each student that matches the requested degree program.
    for (auto &entry : classRosterArray) {
        if (entry != nullptr && entry->getDegree() == degree ) {
            entry -> print();
        }
    }
}

Student* Roster::getStudentByPos(int pos) {
    // Returns the student at position in the classRosterArray.
    return classRosterArray[pos];
}


Roster::~Roster() {};
