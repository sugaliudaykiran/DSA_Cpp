/*

    Given an array of length N and an integer x, you need to find all the indexes 
        where x is present in the input array. 
        Save all the indexes in an array (in increasing order).
        Do this recursively. Indexing in the array starts from 0.

    Sample Input :
        5
        9 8 10 8 8
        8
    Sample Output :
        1 3 4


    Ref :- https://www.geeksforgeeks.org/recursive-program-to-find-all-indices-of-a-number/

                            
    1_st Approach :-        Check the 1st and do recursive call on (N-1) value..

        * Base case :-              if (size == 0) return 0;
        * Recursive call :-         in this we does, call first..     int ans = fun(ar+1, size-1, x, output);
        * Small calculation :-      
            ->  Increment all element of output array by '1'.. 
            ->  Check If the ar[0] with the x and if equal then shift the output towards to right and 
                    add 0 at index of 0 on output array..the increment the ans which return size of output array..
            ->  Else return res..
    
    2_nd Approach :-        Check the (N-1) val and do recursive call on (1 to N-2) val..
        * Base case :-              if (size == 0) return 0;
        * Recursive call :-         in this we does, call first..     int ans = fun(ar, size-1, x, output);
        * Small cal:-               
             -> Check the last value with the ar[N-1] with the X if it's equal then add to output and increment the ans+1..
             -> Else return the ans..

*/ 


int allIndexes(int input[], int size, int x, int output[]) {
	if (size == 0)
    {
        return 0;
    }
    
    int smallAns = allIndexes(input+1, size-1, x, output);
    
    if (input[0] == x)
    {
        for (int i=smallAns-1; i>=0; i--)
        {
            output[i+1] = output[i] + 1;
        }
        output[0] = 0;
        smallAns++;
    }
	else
    {
    	for (int i=0; i<smallAns; i++)
        {
     	   output[i] = output[i] + 1;
    	}
        
    }    
    return smallAns;    
}




int allIndexes(int input[], int size, int x, int output[]) {
  	if (size == 0)
    {
        return 0;
    }
    int s = allIndexes(input, size-1, x, output);
    
    if (input[size-1] == x)
    {
        output[s] = size-1;
        return s+1;
    }
    
    return s;   
}

/*

P2 :-

Given an integer N, count and return the number of zeros 
    that are present in the given integer using recursion.

int countZeros(int n) {
	if (n < 10)
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int smallAns = countZeros(n/10);
    
    if (n % 10 == 0)
    {
        return 1 + smallAns;
    }
    else {
        return smallAns;
    }
}



p3 :-
    Check whether a given String S is a palindrome using recursion. Return true or false.

#include <bits/stdc++.h>
using namespace std;

bool helper(char input[],int start, int end)
{	
    if (start == end)
    {
        return true;
    }
    
    if (input[start] != input[end])
    {
        return false;
    }
	    
    if (start < end+1)
    {
        return helper(input, start+1, end-1); 
    }
    // If there are more than two characters, check if middle substring is also palindrome or not.
	
    return true;
}


bool checkPalindrome(char input[]) {
	int n = strlen(input);
    
    if (n == 0)
    {
        return true;
    }
    return helper(input, 0, n-1);
}



*/ 

