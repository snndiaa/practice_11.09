#include "Subject.h"
#include <cstring>

Subject::Subject()
{
    name = nullptr;
}

Subject::Subject(const char* n)
{
    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
}

Subject::~Subject()
{
    delete[] name;
}

Subject::Subject(const Subject& other)
{
    name = nullptr;
    copy_from(other);
}

void Subject::set_name(const char* n)
{
    if (name != nullptr)
    {
        delete[] name;
    }
    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
}

const char* Subject::get_name()
{
    return name;
}

void Subject::copy_from(const Subject& other)
{
    if (name != nullptr)
    {
        delete[] name;
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
}

void Subject::print()
{
    cout << name << endl;
}