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

    void multiply(Fraction const &f2) 
    {
        this -> numerator = this -> numerator * f2.numerator;
        this -> denominator = this -> denominator * f2.denominator;

        simplify(); 
    }

    //  Operator overload :-   X++ Post_Increment..
    //  try         int j = i++;
    Fraction operator++ (int)
    {
        Fraction fNew(numerator, denominator);  //  copying to j..

        numerator = numerator + denominator;
        simplify();
        fNew.simplify();

        return fNew;
    }

    Fraction& operator+= (Fraction const &f2) // TRY ..f1 += f2.. and also (f1 += f2) += f2;  
    {
        int lcm = denominator + f2.denominator;

        int x = lcm/denominator;
        int y = lcm/f2.denominator;

        int num = (x * numerator) + (y *f2.numerator);

        numerator = num;
        denominator = lcm;

        simplify();
        return *(this);
    }
};

int32_t main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    // Fraction f2 = f1++;
    // f1.print(); 
    // f2.print();

    // f1 += f2;
    // f1.print();
    // f2.print();

    (f1+= f2) += f2;
    f1.print();

    //  Constant Object :-
    Fraction const f3(10, 4);
    // f3.print();


    return 0;
}