#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "instructor.h"
#include <string>
#include <sstream>

using namespace std;

Student *theStudents[20];
instructor theInstructors[3];
bool isInstructor = 0;
bool isLogin = 0;

int initialize();
void getWord(string *toChange, FILE * stream);
int sti (string number);

int main() {
	Student("tim", "hansen", "nop", "pw", 96, 54 ,37, 26);
	initialize();
        return 0;
} // main

/**
 * initialize is going to return 1 if success and 0 if failure.
 * Failure should shortcircuit the program and cause an error.
 * @return 1 if worked and 0 if didnt initialize properly
 */
int initialize() {
	FILE * sFile;
	
	sFile = fopen("./students.txt", "r");
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
	while (!feof(sFile)) {
		for (int i = 0; i < 8; i++) {
			switch(i) {
				case 0: 
					getWord(&firstName, sFile);
				case 1:
					getWord(&lastName, sFile);
				case 2:
					getWord(&username, sFile);
				case 3:
					getWord(&password, sFile);
				case 4: 
					getWord(&temp, sFile);
					finalGrade = sti(temp);
					temp = "";
				case 5:
					getWord(&temp, sFile);
					midtermGrade = sti(temp);
					temp = "";
				case 6:
					getWord(&temp, sFile);
					quizGrade = sti(temp);
					temp = "";
				case 7:
					getWord(&temp, sFile);
					projectGrade = sti(temp);
					temp = "";
			} // switch
		} // for
//		theStudents[j++] = new Student(firstName, lastName, username, password, finalGrade, midtermGrade, quizGrade, projectGrade);
	} // while
	fclose(sFile);
	
	// do this for instructors
	//
	return 1;
} // initialize

void getWord(string *toChange, FILE *stream) {
	char c;
	while ((c =fgetc(stream)) != '\0' || c != ' ')  {
		*toChange = *toChange + c;
	} // for
} // getWord

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
