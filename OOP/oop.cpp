#include<bits/stdc++.h>
using namespace std;

class Person{
    string first,last;
    
    public:
    Person()=default;
    
    Person(string first,string last)
    {
        this->first=first;
        this->last=last;
    }

    string getFullName(){
        return first+" "+last;
    }

    virtual void printInfo(){
        cout<<"Name: "<<getFullName()<<endl;
    }
};

class Employee:public Person{

    string dept;

    public:
    Employee()=default;
    Employee(string first,string last,string dept):Person(first,last){
        this->dept=dept;
    }

    void printInfo()override{
        cout<<"Name: "<<getFullName()<<endl;
        cout<<"Department: "<<dept<<endl;
    }
};

int main()
{
    vector<Person*>people;
    Person p("jobaer","hasan");
    Employee e("mehedi","hasan","cse");
    // e1.printInfo();

    people.push_back(&p);
    people.push_back(&e);

    for(auto person:people)
    {
        person->printInfo();
    }
}