//
//  student.cpp
//  C867
//
//  Created by Chris Vergilio on 11/21/21.
//

#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

// Define accessors
std::string Student::getFirstName() {
    return firstName;
}

std::string Student::getLastName() {
    return lastName;
}

std::string Student::getID() {
    return studentID;
}

std::string Student::getEmail() {
    return studentEmail;
}

int Student::getAge() {
    return studentAge;
}

int* Student::getCourseDays() {
    return courseDays;
}

std::string Student::getCourseDaysStr() {
    std::string temp = "";
    for (int i=0; i < 3; i++) {
        temp.append(std::to_string(courseDays[i]) + ",");
    }
    temp.pop_back();
    return temp;
}

DegreeProgram Student::getDegree() {
    return degree;
}

std::string Student::getDegreeName() {
    switch (degree) {
        case 0:
            return "Security";
            break;
        case 1:
            return "Networking";
            break;
        case 2:
            return "Software";
            break;
        default:
            return "UNDEFINED";
            break;
    }
}

//Define mutators
void Student::setID(std::string newID) {
    studentID = newID;
}

void Student::setFirstName(std::string newFirstName) {
    firstName = newFirstName;
}

void Student::setLastName(std::string newLastName) {
    lastName = newLastName;
}

void Student::setStudentEmail(std::string newEmail) {
    studentEmail = newEmail;
}

void Student::setAge(int newAge) {
    studentAge = newAge;
}

void Student::setCourseDays(int *newCourseDays) {
    for (int i=0; i<3; i++) {
        courseDays[i] = newCourseDays[i];
    }
}

void Student::setDegree(DegreeProgram newDegree) {
    degree = newDegree;
}

//Define constructor
Student::Student(std::string id, std::string firstname, std::string lastname, std::string email, int age, int courses[3], DegreeProgram degreeProgram) {
    studentID = id;
    firstName = firstname;
    lastName = lastname;
    studentEmail = email;
    studentAge = age;
    for (int i=0; i < 3; i++) {
        courseDays[i] = courses[i];
    }
    degree = degreeProgram;
}

Student::~Student() {};

//Print method
void Student::print() {
    // Make changes here to be able to dynamically retrieve student info.
    std::cout << "Student #" << studentID << std::endl;
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Email Address: " << studentEmail << std::endl;
    std::cout << "Age: " << studentAge << std::endl;
    std::cout << "Days to Complete Courses: " << courseDays[0] << "," << courseDays[1] << "," << courseDays[2] << std::endl;
    
    std::cout << "Degree Program: ";
    switch (degree) {
        case 0:
            std::cout << "Security";
            break;
        case 1:
            std::cout << "Networking";
            break;
        case 2:
            std::cout << "Software";
            break;
        default:
            std::cout << "ERROR: Undefined degree program";
            break;
    }
    std::cout << std::endl << std::endl;
    
}
