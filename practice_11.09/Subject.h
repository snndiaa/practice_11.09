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
    const char* get_name();

    void copy_from(const Subject& other);

    void print();
};