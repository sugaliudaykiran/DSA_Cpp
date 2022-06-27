#include<bits/stdc++.h>
using namespace std;

void insertionSort(int *ar, int n)
{
    for (int i=1; i<n; i++)         //  Traverse from the first element..
    {
        int val = ar[i];
        int hole = i;               //  hole which holds the index of element..

        while (hole > 0 && val < ar[hole-1])    //  Checks the val with in the previous element (or) sorted arr..
        {
            ar[hole] = ar[hole-1];      //  swap the element..
            hole -= 1;              
        }
        ar[hole] = val;     //  Insert in it's position..
    }
}

int32_t main()
{
    int ar[6];

    for (int i=0; i<6; i++)
    {
        cin >> ar[i];
    }

    insertionSort(ar, 6);

    for (int x: ar)
    {
        cout << x << " ";
    }cout << endl;
}

/*
    Insertion Sort :-
        * Better than selection, Bubble sort..
        * Does the in-place and shifting the element in it position..

    */ 