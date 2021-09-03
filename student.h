#include <iostream>
#include <string>
using namespace std;

class Student {
private:
        string fullName;
        string username;
        string password;
        int projectGrade;
        int quizGrade;
        int midtermGrade;
        int finalGrade;

public:
        bool login(string username, string password);
        string getStudentName();
        int getProjectGrade();
        int getQuizGrade();
        int getMidtermGrade();
        int getFinalGrade();
        double getOverallGrade();
};
