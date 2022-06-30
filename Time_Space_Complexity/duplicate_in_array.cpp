#include<bits/stdc++.h>
#include<map>
using namespace std;

int findDuplicate(int *arr, int n)
{
	unordered_map <int, int> mp;
    
    for (int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        if (it -> second == 2)
        {
            return it -> first;
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
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}