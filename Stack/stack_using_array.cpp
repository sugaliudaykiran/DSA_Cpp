#include<bits/stdc++.h>
using namespace std;

class Stack
{
    // By default class is private
    int *data;
    int capacity, nextIndex;

    public:
    // Stack(int size)     //  If constructor is created then default constructor will not working.. here size is fixed..
   
    Stack()  // Using Dynamic Array.. size with default value..
    {
        capacity = 4;
        data = new int[4];
        nextIndex = 0;
    }

    void push(int item)
    {
        if (nextIndex == capacity){     //  In Dynamic array.. we increase the size of array when it size is full..
            
            int *newData = new int[2 * capacity];
            for (int i=0; i<capacity; i++)      //  Create an dynamic array of double size of capacity..
            {
                newData[i] = data[i];
            }
            capacity = 2 * capacity;
            delete []data;      //  Delete the last data and updating the newData..
            data = newData;

            // cout << "stack is full.." << "\n";
            // return;
        }

        data[nextIndex++] = item;    // if (nextIndex < capacity)
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        // if (nextIndex == 0)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }

        return (nextIndex == 0);
    }

    int top()
    {
        if (nextIndex == 0) // or isEmpty() or (size == 0)..
        {
            cout << "stack is Empty" << "\n";
            return INT_MAX;
        }
        else 
        {
            return data[nextIndex-1];
        }
    }

    int pop()
    {
        if (nextIndex == 0)  // or isEmpty() or (size == 0)..
        {
            cout << "stack is Empty" << "\n";
            return INT_MIN;
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
    Stack st;       // Dynamic array..
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << st.size() << "\n";

    cout << st.pop() << "\n";
    cout << st.pop() << "\n";
    cout << st.pop() << "\n";
    cout << st.pop() << "\n";


    cout << st.top() << "\n";

    cout << st.isEmpty() << "\n";
    
    return 0;
}