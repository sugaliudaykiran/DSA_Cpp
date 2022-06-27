#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int *ar, int n)
{
    for (int i=1; i<n-1; i++)       //  Passes of the array..
    {
        bool flag = 0;
        for (int j=0; j<n-i-1; j++)     
        {
            if (ar[j] > ar[j+1])        //  Check the element with the adjancent element..
            {
                swap(ar[j], ar[j+1]);
                flag = 1;
            }
        }
        if (flag == 0)      //  Check the array is sorted or not..
        {
            break;
        }
    }
}

int32_t main()
{
    int ar[6];
    for (int i=0; i<6; i++)
    {
        cin >> ar[i];
    }

    bubbleSort(ar, 6);

    for (int x: ar)
    {
        cout << x << " ";
    }cout << endl;

    return 0;
}

/*
    * In Bubble sort, each pass the largest element is bubbled to the highest index of the array..
    * At Some point the array is divided into sorted and un-sorted halves..
    * In unsorted half, the largest element is bubbled to higher index..
    *   TC -> O(n^2)..
    *   In best case :-     O(n)
    */ 