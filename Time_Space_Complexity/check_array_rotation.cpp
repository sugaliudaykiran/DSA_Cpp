/*

    You have been given an integer array/list(ARR) of size N. 
         It has been sorted(in increasing order) and then rotated by some number 'K' in the right hand direction.
    Your task is to write a function that returns the value of 'K', that means, 
        the index from which the array/list has been rotated.
        
        Sample Input:
            2
            5
            3 6 8 9 10
            4
            10 20 30 1

        Sample Output:
            0
            3
*/ 

#include<bits/stdc++.h>
using namespace std;

int arrayRotateCheck(int *input, int size)
{
	for (int i=0; i<size-1; i++)
    {
        if (input[i] > input[i+1])
        {
            return i+1;
        }
    }
    return 0;
}


int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int *ar = new int[n];

        for (int i=0; i<n; i++)
        {
            cin >> ar[i];
        }

        cout << arrayRotateCheck(ar, n) << "\n";

        delete [] ar;
    }
    return 0;
}