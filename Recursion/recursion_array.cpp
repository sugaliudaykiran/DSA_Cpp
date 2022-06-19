/*

Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
First index means, the index of first occurrence of x in the input array.
    Do this recursively. Indexing in the array starts from 0.

*/ 
#include<bits/stdc++.h>
using namespace std;

int firstIndex(int input[], int size, int x) {
  
	if (size == 0)
    {
        return -1;
    }
    
    if (input[0] == x)
    {
        return 0;
    }
    
    int res = firstIndex(input+1, size-1, x);
    
    return (res == -1)? res : res +1;
}

int32_t main()
{
    int size, x;
    cin >> size >> x;

    int input[size];
    for (int i=0; i<size; i++)
    {
        cin >> input[i];
    }

    cout << firstIndex(input, size, x) << endl;
}


/*

Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
You should start traversing your array from 0, not from (N - 1).
Do this recursively. Indexing in the array starts from 0.

int lastIndex(int input[], int size, int x) {
	if (size == 0)
    {
        return -1;
    }
    
    int res = lastIndex(input+1, size-1, x);
    if (res == -1)
    {
        if (input[0] == x)
        {
            return 0;
        }
        return res;
    }
    return res+1;
}

*/ 
