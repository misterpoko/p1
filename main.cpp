#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "instructor.h"
#include <string>
#include <sstream>
#include <unistd.h>

using namespace std;
Student theStudents[20];//student array
Instructor theInstructors[3];//instructors array 
bool isInstructor = 0; //which instructor it is.
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

/**
 * This takes in arguments and creates the flow of methods. Shortcircuits if given bad files or not 2 arguments
 * @param argc the amount of args
 * @param argv the filenames
 * @return whether or not the operation succeeded.
 */
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

/**
 * This prints student information used in student option and instructor view of a singular student.
 * @param person The student in question
 */
void printStudent(Student person) {
//this is formatting for print statements
	cout << endl;
	cout << "Student name: " << person.fullName << endl << '\t' << "Project " << person.getProjectGrade() << "%" << endl;
	cout << '\t' << "Quiz    " << person.getQuizGrade() << "%" << endl << '\t' << "Midterm " << person.getMidtermGrade();
	cout << "%" << endl << '\t' << "Final   "  << person.getFinalGrade() << "%" << endl << '\t' << "Overall ";
	cout << person.getOverallGrade() << "%" << endl << endl;
} // printStudent

/**
 * This method prints the output for the viewstats command for the instructor.
 * @param gradeType which grade type to print stats for
 */
void printOption2(int gradeType) {
	string type;
	Student min = theInstructors[isInstructor].getMinStudent(gradeType);
	Student max = theInstructors[isInstructor].getMaxStudent(gradeType);
	int minGrade;
	int maxGrade;
	double avgGrade = theInstructors[isInstructor].getAvg(gradeType);
	isLogin = 0;
	isInstructor = 0;
	//switch cases for assignment grades 
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
			//formatting for print statments  specificlly for overall grades due to type changes 
			type = "Overall";
			cout << endl << type << " grade stats," << endl << '\t' << "min" << '\t' <<  min.getOverallGrade() << "% (" << min.fullName << ")" << endl;
			cout << '\t' << "max" << '\t' <<  max.getOverallGrade() << "% (" << max.fullName << ")" << endl;
			cout << '\t' << "avg" << '\t' << avgGrade << "%" << endl << endl;
			return;
	} // switch

	//formatting for view stats 
	cout << endl << type << " grade stats," << endl << '\t' << "min" << '\t' <<  minGrade << "% (" << min.fullName << ")" << endl;
	cout << '\t' << "max" << '\t' <<  maxGrade << "% (" << max.fullName << ")" << endl;
	cout << '\t' << "avg" << '\t' << avgGrade << "%" << endl << endl;
} // printOption2

/**
 * This method prints the viewstats option for instructor and directs its flow to print the results of the method using printOption2.
 * It also error checks if given an invalid option.
 */
void instructorOption2() {
	//formating for the menu of view stats 
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
		cout << endl << "Invalid option. Please enter a valid option." << endl;
		instructorOption2();
	} // if
} // instructorOption2

/**
 * This method prints the viewstudent and errorchecks if given an invalid option.
 */
void instructorOption1() {
	string su = ""; // student username
	cout << endl << "Enter student username to view grades: ";
	cin >> su;
	Student inQuestion = theInstructors[isInstructor].getStudent(su);
	//gets student method creates a student if they don't exist so error checks by comparing usernames they should not be the same.
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

/**
 * This method is what follows after logging in. It gives the instructor 2 options of viewing stats and viewing a certain student.
 * It also prints it.
 */
void promptInstructor() {
	string option;
	//formatting menu for instructor
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

/**
 * This method prompts the student with the option to look at individual grades after logging in as a student.
 * @param theStudent the student whose grades we can view
 */
void promptStudent(Student theStudent) {
	string temp;
	cout << "Do you want to view grades (y/n)? ";
	cin >> temp;
	cout << endl;
	if (!temp.compare("y")) {
		printStudent(theStudent);
		promptUser();
	} else { 
		promptUser();
	} // if
} // promptStudent

/**
 * This prompts for a login and error checks to see if they were using valid credentials.
 * @param isInstructor gives if an instructor is attempting a log in and which one.
 */
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
					cout << "You are now logged in as instructor " << theInstructors[i].fName << "\n\n";
					promptInstructor();
					return;
				} // if
			} // if
		} // for
		if (!isLogin) {
			cout << "Login as instructor failed." << endl << endl;
			promptUser();
			return;
		} // if
	} else {
		for (int i = 0; i < 20; i++) {
			if (un == theStudents[i].username) {
				isLogin = theStudents[i].login(un, pw);
				if (isLogin) {
					cout << "You are now logged in as student " << theStudents[i].fullName << endl << endl;
					promptStudent(theStudents[i]);
					return;
				} // if
			} // if
		} // for
		if (!isLogin) {
			cout << "Login as student failed." << endl << endl;
			promptUser();
			return;
		} // if
	} // if
	if (!isLogin) {
		promptUser();
	} // if
} // promptLogin
		
/**
 * This prompts the user with the initial option of the ability to log in to a student or an instructor.
 */
void promptUser() {
	string userType;
	//formatting for initial menu for who to login 
	cout << "User types," << endl << '\t' << "1 - Instructor" << endl << '\t' << "2 - Student" << endl << "Select a login user type or enter 3 to exit: ";
	cin >> userType;
	cout << endl;
	if (!userType.compare("1")) {
		promptLogin(1);
	} else if (!userType.compare("2")) {
		promptLogin(0);
	} else if (!userType.compare("3")) {
		return;
	} else {
		cout << "Invalid option. Please enter a valid option." << endl << endl;
		promptUser();
		return;
	} // if		
} // promptUser

/**
 * This takes in a char array and makes it into a file which initializes the instructor array instance variable for future use.
 * @param argv2 the first argument passed through main.
 * @return whether or not the instructorsarray were successfully initialized. 0 is failure 1 is success
 */
int initializeInstructor(char *argv2) {
	FILE * iFile;
	int j = 0;
	char c;
	iFile = fopen(argv2, "r");//opening text file
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

/**
 * This takes in a char array and makes it into a file which initializes the student array instance variable for future use.
 * @param argv1 the second argument passed through main.
 * @return whether or not the students sarray were successfully initialized. 0 is failure 1 is success
 */
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
	if (!isdigit(number.at(0))) {
		return -243;
	} // if
	stringstream ss;
	int num;
	ss << number;
	ss >> num;
	return num;
} // string
