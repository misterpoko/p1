#include <iostream>
#include <string>
using namespace std;

class student {
        string fullName;
        string username;
        string password;
        int finalGrade;
        int midtermGrade;
        int quizGrade;
        int projectGrade;

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
        public:
        student(string fn, string ln, string un, string pw, int fg, int mg, int qg, int pg) {
                fullName = fn + " " + ln;
                username = un;
                password = pw;
                finalGrade = fg;
                midtermGrade = mg;
                quizGrade = qg;
                projectGrade = pg;
        } // student;
        bool login(string un, string pw) {
                if (!username.compare(un) && !password.compare(pw)) {
                        return true;
                } // if
                return false;
        } // login
}; // student
