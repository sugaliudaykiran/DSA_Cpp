#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
//     int i = 10;
//     cout << &i << endl;         //  Address of -> &
    
//     int *p = &i;    //  'Pointer' are variables which stores address of another variables
//     cout << p << endl;

//     cout << *p << endl;     //  Deference (or) Gets the value of 'i' (or) Given me value pointed by 'p'..
//     cout << i << endl;

//     (*p)++;     //  Update the value of 'i' by pointer also..   which pointing to address of 'i'
//     cout << *p << endl;
//     cout << i << endl;

//     int *q = p;         //  we can use another pointer to store the address of a pointer also..
//     cout << q << endl;
//     cout << *q << endl;

//     (*q)++;
//     cout << i << endl;      //  it make change to the 'i', because it pointing the address of 'i'..

//     cout << sizeof(p) << endl;  //  to known the size of 'p'
    
//     int a = *p;
//     a++;
//     cout << i << endl;  //  It won't effect the value of 'i', because a is not pointing to 'i'..
//     cout << a << endl;  //  But 'a' is assigned by the value 'i'..


//     //  We can also assign value of 'i' by direct way (or) pointer of it..
//     i = 15;
//     cout << *p << endl;
    
//     *p = 23;
//     cout << i << endl;

//     //  We can also increment the value of 'i' by --->  (*p)++;
    
//     int *x = p;
//     cout << *x << endl;
//     cout << i << endl;

    /*

    int ar[10];
    ar[0] = 10;
    ar[1] = 20;

    cout << ar << endl;         //  Both return same address, because the address reference is same..
    cout << &ar[0] << endl;     //     'ar' is acts as a pointer and points to first element of the array..
    
    cout << *ar << endl;        //  prints the first element of array..
    cout << *(ar + 1) << endl;  //      prints the i_th value of array..
                                //  *(ar + i) deference the i_th value of array..
                                //      *(ar + i) ===> ar[i] ===> i[ar]
    int i = 1;
    cout << i[ar] << endl;

    
    int *p = &ar[0];

    cout << p << endl;
    cout << ar << endl;         //  Difference of array and pointer..
                                //  '&' -> Operator..
    cout << &p << endl;         // It has stores the address of ar[0].. in separtly..
    cout << &ar << endl;        //  But, [ar == &ar] both are address of ar[0]..
                                    //  Size of 
    cout << sizeof(ar) << endl;     //  Print the size of array as 40 bytes..
    cout << sizeof(p) << endl;      //  Print the size of Pointer as 8 bytes, which takes 4 bytes as integer..

    p = p +1;       //  Pointer can be update and modified.. as we can do   p = (ar + i);
    // ar = ar +1;     //  We can't update the ar, because it can't modified ones it's assigned..
                    //      Which is an Error..

    // Ex:-
    int a[6] = {1, 2, 3};
    int *p1 = a;
    
    cout << p1[1] << endl;   //  Here it prints the ar[1] th element.. because 'p1' acts as 'a'.. 

    
    */ 

    int a[] = {1, 2, 3};
    char b[] = "abc";

    cout << a << endl;  //  Print the address of the a[0] or array..
    cout << b << endl;  //  Print the entire string upto '\n' character..

    char *ch = &b[0];
    cout << ch << endl; //  Pointer which print all character in case of character..

    char c1 = 'a';
    char *pc = &c1;

    cout << c1 << endl;
    cout << *pc << endl;    //  In above it's print entire characters..
    cout << pc << endl; //  In this case the it prints extra garbage char and stops at '\n'..


    char str[] = "abcd";    //  In this case it create an tempory memory and assigned to character array..
    // char *ptr = "abcde";    //  In this case it create an tempory memory and pointing by pointer..
            //  In this above case the which is pointing to not existing values it may prints (or) may not..

    // Ex:-
        char ss[]= "hello";
        char *p = ss;
        cout << ss[0] << " " << p[0];   //  O/p :-  h   h
    return 0;
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

----------------->

    Arrays and Pointers :-      
        Has Difference Like size of, '&' -> operator, array can't be modified..

------------------->

    Characters and Pointers :-
        In case of characters the pointer doesn't reference the address do prints all the character upto the '\n' character..

*/ 