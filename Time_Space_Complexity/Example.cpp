#include<bits/stdc++.h>
using namespace std;

int prime(int n)
{   
    for (int i=2; i<sqrt(n); i++)       //  It proporitional to Sqrt(n)..
    {
        if (n % i == 0)
        {
            return i;
        }
    }
    return 0;
}

int main()
{   
    int n;
    cin >> n;
    
    cout << prime(n);
    return 0;
}


/*

int prime2(int n)
{   
    for (int i=2; i<n; i++)         //  In this case the time take directly proportional to N..
    {
        if (n % i == 0)
        {
            return i;
        }
    }
    return 0;
}


*/ 