#include "Group.h"
#include "Student.h"
#include "Subject.h"
#include <iostream>
using namespace std;

int main()
{
    Group group1("KN-P-241", 2, 2);

    Student s1("Vanya", 2);
    s1.set_mark(0, 90);
    s1.set_mark(1, 80);

    Student s2("Arina", 2);
    s2.set_mark(0, 100);
    s2.set_mark(1, 95);

    group1.set_student(0, s1);
    group1.set_student(1, s2);

    Subject sub1("OOP");
    Subject sub2("English");

    group1.set_subject(0, sub1);
    group1.set_subject(1, sub2);

    group1.print();

    return 0;
}