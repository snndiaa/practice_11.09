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
    if (this->name != nullptr)
    {
        delete[] this->name;
    }
    this->name = new char[strlen(n) + 1];
    strcpy_s(this->name, strlen(n) + 1, n);
}

char* Student::get_name()
{
    return this->name;
}

void Student::set_mark(int index, int mark)
{
    if (index >= 0 && index < count_of_marks)
    {
        this->marks[index] = mark;
    }
}

int Student::get_mark(int index)
{
    if (index >= 0 && index < count_of_marks)
    {
        return this->marks[index];
    }
    return 0;
}

double Student::average()
{
    int sum = 0;
    for (int i = 0; i < count_of_marks; i++)
    {
        sum += this->marks[i];
    }
    if (count_of_marks > 0)
    {
        return (double)sum / count_of_marks;
    }
    return 0;
}

void Student::print()
{
    cout << this->name << ": ";
    for (int i = 0; i < count_of_marks; i++)
    {
        cout << this->marks[i] << " ";
    }
    cout << "Average: " << this->average() << endl;
}
