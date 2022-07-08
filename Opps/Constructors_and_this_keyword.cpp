#include<bits/stdc++.h>
using namespace std;

class student
{
    public:
    int rollno;

    private:
    int age;

    public:

    ~student()  //  Destructor :-  same name as class name, No input argument, No return type.. calls when the object gets existing the scope of it..
    {
        cout << "Destructor is called..!" << "\n";
    }

    student()   // Default construtor :-     Same as Class name, No return type, No Input argument..
    {
        cout << "This is default Constructor.. " << "\n";
    }

    student(int r)
    {
        rollno = r;
        cout << "This is constructor2..." << "\n";
    }

    student(int r, int a)   //  Friendly or Generally Public function can also access the private memeber of the class..
    {
        cout << "This is constructor3..." << "\n";
        this -> rollno = r;
        this -> age = a;
    }

    void display()
    {
        cout << "rollno :" << rollno << " " << "age :" << age << "\n";
    }
};


int32_t main()
{
    student s1(101, 21);

    // s1.display();

    student *s2 = new student(102, 21);

    // (*s2).display();

    student s3(*s2);    //  Copy Constructor..

    student *s4 = new student(s1);  //  In copying the dynamic..alloction.

    s3.display();

    s4 -> display();

    student s5(104, 21);
    s5 = (*s2);        //  Using 'copy assignment operator', in inside it's called copy constructor.. like :- student s5 = s2;

    student *s6 = new student(105, 21);
    (*s6) = s1;     //  Here already existing objet copied from the other existing object..

    //  In case of dynamic type we need to delete and further destructor is called..

    delete s6;
    delete s4;
    delete s2;
}