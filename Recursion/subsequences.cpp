#include<bits/stdc++.h>
using namespace std;

int subSeq(string str, string *output)
{
    if (str.empty())
    {
        output[0] = "";
        return 1; 
    }

    string sub_str = str.substr(1);
    int smallOutputSize = subSeq(sub_str, output);

    for (int i=0; i<smallOutputSize; i++)
    {
        output[smallOutputSize + i] = str[0] + output[i];
    }

    return 2 * smallOutputSize;
}


int32_t main()
{
    string str;
    cin >> str;
    int Size = pow(2, str.size());
    string *output = new string[Size];

    int outputSize = subSeq(str, output);

    for (int i=0; i<outputSize; i++)
    {
        cout << output[i] << endl;
    }cout  << outputSize << endl;
}

/*
    Ref :-  https://www.geeksforgeeks.org/subarraysubstring-vs-subsequence-and-programs-to-generate-them/
    Ref2 :- https://www.geeksforgeeks.org/power-set/

    A subarray is a contiguous part of array. An array that is inside another array. 
        For example, consider the array [1, 2, 3, 4], There are 10 non-empty sub-arrays. 
        The subarrays are (1), (2), (3), (4), (1,2), (2,3), (3,4), (1,2,3), (2,3,4) and (1,2,3,4). 
        In general, for an array/string of size n, there are n*(n+1)/2 non-empty subarrays/substrings.

    Subsequence 
A subsequence is a sequence that can be derived from another sequence by removing zero or more elements,
     without changing the order of the remaining elements. 
    For the same example, there are 15 sub-sequences. 
        They are (1), (2), (3), (4), (1,2), (1,3),(1,4), (2,3), (2,4), (3,4), (1,2,3), (1,2,4), (1,3,4), (2,3,4), (1,2,3,4). 
        More generally, we can say that for a sequence of size n, we can have (2n-1) non-empty sub-sequences in total. 
    */ 