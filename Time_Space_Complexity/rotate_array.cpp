/*

You have been given a random integer array/list(ARR) of size N. 
Write a function that rotates the given array/list by D elements(towards the left).

    Sample Input 1:
    1
    7
    1 2 3 4 5 6 7
    2
    Sample Output 1:
    3 4 5 6 7 1 2

*/ 

#include<bits/stdc++.h>
using namespace std;


void rotate2(int *input, int d, int n)      //  TC -> O(n*d)..  SC -> O(1)..
{
	for (long long int i=1; i<=d; i++)
    {
        int temp = input[0];
        
        for (long long int j=0; j<n-1; j++)
        {
            input[j] = input[j+1];
        }
        
        input[n-1] = temp;
    }
} 


int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    
    return gcd(b, a%b);
}

void rotate(int *input, int d, int n)
{
    if (d == 0 and n == 0)      //  TC -> O(n)..    SC -> O(1)..
    {
    	input[0] = 0;
        return;
    }
    
	d = d%n;	//	In case of d >= n
    
    int x = gcd(d, n);
    
    for (int i=0; i<x; i++)
    {
        int temp = input[i];
        int j = i;
        
        while (1)
        {
            int k = j + d;
            
            if (k >= n)
            {
                k -= n;
            }
            
            if (k == i)
            {
                break;
            }
            
            input[j] = input[k];    //  swap with k th items..
            j = k;
        }
        input[j] = temp;
    }
}

int32_t main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}
	return 0;
}