#include<bits/stdc++.h>
#include<map>
using namespace std;

map <int, int> mp;

int findUnique4(int *arr, int n) {
    for (int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
    	// cout << it-> first << " " << it -> second << "\n"; 
        if (it -> second == 1)
        {
            return it-> first;
        }
    }
    return 0;
}


int findUnique3(int *arr, int n) {      //  Using Hashing..
	
    vector <int> v(10, 0);
    
    for (int i=0; i<n; i++)
    {
        v[arr[i]]++;
    }
    
    for (int i=0; i<v.size(); i++)
    {
        if (v[i] == 1)
        {
            return i;
        }
    }
    return 0;
}


int findUnique2(int *arr, int n) {      //  Using XOR operation..
    int res = arr[0];
    
    for (int i=1; i<n; i++)
    {
        res ^= arr[i];
    }
    return res;
}

int findUnique(int *ar, int n) {    //  Using Sorting..
    
    if (n == 1)
    {
        return ar[0];
    }
    
	sort(ar, ar+n);
    
    for (int i=0; i<n; )
    {
        if (ar[i] != ar[i+1])
        {
            return ar[i];
        }
        else
        {
            i += 2;
        }
    }
    return 0;
}	


int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}