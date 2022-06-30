#include<bits/stdc++.h>
using namespace std;

void intersection(int *arr1, int *arr2, int n, int m) 
{   
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);             // Approach -1 : scanning one array checking each element in the another array..  -> TC -> O(m*n)..
                                    // Approach -2 : sort the smallest array and do binary search each element in another array..   -> TC -> O(mlogm + nlogm).. in doesn't work in duplicate case.. 
    int p1 = 0, p2 = 0;				//	TC -> O(nlogn + mlogm + (m+n))..
    
    while (p1 < n and p2 < m)       //  Approach - 4 : using hash map..
    {
        if (arr1[p1] < arr2[p2])
        {
            p1++;
        }
        
        if (arr1[p1] > arr2[p2])
        {
            p2++;
        }
        
        if (arr1[p1] == arr2[p2])
        {
            cout << arr1[p1] << " ";
            p1++, p2++;
        }
    }
}


int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}