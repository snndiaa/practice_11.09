#pragma once
#include <iostream>
using namespace std;

class Student
{
    char* name;
    int* marks;
    int count_of_marks;

public:
    Student();
    Student(const char* n, int count);
    ~Student();

    void set_name(const char* n);
    char* get_name();

    void set_mark(int index, int mark);
    int get_mark(int index);
    double average();

    void print();
};
