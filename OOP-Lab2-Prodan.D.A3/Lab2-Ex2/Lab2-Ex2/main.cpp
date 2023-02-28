#include "Student.h"
#include "GlobalF.h"
#include <iostream>

using namespace std;

int main()
{
	Student s1;

	s1.setName("Daniel");
	s1.setMathGrade(10);
	s1.setEngGrade(10);
	s1.setHistGrade(10);
	
	Student s2;

	s2.setName("Denis");
	s2.setMathGrade(10);
	s2.setEngGrade(10);
	s2.setHistGrade(10);

	cout << "Nota la mate al studentului " << s1.getName() << " este " << s1.getMathGrade();
	cout << endl;
	cout << "Nota la engleza al studentului " << s1.getName() << " este " << s1.getEngGrade();
	cout << endl;
	cout << "Nota la istorie al studentului " << s1.getName() << " este " << s1.getHistGrade();
	cout << endl;

	cout << "Nota la mate al studentului " << s2.getName() << " este " << s2.getMathGrade();
	cout << endl;
	cout << "Nota la engleza al studentului " << s2.getName() << " este " << s2.getEngGrade();
	cout << endl;
	cout << "Nota la istorie al studentului " << s2.getName() << " este " << s2.getHistGrade();
	cout << endl;

	cout << "Este " << s1.getName() << " mai bun la mate decat " << s2.getName() << "? (-1, 0, 1)   " << compareMathGrades(s1, s2);
	cout << endl;
	cout << "Este " << s1.getName() << " mai bun la engleza decat " << s2.getName() << "? (-1, 0, 1)   " << compareEngGrades(s1, s2);
	cout << endl;
	cout << "Este " << s1.getName() << " mai bun la istorie decat " << s2.getName() << "? (-1, 0, 1)   " << compareHistGrades(s1, s2);
	cout << endl;

	cout << "Media lui " << s1.getName() << " este " << s1.getAvgGrade();
	cout << endl;
	cout << "Media lui " << s2.getName() << " este " << s2.getAvgGrade();
	cout << endl;

	cout << "Este media lui " << s1.getName() << " mai mare decat a lui " << s2.getName() << "? (-1, 0, 1)   " << compareAvgGrades(s1, s2);
	cout << endl;

	return 1;
}