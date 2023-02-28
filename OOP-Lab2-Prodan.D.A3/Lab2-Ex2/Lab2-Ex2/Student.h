#pragma once
#include <string>
#include <iostream>

using namespace std;

class Student {
private:
    string name;
    float mathGrade;
    float engGrade;
    float histGrade;

public:
    void setName(string name);
    string getName();

    void setMathGrade(float grade);
    float getMathGrade();

    void setEngGrade(float grade);
    float getEngGrade();

    void setHistGrade(float grade);
    float getHistGrade();

    float getAvgGrade();
};