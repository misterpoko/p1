#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "instructor.h"
#include <string>
#include <sstream>
#include <unistd.h>

using namespace std;
Student theStudents[20];
Instructor theInstructors[3];
bool isInstructor = 0;
bool isLogin = 0;

int initialize(char *argv1, char *argv2);
void getWord(string *toChange, FILE * stream);
int sti (string number);

void promptUser();
void promptLogin(int isInstructor);
void promptInstructor();
void promptStudent();
void instructorOption1();
void instructorOption2();

int main(int argc, char **argv) {
	if (argc != 3) {
		cout << "Usage: main [instructors_file] [students_file]" << endl;
		return 1;
	} // if
	if(initialize(argv[1], argv[2])) {
		cout << "Parsing instructors and students information success." << endl << endl;
		promptUser();	
        	return 0;
	} // if
	return 1;
} // main

void printStudent(Student person) {
	cout << endl;
	cout << "Student name: " << person.fullName << endl << '\t' << "Project " << person.getProjectGrade() << "%" << endl;
	cout << '\t' << "Quiz    " << person.getQuizGrade() << "%" << endl << '\t' << "Midterm " << person.getMidtermGrade();
	cout << "%" << endl << '\t' << "Final   "  << person.getFinalGrade() << "%" << endl << '\t' << "Overall ";
	cout << person.getOverallGrade() << "%" << endl << endl;
} // printStudent

void printOption2(int gradeType) {
	string type;
	Student min = theInstructors[isInstructor].getMinStudent(gradeType);
	Student max = theInstructors[isInstructor].getMaxStudent(gradeType);
	int minGrade;
	int maxGrade;
	double avgGrade = theInstructors[isInstructor].getAvg(gradeType);
	isLogin = 0;
	isInstructor = 0;
	switch (gradeType) {
		case 1:
			type = "Project";
			minGrade = min.projectGrade;
			maxGrade = max.projectGrade;
			break;
		case 2:
			type = "Quiz";
			minGrade = min.quizGrade;
			maxGrade = max.quizGrade;
			break;
		case 3:
			type = "Midterm";
			minGrade = min.midtermGrade;
			maxGrade = max.midtermGrade;
			break;
		case 4: 
			type = "Final";
			minGrade = min.finalGrade;
			maxGrade = max.finalGrade;
			break;
		case 5:
			type = "Overall";
			cout << type << " grade stats," << endl << '\t' << "min" << '\t' <<  min.getOverallGrade() << "% (" << min.fullName << ")" << endl;
			cout << '\t' << "max" << '\t' <<  max.getOverallGrade() << "% (" << max.fullName << ")" << endl;
			cout << '\t' << "avg" << '\t' << avgGrade << "%" << endl << endl;
			return;
	} // switch
	cout << type << " grade stats," << endl << '\t' << "min" << '\t' <<  minGrade << "% (" << min.fullName << ")" << endl;
	cout << '\t' << "max" << '\t' <<  maxGrade << "% (" << max.fullName << ")" << endl;
	cout << '\t' << "avg" << '\t' << avgGrade << "%" << endl << endl;
} // printOption2

void instructorOption2() {
	string number;
	cout << endl << "Grade types," << endl << '\t' << "1 - Project grade" << endl << '\t' << "2 - Quiz grade" << endl << '\t';
	cout << "3 - Midterm grade" << endl << '\t' << "4 - Final grade" << endl << '\t' << "5 - Overall grade" << endl;
	cout << "Select a grade type to view stats: ";
	cin >> number;
	if (!number.compare("1")) {
		printOption2(1);
		promptUser();
	} else if (!number.compare("2")) {
		printOption2(2); 
		promptUser();
	} else if (!number.compare("3")) { 
		printOption2(3); 
		promptUser();
	} else if (!number.compare("4")) { 
		printOption2(4); 
		promptUser();
	} else if (!number.compare("5")) { 
		printOption2(5); 
		promptUser();
	} else {
		cout << "Invalid option. Please enter a valid option." << endl << endl;
		instructorOption2();
	} // if
} // instructorOption2


void instructorOption1() {
	string su = ""; // student username
	cout << endl << "Enter student username to view grades: ";
	cin >> su;
	Student inQuestion = theInstructors[isInstructor].getStudent(su);
	if (inQuestion.username != su) {
		cout << endl << "Student username is not valid" << endl;
		instructorOption1();
		return;
	} else {
		printStudent(inQuestion);
		isInstructor = 0;
		isLogin = 0;
		promptUser();
	} // if
} // instructorOption1

void promptInstructor() {
	string option;
	cout << "Query options," << endl << '\t' << "1 - view grades of a student" << endl << '\t' << "2 - view stats" << endl;
	cout << "Enter option number: ";
	cin >> option;
	if (!option.compare("1")) {
		instructorOption1();
	} else if (!option.compare("2")) {
		instructorOption2();
	} else {
		cout << endl << "Invalid option. Please enter a valid option." << endl << endl;
		promptInstructor();
	} // if
} // promptInstructor

