//
//  student.h
//  C867
//
//  Created by Chris Vergilio on 11/21/21.
//

#include <string>
#include "degree.h"
#ifndef student_h
#define student_h

class Student {
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string studentEmail;
    int studentAge;
    int courseDays[3];
    DegreeProgram degree;

public:
    //Accessors
    std::string getFirstName();
    std::string getLastName();
    std::string getID();
    std::string getEmail();
    int getAge();
    int* getCourseDays();
    DegreeProgram getDegree();
    std::string getDegreeName();
    std::string getCourseDaysStr();

    //Mutators
    void setID(std::string);
    void setFirstName(std::string);
    void setLastName(std::string);
    void setStudentEmail(std::string);
    void setAge(int);
    void setCourseDays(int[3]);
    void setDegree(DegreeProgram);

    //Constructor
    Student(std::string id,
            std::string firstname,
            std::string lastname,
            std::string email,
            int age,
            int courses[3],
            DegreeProgram degreeProgram);
    ~Student();
    
    //Other methods
    void print();
};

#endif /* student_h */
