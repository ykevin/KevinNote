
#include <iostream>

using namespace std;

class Advisor {
	int noOfMeeting;
public :
	Advisor() {
		cout << "Advisor\n";
	}
	Advisor(const Advisor&) {
		cout << "copy Advisor\n";
	}
	~Advisor() {
		cout << "~Advisor\n";
	}
};

class Student {
	string name;
	int semesterHours;
	double average;
public :
	Student(string pName="noName"):name(pName),average(0), semesterHours(0){}
	void addCourse(int hours, double grade) {
		double totalGrade = (semesterHours * average + grade);
		semesterHours += hours;
		average = semesterHours ? totalGrade/semesterHours : 0;
	}

	void display() {
		cout << "name = \""  << name << "\""  << ", hours=" << semesterHours << ", average="<< average << " ";
	}
	
	int getHours() {
		return semesterHours;
	}

	double getAverage() {
		return average;
	}

	~Student() { cout << "~Student\n";
	}
};

class GraduateStudent : public Student {
	Advisor advisor;
	int qualifierGrade;
public :
	GraduateStudent (const string& pN, Advisor& adv):Student(pN), advisor(adv), qualifierGrade(0){}
	void display() {
		Student::display();
		cout << "GraduateStudent\n";
	}
	int getQualifier() {
		return qualifierGrade;
	}
};

void fn(Advisor &advisor) {
	GraduateStudent gs("Yen Kay Doodle", advisor);
	gs.display();
}

int main(void) {
	Advisor da;
	fn(da);
	return 0;
}
