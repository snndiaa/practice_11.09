#include "Group.h"
#include <iostream>
using namespace std;

Group::Group()
{
    name = nullptr;
    students = nullptr;
    subjects = nullptr;
    count_of_students = 0;
    count_of_subjects = 0;
}

Group::Group(const char* n, int st_count, int sub_count)
{
    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);

    count_of_students = st_count;
    count_of_subjects = sub_count;

    students = new Student[count_of_students];
    subjects = new Subject[count_of_subjects];
}

Group::~Group()
{
    delete[] name;
    delete[] students;
    delete[] subjects;
}

void Group::set_student(int index, Student s)
{
    if (index >= 0 && index < count_of_students)
    {
        students[index].copy_from(s);
    }
}

Student& Group::get_student(int index)
{
    return students[index];
}

void Group::set_subject(int index, Subject s)
{
    if (index >= 0 && index < count_of_subjects)
    {
        subjects[index].copy_from(s);
    }
}

Subject& Group::get_subject(int index)
{
    return subjects[index];
}

double Group::subject_average(int subj_index)
{
    int sum = 0;
    for (int i = 0; i < count_of_students; i++)
    {
        sum += students[i].get_mark(subj_index);
    }
    if (count_of_students > 0)
    {
        return static_cast<double>(sum) / count_of_students;
    }
    return 0;
}

double Group::group_average()
{
    double sum = 0;
    for (int i = 0; i < count_of_students; i++)
    {
        sum += students[i].average();
    }
    if (count_of_students > 0)
    {
        return sum / count_of_students;
    }
    return 0;
}

void Group::max_min_subject(int subj_index)
{
    int max_grade = students[0].get_mark(subj_index);
    int min_grade = students[0].get_mark(subj_index);
    int max_index = 0;
    int min_index = 0;

    for (int i = 1; i < count_of_students; i++)
    {
        int g = students[i].get_mark(subj_index);
        if (g > max_grade)
        {
            max_grade = g;
            max_index = i;
        }
        if (g < min_grade)
        {
            min_grade = g;
            min_index = i;
        }
    }

    cout << "Subject " << subjects[subj_index].get_name()
        << " max: " << students[max_index].get_name() << " (" << max_grade << ")"
        << ", min: " << students[min_index].get_name() << " (" << min_grade << ")" << endl;
}

void Group::print()
{
    cout << "Group: " << name << endl;
    cout << "Subjects: ";
    for (int i = 0; i < count_of_subjects; i++)
    {
        cout << subjects[i].get_name() << " ";
    }
    cout << endl;

    for (int i = 0; i < count_of_students; i++)
    {
        students[i].print();
    }

    cout << "Group average: " << group_average() << endl;

    for (int j = 0; j < count_of_subjects; j++)
    {
        cout << "Average for " << subjects[j].get_name() << " = " << subject_average(j) << endl;
        max_min_subject(j);
    }
}