#include<bits/stdc++.h>
#include<map>
using namespace std;


int pairSum4(int *arr, int n, int num)       //  TC -> O(n)..    SC -> O(n)..
{
	unordered_map <int, int>mp;
    int tc = 0;
    
    for (int i=0;i<n; i++)
    {
        mp[arr[i]]++;	//	For each item frequency..
    }
    
    for (int i=0; i<n; i++)
    {
        tc += mp[num - arr[i]];		//	In this it gets added double time.. so we need to divide by 2..
        
        if (num - arr[i] == arr[i])
        {
            tc--;		//	In this case we can't pair a num by itself.. so reduces it count..
        }
    }
    return tc/2;
}

int pairSum3(int *arr, int n, int num)
{
    sort(arr, arr+n);           //  TC -> O(n*logn)..   SC -> O(1)..
    
    int res = 0, x = 0, y, z;
    
    for (int i=0; i<n-1; i++)
    {
    	x = (num - arr[i]);
        
        y = lower_bound(arr+i+1, arr+n, x) - arr;	//	return the index of the start occurance element which is [>= x]..
        
        z = upper_bound(arr+i+1, arr+n, x) - arr;	//	return the index of the start occurance element which is [> x]..
        
        res += z-y;
    }
    return res;
}



int pairSum2(int *arr, int n, int num)  //  Using Hashing .. TC -> O(n)..   SC -> O(1)..
{
	unordered_map <int, int> mp;
    
    int res = 0;
    
    for (int i=0; i<n; i++)
    {
        if (mp.find(num - arr[i]) != mp.end())
        {
            res += mp[num - arr[i]];
        }
        mp[arr[i]]++;
    }
   return res;
}


int pairSum(int *arr, int n, int num)
{   
    int res = 0;        //  TC -> O(n^2)..  SC -> O(1)..
    
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (arr[i] + arr[j] == num)
            {
                res++;
            }
        }
    }
    return res;
}


int32_t main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, num;
        cin >> n; 

        int *ar = new int[n];
        for (int i=0; i<n; ++i)
        {
            cin >> ar[i];
        }
        cin >> num;

        cout << pairSum(ar, n, num) << "\n"; 

        delete []ar;    
    }

    return 0;
}