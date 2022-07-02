
#include<bits/stdc++.h>
#include<set> 			//	in this we can use hashing..
using namespace std;

int tripletSum(int *arr, int n, int num)
{
	if (n > 3)
    {
        int res = 0;

        for (int i=0; i<n-2; i++)
        {
        	unordered_set <int> s;
            for (int j=i+1; j<n; j++)
            {
                if (s.find(num - (arr[i] + arr[j])) != s.end())
                {
                    res++; 
                }
                s.insert(arr[j]);
            }
        }
        return res;
    }
}

int tripletSum(int *arr, int n, long long int num)
{
    int res =0;
	for (int i=0; i<n-2; i++)
    {
        for (int j=i+1; j<n-1; j++)
        {
            for (int k = j+1; k<n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == num)
                {
                    res++;
                }
            }
        }
    }
}

int tripletSum(int *arr, int n, int num)
{
	sort(arr, arr+n);  
    int res = 0;
    
    for (int i=0; i<n-2; i++)
    {
        int l = i+1, r = n-1;
        
        while (l < r)
        {
            if (arr[i] + arr[l] + arr[r] == num)
            {
                res++;
            }
            else if (arr[i] + arr[l] + arr[r] < num)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return res;
}

