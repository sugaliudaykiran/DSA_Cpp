#include<bits/stdc++.h>
using namespace std;
 
class student
{
    public:
    
    int age, rollno;
    static int totalstudent;    //  static member.. which can be accessed by class not by objects, in that it will be logical error.

    student (int age, int rollno)
    {
        this -> age = age;
        this -> rollno = rollno;

        totalstudent++;
    }
    
    void display()
    {
       cout << this -> age << " " << this -> rollno << "\n";
    }

    static int getTotalStudent()     //  Static Function..  properities are which can't accessed by object, doesn't involue any non-static members in it..
    {
        return totalstudent;
    }
};

int student :: totalstudent = 0;    //  :: -> Scope resolution and it is initization of static member..

int32_t main()
{

    student s1(21, 1);
    student s2(21, 2);
    student s3(21, 3);

    cout << student::totalstudent << "\n";  //  static Member..

    cout << student::getTotalStudent() << "\n"; //  Static Function..

    return 0;
}