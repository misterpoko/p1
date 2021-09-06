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

Student(string fName, string lName, string uName, string pw, int fg, int mg, int qg, int pg) {
	fullName = fName + " " + lName;
        username = uName;
        password = pw;
        finalGrade = fg;
        midtermGrade = mg;
        quizGrade = qg;
        projectGrade = pg;
} // student

string getStudentName() {
        return fullName;
} // getStudentName

int getProjectGrade() {
        return projectGrade;
} // getProjectGrade

int getQuizGrade() {
        return quizGrade;
} // getQuizGrade

int getMidtermGrade() {
        return midtermGrade;
} // getMidtermGrade

int getFinalGrade() {
        return finalGrade;
} // getFinalGrade

double getOverallGrade() {
        double sum = 0;
        sum += (.3 * projectGrade);
        sum += (.1 * quizGrade);
        sum += (.2 * midtermGrade);
        sum += (.4 * finalGrade);
        return sum;
} // getOverallGrade

bool login(string un, string pw) {
       if (!username.compare(un) && !password.compare(pw)) {
                return true;
       } // if
       return false;
} // login
