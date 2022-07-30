#include<bits/stdc++.h>
using namespace std;

template <typename T, typename V>   //  Used for temporary data types..

class Pair
{
    T x;
    V y;

    public:

    void setX(T x)
    {
        this -> x = x;
    }

    void setY(V y)
    {
        this -> y = y;
    }

    T getX()
    {
        return x;
    }

    V getY()
    {
        return y;
    }
};




int32_t main()
{

    Pair <int, Pair<int, char>> p3;     //  T is an interger type..  V is an Pair type..
    p3.setX(1);
    
    Pair <int , char> p;
    p.setX(10);
    p.setY('a');
    p3.setY(p);

    cout << p3.getX() << " " << p3.getY().getX() << " " << p3.getY().getY() <<"\n";
    



    // Pair <int, char> p1, p2;   // Need to specify which typename is using while delcaring the object..  

    // p1.setX(1);
    // p1.setY('a');


    // p2.setX(2);
    // p2.setY('b');


    // cout << p1.getX() << " " << p1.getY() << "\n";
    // cout << p2.getX() << " " << p2.getY() << "\n";


    return 0;
}