#include<bits/stdc++.h>
using namespace std;

void print_P(int *p)
    {
        cout << *p << endl;
    }

void incrementPointer(int *p)
    {
        p = p + 1;  //  In this case we increment the address by 4 bytes..
    }

void increment_P(int *p)
    {
        (*p)++;     //  By doing de-references and increment the value..
    }

int sum(int *a, int size)  //  here the arr is an pointer which refer to the array..
{
    cout << sizeof(a) << endl;
    int res = 0;
    for (int i=0; i<size; i++)
    {
        res += a[i];
    }
    return res;
}

void increment1(int **p)
{
    p = p + 1;          //  It does change on copy pointer..
}

void increment2(int **p)
{
    *p += 1;            //  It does change on 'p' by de-references..
}

void increment3(int **p)
{
    **p += 1;           //  It does changes on the value of 'i'..
}

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
/*

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
*/ 
/*
        
    int i = 10;
    int *p = &i;
    print_P(p);

    cout << p << endl;
    incrementPointer(p);
    cout << p << endl;      //  It does no change, because the function updates on the copy address..

    cout << *p << endl;
    increment_P(p);
    cout << *p << endl;         //  In this case, we are derefencing the pointer and increment the value..

    int a[10];
    cout << sizeof(a) << endl;
    cout << sum(a, 10) << endl;     //  Here the 'a' is send as array, but refer as pointer in the function..
    cout << sum(a+2, 8) << endl;    //  We can refer a particular range (or) part of array..

*/
    //  Double Pointer :-
    int i = 10;
    int *p = &i;
    
    int **p2 = &p;

    cout << p2 << endl;
    cout << &p << endl;     //  Both prints the address of 'p'..

    cout << p << endl;
    cout << *p2 << endl;    //  This prints the address of 'i'..
    cout << &i << endl;

    cout << i << endl;
    cout << *p << endl;     //  This prints the value of 'i'..
    cout << **p2 << endl;   

    increment1(p2);         //  In this it does no changes..
    increment2(p2);         //  In this it does increment on address of 'i'.. by derefernces..
    increment3(p2);         //  In this it does increment on value of 'i'..  by double dereferences..

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
-------------------->
    Pointers and Functions  :-
        In this Functions, the Pointers are given as address reference,while in functions we does the changes on derefencing it..
    
    Arrays and Functions :-
        In functions the array is act as a pointer and not an array..
        In functions we can send the particular range (or) part of an array..

    What will be the output ?
            void square(int *p){
            int a = 10;
            p = &a;             //  here the change happend with in the function, because of [p = &a]..
            *p = (*p) * (*p);
            cout << *p << endl;     //  Here the output is 100..
            }

            int main(){
            int a = 10;
            square(&a);
            cout << a << endl;      //  here the output is 10.. It does change the value of 'a'
            }
    
    O/p :-  10

------------------------------>
        Double Pointers :-
            int i = 10, *p = &i;
            int **p2 = &p;      Here this pointer stores the address of another pointer..
        Ex :-
            int a = 10;
            int *p = &a;
            int **q = &p;
            int b = 20;
            *q = &b;
            (*p)++;
            cout << a << " " << b << endl;
        O/p :- 10   21
    p points to a. q points to p directly and a through p (double pointer). 
    *q — value stored in p is changed to address of b instead of that of a. 
    (*p)++ — value that p points to, which now is of b, is incremented by 1 (b becomes 21). 
    Value of a remains unchanged.

--------------------------------->

            Void Pointer :-
A	void	pointer	is	a	generic	pointer,	it	has	no	associated	type	with	it.
    A	void	pointer	can	hold	address	of	any	type	and	can	be	typcasted	to	any	type. Void	
    pointer	is	declared	normally	the	way	we	do	for	pointers.	
        void	*ptr;

This	statement	will	create	a	void	pointer.
        Example:
        void *v;
        int *i;
        int ivar;
        char chvar;
        float fvar;
        v	= &ivar; //	valid
        v	= &chvar; //valid
        v	= &fvar; //	valid
        i	= &ivar; //valid
        i	= &chvar; //invalid
        i	= &fvar; //invalid
        Thus	we	can	use	void	pointer	to	store	address	of	any	variable.

*/ 