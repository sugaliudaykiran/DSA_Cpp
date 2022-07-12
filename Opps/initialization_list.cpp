#include<bits/stdc++.h>
using namespace std;
 
class student
{
    int age;
    public:
    
    int const rollno;   //  Initilization list..
    int &j;

    // Initialization list :- which declare 'const members and reference member' while memory declaration of object.
    student(int age, int rollno) : age(age), rollno(rollno), j(this -> age)
    {
        cout << "initilize..list of const and refernce members" << "\n";
    }

    void display()
    {
       cout << this -> age << " " << this -> rollno << "\n";
    }


};


int32_t main()
{
    // Initialization list :- which declare 'const members and reference member' while memory declaration of object.
    student s4(21, 2001);

    cout << s4.j << "\n"; 
    return 0;
}