#include<bits/stdc++.h>
using namespace std;


template <typename T>

class Stack
{
    // By default class is private
    T *data;
    int capacity, nextIndex;

    public:
    // Stack(int size)     //  If constructor is created then default constructor will not working.. here size is fixed..
   
    Stack()  // Using Dynamic Array.. size with default value..
    {
        capacity = 4;
        data = new T[4];
        nextIndex = 0;
    }

    void push(T item)
    {
        if (nextIndex == capacity){     //  In Dynamic array.. we increase the size of array when it size is full..
            
            T *newData = new T[2 * capacity];
            for (int i=0; i<capacity; i++)      //  Create an dynamic array of double size of capacity..
            {
                newData[i] = data[i];
            }
            capacity = 2 * capacity;
            delete []data;      //  Delete the last data and updating the newData..
            data = newData;
        }

        data[nextIndex++] = item;    // if (nextIndex < capacity)
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return (nextIndex == 0);
    }

    T top()
    {
        if (nextIndex == 0) // or isEmpty() or (size == 0)..
        {
            cout << "stack is Empty" << "\n";
            return 0;    // " INT_MAX" will be invaild in case of remaining data type except.. int.
        }
        else 
        {
            return data[nextIndex-1];
        }
    }

    T pop()
    {
        if (nextIndex == 0)  // or isEmpty() or (size == 0)..
        {
            cout << "stack is Empty" << "\n";
            return 0;  //  "INT_MAX" will be invaild in case of remaining data type except.. int.
        }
        else
        {
            nextIndex--;
            return data[nextIndex];
        }
    }

};


int32_t main()
{

    // Stack st(4); 
    Stack <char> st;       // 'typename' should be specified will creating an Object.. 
    
    st.push(97);        //  Similiary we can create for char, double..string.
    st.push(98);
    st.push(99);
    st.push(100);       //  Stack -> LIFO

    cout << st.size() << "\n";

    cout << st.pop() << "\n";
    cout << st.pop() << "\n";
    cout << st.pop() << "\n";
    cout << st.pop() << "\n";


    cout << st.top() << "\n";

    cout << st.isEmpty() << "\n";
    
    return 0;
}