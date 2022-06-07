#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    int i = 10;
    cout << &i << endl;         //  Address of -> &
    
    int *p = &i;    //  Pointer are variables which stores address of another variables
    cout << p << endl;

    cout << *p << endl;     //  Deference (or) Gets the value of 'i' (or) Given me value pointed by 'p'..
    cout << i << endl;

    (*p)++;     //  Update the value of 'i' by pointer also..   which pointing to address of 'i'
    cout << *p << endl;
    cout << i << endl;

    int *q = p;         //  we can use another pointer to store the address of a pointer also..
    cout << q << endl;
    cout << *q << endl;

    (*q)++;
    cout << i << endl;      //  it make change to the 'i', because it pointing the address of 'i'..

    cout << sizeof(p) << endl;  //  to known the size of 'p'
    
    int a = *p;
    a++;
    cout << i << endl;  //  It won't effect the value of 'i', because a is not pointing to 'i'..
    cout << a << endl;  //  But 'a' is assigned by the value 'i'..


    //  We can also assign value of 'i' by direct way (or) pointer of it..
    i = 15;
    cout << *p << endl;
    
    *p = 23;
    cout << i << endl;

    //  We can also increment the value of 'i' by --->  (*p)++;
    
    int *x = p;
    cout << *x << endl;
    cout << i << endl;
}

/*

    float f;
    float *pf = &f;

    char ch;
    char *pch = &ch;

    double d;
    double *pd = &d;


------------------------------>
    Pointer Arithematic     :-

        int a = 7;
        int *c = &a;
        c = c+1;            //  In case of integer it will add 4 bits to address of 'a'.. which be a garbage_value..
        cout << a <<" "<<  c << endl;       //  In case of double = 8 bits, char = 1 bit..

    O/p :-  7  Garbage_value

    In case of arrays the pointer is pointing to arr. if we increment the p = p+1; then it will point to 
        next value of the array.. similiar we can increment (or) decrement by 'i' value of array.
    ** We can compare the one pointer with another pointer in arrays.. like p1 < p2..


*/ 