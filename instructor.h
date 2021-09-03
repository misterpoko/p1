#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "student.h"

class instructor
{
private:
        string fullName;

public:
        bool login(string username, string password);
        string getInstructorName();
        student getStudent(string username);
        student getMinStudent(int gradeType);
        student getMaxStudent(int gradeType);
        double getAvg(int gradeType);
};

#endif
