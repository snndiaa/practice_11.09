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

void Subject::set_name(const char* n)
{
    if (this->name != nullptr)
    {
        delete[] this->name;
    }
    this->name = new char[strlen(n) + 1];
    strcpy_s(this->name, strlen(n) + 1, n);
}

char* Subject::get_name()
{
    return this->name;
}

void Subject::print()
{
    cout << this->name << endl;
}
