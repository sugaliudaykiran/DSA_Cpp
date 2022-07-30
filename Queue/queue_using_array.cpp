#include<bits/stdc++.h>
using namespace std;

template <typename T>
class queue_using_ar
{
    T *data;
    int size, capacity, nextInd, firstInd;

    public:
    queue_using_ar(int s)
    {
        capacity = s;
        data = new T[s];
        size = 0;
        nextInd = 0, firstInd = -1;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    void enqueue(T x)   //  Inserting..
    {
        if (size == capacity)
        {
            // cout << "queue is Full..!" << "\n";
            // return;

            T *newData = new T[2 * capacity];   //  Dynamic sized array..
            int j =0;
            for (int i=firstInd; i<capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for (int i=0; i<firstInd; i++)
            {
                newData[j] = data[i];
                j++;
            }

            delete [] data;
            data = newData;

            firstInd = 0;
            nextInd = capacity;
            capacity = 2 * capacity;
        }

        data[nextInd] = x;
        nextInd = (nextInd +1) % capacity; 

        if (firstInd == -1)
        {
            firstInd = 0;
        }
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "queue is Empty..!" << "\n";
            return 0;
        }
        return data[firstInd];
    }


    T dequeue()     //  deleting.. 
    {
        if (isEmpty())
        {
            cout << "queue is Empty..!" << "\n";
            return 0;
        }
        T temp = data[firstInd];
        firstInd = (firstInd + 1) % capacity;
        size--;

        if (size == 0)
        {
            firstInd = -1, nextInd = 0;
        }

        return temp;
    }
};


int32_t main()
{

    queue_using_ar <int> q(5); // declare type of object..

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.dequeue() << "\n";
    cout << q.dequeue() << "\n";
    cout << q.front() << "\n";

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    


    cout << q.dequeue() << "\n";
    cout << q.dequeue() << "\n";
    cout << q.dequeue() << "\n";

    cout << q.isEmpty() << "\n";
    cout << q.getSize() << "\n";

    return 0;
}