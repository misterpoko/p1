#include <iostream>
#include <string>
#include "student.h"

using namespace std;

string fullName;
string username;
string password;
int finalGrade;
int midtermGrade;
int quizGrade;
int projectGrade;

Student::Student() {}
/**
 * student constructor 
 * @param string fName is student's full name 
 * @param string  lName is student's last name
 * @param string uName is student's username 
 * @param string pw is student's password
 * @param int fg is student's final grade 
 * @param int mg is student's midterm grade
 * @param int qg is student's quiz grades 
 * @param int pg is student's project grades 
 */
Student::Student(string fName, string lName, string uName, string pw, int fg, int mg, int qg, int pg) { 
	fullName = fName + " " + lName;
	username = uName;
	password = pw;
	finalGrade = fg;
	midtermGrade = mg;
	quizGrade = qg;
	projectGrade = pg;
} // student

/** 
 * getter method for student names
 * @return student's full name 
 */
string Student::getStudentName() {
	return fullName;
} // getStudentName

/**
 * getter method for student project grades 
 * @return students project grades 
 */
int Student::getProjectGrade() {
	return projectGrade;
} // getProjectGrade

/**
 * getter method for students quiz grades 
 * @return students quiz grades 
 */
int Student::getQuizGrade() {
	return quizGrade;
} // getQuizGrade

/**
 * getter method for students midterm grades 
 * @return midterm grades for studens 
 */
int Student::getMidtermGrade() {
	return midtermGrade;
} // getMidtermGrade

/** 
 * getter method for students final grades 
 * @return final grades for students 
 */
int Student::getFinalGrade() {
	return finalGrade;
} // getFinalGrade

/** 
 * method for overall grades of students 
 * @return the sum of grades added up 
 */
double Student::getOverallGrade() {
	double sum = 0;
       	sum += (.3 * projectGrade);
       	sum += (.1 * quizGrade);
       	sum += (.2 * midtermGrade);
       	sum += (.4 * finalGrade);
        return sum;
} // getOverallGrade

/** 
 * boolean method for student login 
 * @param un is student username 
 * @param is student password 
 * @return true if login accepted 
 * @return false is login was unsuccessful
 * 
 */
bool Student::login(string un, string pw) {
	if (!username.compare(un) && !password.compare(pw)) {
		return true;
	} // if
		return false;
} // login

