#include<bits/stdc++.h>
using namespace std;

int bs(int *ar, int start, int end, int x)
{
    int mid = (start+end)/2;
     mid = start + (end-start)/2;
    
    if (start > end)
    {
        return -1;
    }
    
    if (ar[mid] == x)
    {
        return mid;
    }
    
    if (ar[mid] < x)
    {
        return bs(ar, mid+1, end, x);
    }
        
    if (ar[mid] > x)
    {
        return bs(ar, start, mid-1, x);
    }
}



int binarySearch(int input[], int size, int element) {      //  TC -> O(logn).. SC -> O(logn)
    // Write your code here
	return bs(input, 0, size-1, element);
}


int32_t main()
{
    int ar[] = {1, 5, 7, 8, 9};     //  Should be sorted array..
    int size = 5;
    int x;
    cin >> x;

    int res = binarySearch(ar, size, x);

    cout << res << "\n";        //  return index else -1..
}