void promptStudent(Student theStudent) {
	string temp;
	cout << "Do you want to view grades (y/n)? ";
	cin >> temp;
	if (!temp.compare("y")) {
		printStudent(theStudent);
		promptUser();
	} else { 
		promptUser();
	} // if
} // promptStudent

void promptLogin(int isInstructor) {
	string un;
	string pw;
	cout << "Enter credentials to login," << endl << '\t' << "Enter username: ";
	cin >> un;
	cout << '\t' << "Enter password: ";
	cin >> pw;
	cout << endl;
	if (isInstructor) {
		for (int i = 0; i < 3; i++) {
			if (un == theInstructors[i].uName) {
				isLogin = theInstructors[i].login(un, pw);
				if (isLogin) {
					isInstructor = i;
					cout << "You are now logged in as instructor " << theInstructors[i].fName << endl << endl;
					promptInstructor();
					return;
				} // if
			} // if
		} // for
		if (!isLogin) {
			cout << "Login as instructor failed." << endl << endl;
			promptLogin(1);
			return;
		} // if
	} else {
		for (int i = 0; i < 20; i++) {
			if (un == theStudents[i].username) {
				isLogin = theStudents[i].login(un, pw);
				if (isLogin) {
					promptStudent(theStudents[i]);
					return;
				} // if
			} // if
		} // for
		if (!isLogin) {
			cout << "Login as student failed." << endl << endl;
		} // if
	} // if
	if (!isLogin) {
		promptUser();
	} // if
} // promptLogin
		

void promptUser() {
	string userType;
	cout << "User types," << endl << '\t' << "1 - Instructor" << endl << '\t' << "2 - Student" << endl << "Select a login user type or enter 3 to exit: ";
	cin >> userType;
	if (!userType.compare("1")) {
		promptLogin(1);
	} else if (!userType.compare("2")) {
		promptLogin(0);
	} else if (!userType.compare("3")) {
		return;
	} else {
		cout << endl << "Invalid option. Please enter a valid option." << endl << endl;
		promptUser();
		return;
	} // if		
} // promptUser

int initializeInstructor(char *argv2) {
	FILE * iFile;
	int j = 0;
	char c;
	iFile = fopen(argv2, "r");
	if (iFile == NULL) {
		cout << "Error: cannot parse instructors information from file " << string(argv2) << endl;
		return 0;
	} // if
	string firstName;
	string lastName;
	string username;
	string password;
	string temp;
	while (!feof(iFile)) {
		for (int i = 0; i < 4; i++) {
			while ((c = fgetc(iFile)) != ' ' && c != '\t' && c != '\n' && !feof(iFile)) {
				temp = temp + c;
			} // while
			switch(i) {
				case 0:
					username = temp;
					break;
				case 1:
					password = temp;
					break;
				case 2: 
					firstName = temp;
					break;
				case 3:
					lastName = temp;
					break;
			} // switch
			temp = "";
		} // for
		theInstructors[j++] = Instructor(username, password, firstName, lastName, theStudents);
	} // while
	fclose(iFile);
	/*for (int i = 0; i < 3; i++) {
		theInstructors[i].getStudentArray(theStudents);
	} // for*/
	return 1;
} // initializeInstructor

int initializeStudent(char *argv1) {
	FILE * sFile;	
	sFile = fopen(argv1, "r");
	if (sFile == NULL) {
		cout << "Error: cannot parse students information from file " << string(argv1) << endl;
		return 0;
	} // if
	string firstName;
	string lastName;
	string username;
	string password;
	string temp;
	int finalGrade;
	int midtermGrade;
	int quizGrade;
	int projectGrade;
	int j = 0;
	char c;
	while (!feof(sFile)) {
		for (int i = 0; i < 8; i++) {
			while ((c = fgetc(sFile)) != ' ' && c != '\t' && c != '\n' && !feof(sFile)) {
				temp = temp + c;
			} // while
			switch(i) {
				case 0:
					username = temp;
					break;
				case 1:
					password = temp;
					break;
				case 2: 
					firstName = temp;
					break;
				case 3:
					lastName = temp;
					break;
				case 4:
					projectGrade = sti(temp);
					break;
				case 5:
					quizGrade = sti(temp);
					break;
				case 6:
					midtermGrade = sti(temp);
					break;
				case 7: 
					finalGrade = sti(temp);
					break;
			} // switch
			temp = "";
		} // for
		theStudents[j++] = Student(firstName, lastName, username, password, finalGrade, midtermGrade, quizGrade, projectGrade);
	} // while
	fclose(sFile);
	return 1;
} // initializeStudent

/**
 * initialize is going to return 1 if success and 0 if failure.
 * Failure should shortcircuit the program and cause an error.
 * @return 1 if worked and 0 if didnt initialize properly
 */
int initialize(char *argv2, char *argv1) {
	if (!initializeStudent(argv1)) {
		return 0;
	} // if
	if (!initializeInstructor(argv2)) {
		return 0;
	} // if
	return 1;
} // initialize

/**
 * This method converts strings to ints.
 * @param number the number it takes to make an int
 * @return the numerical value of the string.
 */
int sti(string number) {
	stringstream ss;
	int num;
	ss << number;
	ss >> num;
	return num;
} // sti
