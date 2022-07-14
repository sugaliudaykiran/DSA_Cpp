#include<bits/stdc++.h>
using namespace std;

class dynamicArray
{
    int *data;
    int nextIndex;
    int capacity;

    public:
    dynamicArray()
    {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    void add(int x)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[capacity * 2];
            for (int i=0; i<capacity; i++)
            {
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex] = x;
        nextIndex++;
    }

    int get(int index)
    {
        if (index < nextIndex)
        {
            return data[index];
        }
        else
        {
            return -1;
        }
    }


    void add(int index, int x)
    {
        if (index < nextIndex)
        {
            data[index] = x;
        }
        else if (index == nextIndex)
        {
            add(x);
        }
        else
        {
            return;
        }
    }

    void print() const
    {
        for (int i=0; i<nextIndex; i++)
        {
            cout << data[i] << " ";
        }cout << "\n";
    }

    //  copy constructor..
    dynamicArray (dynamicArray const &d)
    {
        // this -> data = d.data;           //  Shallow copy..
        
        this -> data = new int[d.capacity];
        for (int i=0; i<d.nextIndex; i++)   //  deep copy..
        {
            this -> data[i] = d.data[i];
        }

        this -> capacity = d.capacity;
        this -> nextIndex = d.nextIndex;   
    }

    void operator= (dynamicArray const &d)   //  "=operator" and "copy constructor".. using deep copy, but by default it, were uses shallow copy..
    {
        this -> data = new int[d.capacity];
        for (int i=0; i<d.nextIndex; i++)
        {
            this -> data[i] = d.data[i];
        }

        this -> capacity = d.capacity;
        this -> nextIndex = d.nextIndex;   
    }
};



int32_t main()
{
    dynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();

    // dynamicArray d2(d1);    //  copy constructor.. using deep copy, but by default it, were uses shallow copy..
    // d1.add(1, 100);
    // d2.print();

    dynamicArray d2;
    d2 = d1;
    d2.print();

    cout << d2.get(0) << "\n";

    return 0;
}   