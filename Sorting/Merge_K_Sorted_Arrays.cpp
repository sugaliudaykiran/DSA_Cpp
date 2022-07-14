#include "bits/stdc++.h"
using namespace std;

vector<int> merge(vector<vector<int>> &arr, int n, int i, vector <int> &f_res) {
	vector <int> res;
	
	 int p1 = 0, p2 = 0;                        //  Using Merge sort..
	while ((p1 < n) && (p2 < f_res.size()))     //  TC -> O((k*n)*log(k*n))..   SC-> O(k*n)..
	{
		if (arr[i][p1] < f_res[p2])
		{
			res.push_back(arr[i][p1++]);
		}
		
		if (arr[i][p1] > f_res[p2])
		{
			res.push_back(f_res[p2++]);
		}
		
		if (f_res[p2] == arr[i][p1])
		{
			res.push_back(f_res[p2]), res.push_back(arr[i][p1]);
			p1++, p2++;	
		}
	}
	
	while (p1 < n)
	{
		res.push_back(arr[i][p1++]);
	}
	
	while (p2 < f_res.size())
	{
		res.push_back(f_res[p2++]);
	}
	
	return res;
}



vector<int> mergeKArrays(vector<vector< int>> &arr) {
	int k = arr.size(), n = arr[0].size();
	vector <int> f_res(begin(arr[0]), end(arr[0]));
	
	int i = 1;
	while (k > 2 && i < k)
	{
		f_res = merge(arr, n, i, f_res);
		i++;
	}
	return f_res;
}


int32_t main()
{
    int k, n;
    cin >> k >> n;
    
    vector <vector <int>> arr;
    
    for (int j=0; j<k; j++)
    {
        vector <int> a;
        for (int i=0; i<n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        arr.push_back(a);
    }

    // for (int j=0; j<k; j++)
    // {
    //     for (int i=0; i<n; i++)
    //     {
    //         cout << arr[j][i] << " ";
    //     }cout << "\n";
    // }
    
    
    vector <int> res = mergeKArrays(arr);
    
    for (int x: res)
    {
        cout << x << " ";
    }cout << "\n";
    
    return 0;
}