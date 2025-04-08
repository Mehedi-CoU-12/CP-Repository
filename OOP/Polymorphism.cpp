#include<bits/stdc++.h>
using namespace std;

/*
                               polymorphism
                  __________________|___________________
                  |                                    |
            compile time(overloading)               run time(overriding)
        _________|_________________                     |
        |                          |
    function overloading  operator overloading     virtual function   
*/

//function overloading
class Mehedi{
    public:
    void fun(){
        cout<<"this is a function without arguments"<<endl;
    }

    void fun(int a){
        cout<<"this is a function with arguments "<<a<<endl; 
    }

    void fun(double a){
        cout<<"this is a function with arguments "<<a<<endl; 
    }
};

//operator overloading
class Complex{
    int real,img;
public:
    Complex(int a=0,int b=0){
        real=a;
        img=b;
    }

    //operator overloading
    Complex operator +(Complex const&obj){
        Complex res;

        // cout<<real<<" "<<img<<endl;
        // cout<<obj.real<<" "<<obj.img<<endl;

        res.real=real+obj.real;
        res.img=img+obj.img;
        return res;
    }

    void display(){
        cout<<real<<"+i"<<img<<endl;
    }
};

//runtime polymorphism;
class base{
    public:
    virtual void print(){
        cout<<"this is a base class print function"<<endl;
    }

    virtual void display(){
        cout<<"this is a base class display function"<<endl;
    }
};

class derived:public base{
    public:
    void print(){
        cout<<"this is a derived class print function"<<endl;
    }

    void display(){
        cout<<"this is a derived class display function"<<endl;
    }
};

int main()
{
    //function overloading
    // Mehedi obj;
    // obj.fun();
    // obj.fun(4);
    // obj.fun(5.6);

    //opertor overloading
    // Complex c1(1,3),c2(2,4);
    // Complex c3=c1+c2;
    // c3.display();


    //runtime polymorphism
    // base *basePtr;
    // derived derivedObj;

    // basePtr=&derivedObj;

    // basePtr->print();
    // basePtr->display();
}