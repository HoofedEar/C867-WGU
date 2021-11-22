//
//  roster.h
//  C867
//
//  Created by Chris Vergilio on 11/21/21.
//

#include <string>
#include "student.h"
#include "degree.h"
#ifndef roster_h
#define roster_h

class Roster {
    
private:
    Student *classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
 
public:
    
    
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysincourse1, int daysincourse2, int daysincourse3, DegreeProgram degree);
    void printAll();
    void remove(std::string ID);
    void printAverageDaysInCourse(std::string ID);
    void printInvalidEmails();
    void printByDegreeType(DegreeProgram degree);
    Student* getStudentByPos(int pos);
    
    ~Roster();
};

#endif /* roster_h */
