#include "Student.h"

void Student::setName(string name) {
    this->name = name;
}

string Student::getName() {
    return name;
}

void Student::setMathGrade(float grade) {
    if (grade > 10 or grade < 0) { mathGrade = 0; }
    else mathGrade = grade;
}

float Student::getMathGrade() {
    return mathGrade;
}

void Student::setEngGrade(float grade) {
    if (grade > 10 or grade < 0) { engGrade = 0; }
    else engGrade = grade;
}

float Student::getEngGrade() {
    return engGrade;
}

void Student::setHistGrade(float grade) {
    if (grade > 10 or grade < 0) { histGrade = 0; }
    else histGrade = grade;
}

float Student::getHistGrade() {
    return histGrade;
}

float Student::getAvgGrade() {
    return (mathGrade + engGrade + histGrade) / 3.0;
}