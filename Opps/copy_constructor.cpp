#include<bits/stdc++.h>
using namespace std;
 
class student
{
    int age;
    char *name;
   
    public:
    student(int age, char *name)
    {
        this -> age = age;
        // this -> name = name;        // Shallow copy :- Two or more object are pointing to same member..

        this -> name = new char[strlen(name)+1];
        strcpy(this -> name, name);     //  Deep copy :- Create an new member to every object and copy from the given object..
    }
    

    student(student const &s)      //  But here it exclipt performs the shallow copy to avoid it, we use the 'const refernce'..
    {
        this -> age = s.age;
        this -> name = new char[strlen(s.name)+1];    //  to include '\0'
        strcpy(this -> name, s.name);
    }


    void display()
    {
       cout << this -> age << " " << this -> name << "\n";
    }


};


int32_t main()
{
    char name[] = "abcd";

    student s1(21, name);
    s1.display();

    name[0] = 'x';
    student s2(22, name);
    s1.display();
    s2.display();

    //  Copy Constructor :- In copy assignment, copy construtor exclipt implement in it,.

    student s3(s1); 
    s3.display();   //  Here we create implcit copy constructor..

    return 0;
}