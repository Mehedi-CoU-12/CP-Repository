/*
static use kore kore kono variable decleare korle oita memory te ekbarei create hoy.
*/

#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    static int value;
    Student()
    {
        value++;
    }
};

int Student::value = 0;

int main()
{
    Student s1, s2, s3;
    cout << Student::value << s1.value << endl; // value will be 3.
}