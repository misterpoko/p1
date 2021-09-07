#include <iostream>
#include <string>
#include "instructor.h"

string fName;
string uName;
string pw;
Student people[100];

/*
 * GradeTypes:
 * project -1
 * quiz    -2
 * midterm -3
 * final   -4
 * overall -5
 */

Instructor::Instructor(){}

Instructor::Instructor(string username, string password, string firstName, string lastName) {
	uName = username;
	pw = password;
	fName = firstName + " " + lastName;
} // Instructor

string getInstructorName() {
} // getInstructorName

Student getStudent(string username) {
} // getStudent

Student getMinStudent(int gradeType) {
} // getMinStudent

Student getMaxStudent(int gradeType) {
} // getMaxStudent

double getAvg(int gradeType) {
	return 0.0;
} // 
bool login(string username, string password) {
	if (username == uName && password == pw) {
		return 1;
	} // if
	return 0;
} // login

void getStudentArray(Student* firstStudent) {
} // getStudentArray
