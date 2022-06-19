/*
    Recursion :- A function calling itself, that is a function calling the smaller version of itself..
        Ex:-    n! = n * n-1 * n-2 * n-3 * .. * 1;
                n! = n * (n-1)!;

    Similiar..    fact(n) = n * fact(n-1);
                fact(n-1) = n-1 * fact(n-2);


    Function Calls are stores in function call stack, like in above case..

        main() -> fact(n) --> fact(n-1) --> fact(n-2) --> fact (n-1) --> fact(0)
                                                                            
*/ 

#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    int smalloutput = factorial(n-1);
    return n * smalloutput;
}


int32_t main()
{
    int n;
    cin >> n;

    cout << factorial(n) << endl;
    
    return 0;
}