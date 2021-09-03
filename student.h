#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class student {
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

#endif
