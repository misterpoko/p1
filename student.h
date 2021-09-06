#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student {
	public:
		string fullName;
        	string username;
        	string password;        
		int projectGrade;
        	int quizGrade;
        	int midtermGrade;
        	int finalGrade;
        	int getProjectGrade();
        	int getQuizGrade();
        	int getMidtermGrade();
        	int getFinalGrade();
        	double getOverallGrade();
        	string getStudentName();

		Student();
		Student(string fn, string ln, string un, string pw, int fg, int mg, int qg, int pg);
        	bool login(string username, string password);
};

#endif
