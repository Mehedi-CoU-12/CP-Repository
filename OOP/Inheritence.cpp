#include<bits/stdc++.h>
using namespace std;

class Person{
    public:
    string name;
    int age;

    Person(string name,int age){
        this->name=name;
        this->age=age;
    }
};

class Student:public Person{
    public:
    int roll;

    Student(string name,int age,int roll):Person(name,age){
        this->roll=roll;
    }

    void getInfo(){
        cout<<"name: "<<name<<endl;
        cout<<"age: "<<age<<endl;
        cout<<"roll: "<<roll<<endl;
    }
};

int main(){

    Student std("mehedi",24,12008048);
    std.getInfo();
}