#pragma once
#include <iostream>
using namespace std;

class Subject
{
    char* name;

public:
    Subject();
    Subject(const char* n);
    ~Subject();

    void set_name(const char* n);
    char* get_name();

    void print();
};
