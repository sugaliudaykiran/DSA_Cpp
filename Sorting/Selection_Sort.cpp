#include<bits/stdc++.h>
using namespace std;

void selectionSort(int *ar, int n)      //  TC -> O(n^2).. AS -> O(1)..
{
    for (int i=0; i<n-1; i++)   //  we need to do n-2 passes..
    {
        int imin = i;   //  ith position: elements from i till (n-1) are candidates..
        for (int j=i+1; j<n; j++)
        {
            if (ar[j] < ar[imin])
            {   
                imin = j;       //  update the index of minimum element..
            }
        }
        swap(ar[i], ar[imin]);
    }
}

int32_t main(){
    int ar[6];
    for (int i=0; i<6; i++)
    {
        cin >> ar[i];
    }

    selectionSort(ar, 6);
 
    for (int x: ar)
    {
        cout << x << " " ;
    }cout << endl;

    return 0;
}

/*
    Selection Sort :-
        * Pick the min element in each pass and replace element with it's apperate position..
        * By this it take O(n^2).. which is slow sorting algorithm..
        
    selection(ar, n)
    {
        i <- 0 to n-2  //   [til the last one element..]
        imin <- i;

        j <- i+1 to n-1 
            if (ar[j] < ar[imin])
            {
                imin = j;   //  updating the min element index..
            }
        swap(ar[i], ar[imin]);
    }

*/ 