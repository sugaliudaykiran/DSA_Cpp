/*
    The Principle of Mathematical Induction :-
        (PMI) is a theorem that gives a method for establishing the truth of statements 
            quantified over all integers greater than or equal to some given integer.

    Ref :- https://www.codingninjas.com/blog/2020/06/19/learn-recursion-in-c/

When to prove PMI we also do the three main parts:
    Base Case: In this concept firstly we do for (X = 0 or X = 1 usually) for making the LHS and RHS true.
    Induction Hypothesis: We have to assume that it is true of F(k). We don’t have to put a question on this part.
    Induction Step: Then we make the statement true for the condition (X = K+1) using step 2

Note: Recursion uses a stack to store the recursive calls. If we don’t make the base case, then the condition
     leads to stack overflow. That’s why we make the base case in recursion.

P1 :-

#include <iostream>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * power(x, n-1);
}

int main()
{
    int x, n;
    
    cin >> x >> n;
    
    cout << power(x, n) << endl;

    return 0;
}


P2 :-
#include <iostream>

using namespace std;

void prints(int n)
{   
    if (n == 0)
    {
        return;
    }
    prints(n-1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;

    prints(n);
    return 0;
}


p3 :-

int count(int n){
    if (n/10 == 0)
    {
        return 1;
    }
    n = count(n/10);        //  It remove the digit from left to right ==> 1234 -> 123
    return 1+n;
}

int32_t main()
{
    int n;
    cin >> n;
    cout << count(n) << endl;
}

#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    
    return fib(n-1) + fib(n-2);
}

void fib2(int n)
{
    int f1 = 0, f2 = 1, i, temp;
    cout << f1 << " ";
    
    for (int i=0; i<n; i++){
        cout << f2 << " ";
        
        temp = f1 + f2;
        f1 = f2;
        f2 = temp;
    }
}

int32_t main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    fib2(n);
    return 0;
}
*/

#include <iostream>
using namespace std;

void print(int n){
    if(n < 0){    //     Solution Description :-
        return;  //         In function print when recursion call is being made  n-- is being passed as input.
    }           //              Here we are using post decrement operator, so argument passed to next function call is n and not n - 1. 
    if(n == 0){         //      Thus there will be infinite recursion calls and runtime error will come
        cout << n << " ";
        return;
    }
    print(n--);
    cout << n << " ";
}

int main() {
    int num = 3;
    print(num);         
}

