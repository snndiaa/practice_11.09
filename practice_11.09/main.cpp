#include "Group.h"
#include "Student.h"
#include "Subject.h"
#include <iostream>
using namespace std;

int main()
{
    Group group1("CS101", 2, 3);

    Student s1("Alice", 3);
    s1.set_mark(0, 90);
    s1.set_mark(1, 80);
    s1.set_mark(2, 85);

    Student s2("Bob", 3);
    s2.set_mark(0, 70);
    s2.set_mark(1, 95);
    s2.set_mark(2, 60);

    group1.set_student(0, s1);
    group1.set_student(1, s2);

    Subject sub1("Math");
    Subject sub2("Physics");
    Subject sub3("English");

    group1.set_subject(0, sub1);
    group1.set_subject(1, sub2);
    group1.set_subject(2, sub3);

    group1.print();

    return 0;
}
