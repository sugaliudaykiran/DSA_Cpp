#include<bits/stdc++.h>
using namespace std;

class Fraction
{
    private :
    int numerator;
    int denominator;

    public:
    Fraction(int numerator, int denominator)
    {
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    void print() const  //  Constant Function.. which doesn't make any change to the object..
    {
        cout << this -> numerator << "/ " << this -> denominator << "\n";
    }

    void simplify()
    {
        int gcd = 1;

        int x = min(this -> numerator, this -> denominator);

        for (int i=1; i<=x; i++)
        {
            if (this -> numerator % i == 0 && this -> denominator % i == 0)
            {
                gcd = i;
            }
        }

        this -> numerator = this -> numerator / gcd;
        this -> denominator = this -> denominator / gcd;
    }

    Fraction& operator++ ()     //  By using 'Fraction reference' which doesn't creat new memory in main().. and uses the calling object..
    {
        numerator = numerator + denominator;
        simplify();

        return *(this);
    }

};

int32_t main()
{
    Fraction f1(10, 2);

    // ++f1;
    // f1.print();

    // try.. f2 = ++f1;
    // Fraction f2 = ++f1;
    // f1.print();

    //  try.. ++(++f1) and f2 = ++(++f1);
    
    // ++(++f1);
    // f1.print();
    Fraction f2 = ++(++f1);
    f2.print();    //  Here it creates the new object in memory then does the "++" work.. 
    f1.print();    // Here it does increment by only ones..

    //  Constant Object :-
    Fraction const f3(10, 4);
    // f3.print();


    return 0;
}