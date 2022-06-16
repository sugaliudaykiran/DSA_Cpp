/*
      Address Type-Casting :-
        In case of pointers :-  It generally  need for perform 'explicitly' because, to type-cast one data type to another data type.
        

      Reference and Pass by Reference :-
        To get change will assign the variable we need to use reference variable, by this we can get value by the another variable..
          Ex :-   int i = 10;
                  int &j = i;
                  i++;
                  cout << j << endl;

        * Can be send same refernce while calling the function..
        * uses same memory and reduces the memory creation..
      
      Dynamic Memory Allocation :-
        To use the Dynamic memory allocation we need to use 'new' keyword..
          * "new" which return address of memory allocation in the heap..
          * It Must declared to a pointer.. which is used for 'Run time declaration'..
          * Ex:-  int *p = new int;
                      *p = 10;   
                  cout << *p << endl;   delete p;
          * In case of arrays, int *p = new int[n];  delete []p;
        In this we need to deallocate the memory by manually..
      
      Dynamic allocation of 2D arrays :-
        * In this we can't do   int *p = new int[m][n].. it has to be declared in separte way..
        * First need to declare the pointer array to store each row..then need to declare each row's column..
        * int **ar = new int *[m];  
            for (int i=0; i<m; i++)
            {
              ar[i] = new int[n];
              for (int j=0; j<n; i++)
              {
                cin >> ar[i][j]
              }
            }
        * In dynamic allocation we need to deallocate the memory is required..
            so, First we need to deallocate the each row and next, we deallocate the pointer array..
          for (int i=0; i<m; i++)
          {
            delete []ar[i];   //  this delete each pointer row's..
          }

          delete []ar;    // this delete the pointer array..

      Macros and Global Variables :-
        * In this we known about the keyword " #define ".. 
          #define ----> which is used declare constant globally..and declare the variable before compile time..
            Ex :-   #define PI 3.14    
        * Global variable are variable can be accessed any where and does modification happens..
            Most of cases Global variables are avoided..

        Ex:-  
        #define SQUARE(x) x*x

            int main(){
            int x = 36 / SQUARE(6);   //  It gets the closest multiple of 6 to 36 that is 36.. 
            cout << x << endl;
            cout << 25/SQUARE(3);     //  It gets the closest multiple of 3 to 25 that is 24..
            cout << 11/SQUARE(2);     //  It is '10'
            return 0;
            }

      inline and default argument :-
        * 'inline' is used in the in function get realibilty and only used for shorter lines of code..
        * Inline functions are used to reduce the function call overhead. 
        * Inline function is a function that is expanded in line when it is called.
        * Ex:-    
              inline int max_value(int a, int b)
              {
                return (a>b)? a: b;
              }
        * 'default argument' is an optional arugument and which are declared to some default value in case not given..
          This are declared from left to right,..
        
      Constant variables :-
        * This 'const' is used to reference that the variable (or) 
            reference is an constant which can't be change and does only read operations..
        
        //  constant variable :-
        int const i = 10;   (or)  const int i = 10; we can initizes in any order..
        
        //  constant reference from a non const int :-
        int j = 12;
        const int &k = j;
        j++;      //  can't modify by the const reference..
        cout << k << endl;  
        
        //  constant reference from a constant int :-
        int const j2 = 14;
        int const &k2 = j2;   //  In this we case these does 'only read operations'..

        //  Reference from a const int :-
        int const j3 = 13;
        int & k3 = j3;    //  In this we can't creat any reference for the read only integer,

        //  Const_pointer :-

        void f(int const &a)
        {
          //  does only read operation.. which can't modified the value..
        }

        void g(int const *p)
        {
            //  does only read operation.. which can't be changed..
        }

        int const i = 10;
        int const *p = &i;  //  Here does only Read operation for an const int..

        int j = 20;
        f(&j);    
        g(j);

        int const *p2 = &j;   //  variable can be increment but, not by the pointer.. which does only read operation..
        cout << *p2 << endl;
        j++;
        cout << *p2 << endl;
        
        // Constant Pointer :-
        int i = 10;
        int j = 20;
        
        int const *p = &i;
        p = &j;   //  'p' is a pointer which pointing to const int.. but can't be modified..(*p)++

        int * const p = &i;   //  'p' is a const pointer which pointing to an int.. 
        (*p)++;               //    then we can modified by the pointer but can't assing to another int..

        int const * const p = &i;   //  'p' is a const pointer which pointing to const int..
                          //  Which means it can't does any modification and Write operation..
                          // does only read..
*/ 

