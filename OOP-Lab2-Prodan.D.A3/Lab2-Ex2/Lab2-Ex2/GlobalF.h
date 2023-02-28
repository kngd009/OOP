#pragma once
#include "Student.h"

int compareNames(Student s1, Student s2) {
    return 0;
}

int compareMathGrades(Student s1, Student s2) {
    if (s1.getMathGrade() == s2.getMathGrade()) {
        return 0;
    }
    if (s1.getMathGrade() > s2.getMathGrade()) {
        return 1;
    }
    else return -1;
}

int compareEngGrades(Student s1, Student s2) {
    if (s1.getEngGrade() == s2.getEngGrade()) {
        return 0;
    }
    if (s1.getEngGrade() > s2.getEngGrade()) {
        return 1;
    }
    else return -1;
}

int compareHistGrades(Student s1, Student s2) {
    if (s1.getHistGrade() == s2.getHistGrade()) {
        return 0;
    }
    if (s1.getHistGrade() > s2.getHistGrade()) {
        return 1;
    }
    else return -1;
}

int compareAvgGrades(Student s1, Student s2) {
    if (s1.getAvgGrade() == s2.getAvgGrade()) {
        return 0;
    }
    if (s1.getAvgGrade() > s2.getAvgGrade()) {
        return 1;
    }
    else return -1;
}