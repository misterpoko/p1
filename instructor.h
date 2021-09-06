#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "student.h"

class instructor
{
	public:
        	string fullName;
        	bool login(string username, string password);
        	string getInstructorName();
        	Student getStudent(string username);
        	Student getMinStudent(int gradeType);
        	Student getMaxStudent(int gradeType);
        	double getAvg(int gradeType);
};

#endif