#include<bits/stdc++.h>
using namespace std;
#define PI 3.14   //  Macros..
int gob = 10;     //  global declaration...

int increment(int &n)   //  Pass by reference.. functions same memory (or) refernces to the main() variable..
{                       //    gets changes to the value of variable in function..  
  n++;
}

/*  
              Wrong Declaration :-

int &f(int n)   //  warning: reference to local variable 'a' returned [-Wreturn-local-addr]
{
  int a = n;
  return a;
}
int *f2()   //  warning: address of local variable 'i' returned [-Wreturn-local-addr]
{
  int i = 10;
  return &i;
}
*/

void p()
{
  gob++;
  cout << gob << endl;    //  3
}

void f()
{
  gob++;
  cout << gob << endl;    //  2
  p();
}

int32_t main()
{ 
  int r;
  cin >> r;
  cout << PI * r * r << endl;

  gob = 1;
  f();
  cout << gob << endl;    //  3..
  return 0;
}

/* 
    int i = 65;
    char c = i;         //  Here it does type-casting from one data type to another data type.. which is Implicity [does change own on it..]
    cout << c << endl;      //  A

    int *p = &i;
    // char *pc = p;
    char *pc = (char*) p;
    cout << *p << endl;     
    cout << *pc << endl;    //  Raise an Error :- cannot convert 'int*' to 'char*' in initialization
                            //    that why we need to Explicity type-casting..
    
    cout << *(pc + 1) << endl;      //  [0|0|0|65] ---> [65|0|0|0]
    cout << *(pc + 2) << endl;      //  Generally '65' value is small, so it store on last bytes but while call the remainig bytes.. it shows reverse order..        
    cout << *(pc + 3) << endl;      //    Because of 'it follow Little Endian'..  

    cout << p << endl;      //  It return address of 'i'
    cout << pc << endl;     //  It prints the sequence of char upto '\0' NULL character..
*/ 

/*
    int i = 10;
    increment(i);
    cout << i << endl;

    int &q = f(i);
    int *p = f2();


    int j = i;
    int &z = i;

    i++;
    cout << j << endl;    //  In this case the variable i and j store at diff.address..
    cout << z << endl;    //  In this, 'z' is an refernce to 'i' [Can by accessed by both ways..]

    z++;                  //  changes can done by the reference also.. which reference to same address of 'i'
    cout << i << endl;  
    cout << z << endl;

    int k = 100;
    z = k;
    cout << i << endl;  //  It change the value by assign the references variable..
*/ 

/*
  int *p = new int;     // Dynamic Allocation of an integer.. and memory allocated at stack is 8 bytes and in heap is 4 bytes for integer..
  *p = 10;
  cout << *p << endl;   //  Pointer store at 'stack' of 8 bytes..
  cout << p << endl;    //  address of 4 bytes in 'heap'..

  //  Similiary :-
  char *pc = new char;
  *pc = 'A';

  double *pd = new double;
  *pd = 2.3;

  cout << *pc << endl;
  cout << *pd << endl;  

  int *pa = new int[50];    // Dynamic allocation Array..and memory allocated at stack is pointer of 8 bytes and memory at heap is 200 bytes for array..

  int n;
  cin >> n;
  int *ar = new int[n];      //  *(ar+0) = 10;  *(ar + i) = i_th value.. ---> ar[i] = i_th value

  for (int i=0; i<n; i++)
  {
    cin >> ar[i];
  }

  int MAX = -1;
  for (int i=0; i<n; i++)
  {
    if (MAX < ar[i])
    {
      MAX = ar[i];
    }
  }
  cout << MAX << endl;

---------------------->

  while(true)
  {
    int i = 10;     // It create with in scope and delete and re-assign the memory..
  }

  while(true)
  {
    int *p = new int;   // It creates a new memory in every cycle.. which required more space..
  }                     

-------------------->

  int *p = new int;   //  In dynamic allocation memory need to deleted, but in static it does auto..
  delete p;   //  It delete the memory allocated by the pointer 'p'.. not the pointer..

  p = new int;  //  after the deletion we can re-assign new memory to pointer 'p'..
  delete p;

  int *ar = new int[10];
  delete []ar;    //  In case of array we need delete like this..

*/ 