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
    const char* get_name();
    int get_count_of_marks() const;

    void set_mark(int index, int mark);
    int get_mark(int index);
    double average();

    void copy_from(const Student& other);

    void print();
};