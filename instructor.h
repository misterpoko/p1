#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "student.h"

class Instructor
{
	public:
		Instructor();
		Instructor(string one, string two, string three, string four, Student persons[20]);
        	string fullName;
        	bool login(string username, string password);
        	string getInstructorName();
        	Student getStudent(string username);
        	Student getMinStudent(int gradeType);
        	Student getMaxStudent(int gradeType);
        	double getAvg(int gradeType);
		void getStudentArray(Student firstStudents[20]);
};

#endif
