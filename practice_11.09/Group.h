#pragma once
#include "Student.h"
#include "Subject.h"

class Group
{
    char* name;
    Student* students;
    int count_of_students;
    Subject* subjects;
    int count_of_subjects;

public:
    Group();
    Group(const char* n, int st_count, int sub_count);
    ~Group();

    void set_student(int index, Student s);
    Student& get_student(int index);

    void set_subject(int index, Subject s);
    Subject& get_subject(int index);

    double subject_average(int subj_index);
    double group_average();
    void max_min_subject(int subj_index);
    void print();
};