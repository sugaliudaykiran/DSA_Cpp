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

    Fraction add(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator;

        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = (x * this -> numerator) + (y * f2.numerator);
        
        Fraction fnew(num,lcm);
        fnew.simplify();

        return fnew;
    }

    Fraction operator+(Fraction const &f2) const        //  It is constant function, because it change the called object..
    {
        int lcm = denominator * f2.denominator;

        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = (x * this -> numerator) + (y * f2.numerator);
        
        Fraction fnew(num,lcm);
        fnew.simplify();

        return fnew;
    }

    void multiply(Fraction const &f2) 
    {
        this -> numerator = this -> numerator * f2.numerator;
        this -> denominator = this -> denominator * f2.denominator;

        simplify(); 
    }

    Fraction operator* (Fraction const &f2) const
    {
        int x = numerator * f2.numerator;
        int y = denominator * f2.denominator;

        Fraction fnew(x, y);
        fnew.simplify(); 

        return fnew;
    }

    bool operator== (Fraction const &f2) const
    {
        return (numerator == f2.numerator && denominator == f2.denominator); 
    }

};

int32_t main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    Fraction f4 = f1.add(f2);
    f4.print();

    Fraction f5 = f1 + f2;
    f5.print();

    Fraction f6 = f1 * f2;
    f6.print();

    if (f2 == f1)
    {
        cout << "Equal" << "\n";
    }
    else 
    {
        cout << "Not Equal" << "\n";
    }


    //  Constant Object :-
    Fraction const f3(10, 4);
    f3.print();


    return 0;
}