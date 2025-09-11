#include "Student.h"
#include <cstring>

Student::Student()
{
    name = nullptr;
    marks = nullptr;
    count_of_marks = 0;
}

Student::Student(const char* n, int count)
{
    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
    count_of_marks = count;
    marks = new int[count_of_marks];
    for (int i = 0; i < count_of_marks; i++)
    {
        marks[i] = 0;
    }
}

Student::~Student()
{
    delete[] name;
    delete[] marks;
}

void Student::set_name(const char* n)
{
    if (name != nullptr)
    {
        delete[] name;
    }
    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
}

const char* Student::get_name()
{
    return name;
}

int Student::get_count_of_marks() const
{
    return count_of_marks;
}

void Student::set_mark(int index, int mark)
{
    if (index >= 0 && index < count_of_marks)
    {
        marks[index] = mark;
    }
}

int Student::get_mark(int index)
{
    if (index >= 0 && index < count_of_marks)
    {
        return marks[index];
    }
    return 0;
}

double Student::average()
{
    int sum = 0;
    for (int i = 0; i < count_of_marks; i++)
    {
        sum += marks[i];
    }
    if (count_of_marks > 0)
    {
        return static_cast<double>(sum) / count_of_marks;
    }
    return 0;
}

void Student::copy_from(const Student& other)
{
    if (name != nullptr)
    {
        delete[] name;
    }
    if (marks != nullptr)
    {
        delete[] marks;
    }

    if (other.name != nullptr)
    {
        name = new char[strlen(other.name) + 1];
        strcpy_s(name, strlen(other.name) + 1, other.name);
    }
    else
    {
        name = nullptr;
    }

    count_of_marks = other.count_of_marks;
    if (count_of_marks > 0 && other.marks != nullptr)
    {
        marks = new int[count_of_marks];
        for (int i = 0; i < count_of_marks; i++)
        {
            marks[i] = other.marks[i];
        }
    }
    else
    {
        marks = nullptr;
    }
}

void Student::print()
{
    cout << name << ": ";
    for (int i = 0; i < count_of_marks; i++)
    {
        cout << marks[i] << " ";
    }
    cout << "Average: " << average() << endl;
}