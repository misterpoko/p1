#include <iostream>
#include <string>
#include "instructor.h"

string fName;
string uName;
string pw;
Student *people;

/*
 * GradeTypes:
 * project -1
 * quiz    -2
 * midterm -3
 * final   -4
 * overall -5
 */

Instructor::Instructor(){}
/**
 * Instructor constructor 
 * @param sting username is instructor's username 
 * @param string password is instructor's password
 * @param string firstName is instructor's first name 
 * @param string lastName is instructor's last name 
 * @param Student *person is the student array 
 */
Instructor::Instructor(string username, string password, string firstName, string lastName, Student *persons) {
	uName = username;
	pw = password;
	fName = firstName + " " + lastName;
	people = persons;
} // Instructor
/**
 * getter method for instructor's name
 * @return the student's full name 
 */
string Instructor::getInstructorName() {
	return fName;
} // getInstructorName

/** 
 * student getter for student username 
 * @param string username is students username 
 */
Student Instructor::getStudent(string username) {
	for (int i = 0; i < 20; i++) {
		if(!(people[i].username.compare(username))) {
			return people[i];
		} // if
	} // for
	return Student("Not","Exist", "noUN", "pw", -1, -1, -1, -1);
} // getStudent
/** 
 * student getter for student minimum grade 
 * @param int gradeType is student's type of grade (quiz grade, project grade, midterm grade, final grade, overall grade)
 * @return the minimum of all students grades 
 */
Student Instructor::getMinStudent(int gradeType) {
	Student min = people[0];
	switch(gradeType) {
		case 1:	
			for (int i = 1; i < 20; i++) {
				if (people[i].getProjectGrade() < min.getProjectGrade()) {
					min = people[i];
				} // if
			} // for		
			break;		
		case 2:	
			for (int i = 1; i < 20; i++) {
				if (people[i].getQuizGrade() < min.getQuizGrade()) {
					min = people[i];
				} // if
			} // for		
			break;		
		case 3:	
			for (int i = 1; i < 20; i++) {
				if (people[i].getMidtermGrade() < min.getMidtermGrade()) {
					min = people[i];
				} // if
			} // for		
			break;		
		case 4:	
			for (int i = 1; i < 20; i++) {
				if (people[i].getFinalGrade() < min.getFinalGrade()) {
					min = people[i];
				} // if
			} // for		
			break;		
		case 5:	
			for (int i = 1; i < 20; i++) {
				if (people[i].getOverallGrade() < min.getOverallGrade()) {
					min = people[i];
				} // if
			} // for
			break;		
	} // switch
	return min;
} // getMinStudent
/** 
 * student getter for student's max grades
 * @param int gradeType is student's type of grade (quiz grade, project grade, midterm grade, final grade, overall grade)
 * @return the max of all students grades 
 */
Student Instructor::getMaxStudent(int gradeType) {
	Student max = people[0];
	switch(gradeType) {
		case 1:	
			for (int i = 1; i < 20; i++) {
				if (people[i].getProjectGrade() > max.getProjectGrade()) {
					max = people[i];
				} // if
			} // for		
			break;		
		case 2:	
			for (int i = 1; i < 20; i++) {
				if (people[i].getQuizGrade() > max.getQuizGrade()) {
					max = people[i];
				} // if
			} // for		
			break;		
		case 3:	
			for (int i = 1; i < 20; i++) {
				if (people[i].getMidtermGrade() > max.getMidtermGrade()) {
					max = people[i];
				} // if
			} // for		
			break;		
		case 4:	
			for (int i = 1; i < 20; i++) {
				if (people[i].getFinalGrade() > max.getFinalGrade()) {
					max = people[i];
				} // if
			} // for		
			break;		
		case 5:	
			for (int i = 1; i < 20; i++) {
				if (people[i].getOverallGrade() > max.getOverallGrade()) {
					max = people[i];
				} // if
			} // for
			break;		
	} // switch
	return max;
} // getMaxStudent

/** 
 * student getter for average grade for all students
 * @param int gradeType is student's type of grade (quiz grade, project grade, midterm grade, final grade, overall grade)
 * @return sum of grades dived by the amount of students (20). 
 */
double Instructor::getAvg(int gradeType) {
	double sum = 0.0;
	switch (gradeType) {
		case 1:
			for (int i = 0; i < 20; i++) {
				sum += people[i].getProjectGrade();
			} // for
			break;
		case 2:
			for (int i = 0; i < 20; i++) {
				sum += people[i].getQuizGrade();
			} // for
			break;
		case 3:
			for (int i = 0; i < 20; i++) {
				sum += people[i].getMidtermGrade();
			} // for
			break;
		case 4:
			for (int i = 0; i < 20; i++) {
				sum += people[i].getFinalGrade();
			} // for
			break;
		case 5:
			for (int i = 0; i < 20; i++) {
				sum += people[i].getOverallGrade();
			} // for
			break;
	} // switch
	return sum/20;
} // getAvg

/** 
 *  * boolean operation for instructor login 
 *   * @param string username is instructor's username 
 *    * @return 1 if username and password is inputted properly and 0 if it isn't
 *     */
bool Instructor::login(string username, string password) {
	if (username == uName && password == pw) {
		return 1;
	} // if
	return 0;
} // login
