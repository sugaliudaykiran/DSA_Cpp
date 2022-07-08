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

    void print()
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

    void add(Fraction f2)
    {
        int lcm = this -> denominator * f2.denominator;

        int x = lcm / this -> denominator;
        int y = lcm / f2.denominator;

        int num = (x * this -> numerator) + (y * f2.numerator);

        this -> numerator = num;
        this -> denominator = lcm;

        simplify();
    }
};



int32_t main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    f1.add(f2);

    f1.print();
    f2.print();

    return 0;
}