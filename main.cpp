#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "instructor.h"

using namespace std;

student* theStudents;
instructor* theInstructors;
bool isInstructor = 0;
bool isLogin = 0;

int main() {
        return 0;
} // main

/**
 * initialize is going to return 1 if success and 0 if failure.
 * Failure should shortcircuit the program and cause an error.
 * @return 1 if worked and 0 if didnt initialize properly
 */
int initialize() {
	string temp;
	FILE * students;
	
	students = fopen("students.txt", "r");
	if (students == NULL) {
		cout << "students.txt does not exist" << endl;
		return 0;
	} // if
	/*while (!feof(students)) {
		//doSomething
		fgets
	} // while
	fclose()
	
*/
	// do this for instructors
	//
	return 1;
} // initialize
