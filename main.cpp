#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "instructor.h"
#include <string>
#include <sstream>
#include <unistd.h>

using namespace std;
Student theStudents[100];
Instructor theInstructors[3];
bool isInstructor = 0;
bool isLogin = 0;

int initialize(char *argv1, char *argv2);
void getWord(string *toChange, FILE * stream);
int sti (string number);

void printStudent(Student person) {
	cout << person.username << " " << person.password << " " << person.getStudentName() << " " << person.getProjectGrade() << " " << person.getQuizGrade() << " " << person.getMidtermGrade() << " " << person.getFinalGrade() << endl;
} // printStudent
	

int main(int argc, char **argv) {
	initialize(argv[1], argv[2]);
	for (int i = 0; i < 20; i++) {
		printStudent(theStudents[i]);
		cout << endl;
	} // for
        return 0;
} // main

/**
 * initialize is going to return 1 if success and 0 if failure.
 * Failure should shortcircuit the program and cause an error.
 * @return 1 if worked and 0 if didnt initialize properly
 */
int initialize(char *argv1, char *argv2) {
	FILE * sFile;
	
	sFile = fopen(argv1, "r");
	if (sFile == NULL) {
		cout << "students.txt does not exist" << endl;
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
	j = 0;
	sFile = fopen(argv2, "r");
	if (sFile == NULL) {
		cout << "instructors.txt does not exist" << endl;
		return 0;
	} // if
	while (!feof(sFile)) {
		for (int i = 0; i < 4; i++) {
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
			} // switch
			temp = "";
		} // for
		//add instructor constructor lol
	} // while
	fclose(sFile);
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
