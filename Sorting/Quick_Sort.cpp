/*
    Quick Sort :-
        * In this we does Partition the given array to find the pivot(we choose right_most element)..
        * In Partition, the pivot has divide the array into two halves..
        * left of pivot are smaller or equal to the pivot..
        * Right of pivot are greater elements.,
        
        Partition can be done, by the following way (or) Using two pointer approach..
            * In two pointer approach, we travser the array and find the position of pivot..
            * Swap the element with pivot[left most element]..
            * Now take two pointers left and right most of array..
            * Compare with Pivot and in case of left element is greater than pivot and right elements are lesser than pivot then swap them..
            * By this two pointer reaches towards the pivot then stop.. by this we done the Partition..

*/ 	
    
	#include <iostream>
	using namespace std;


	int partition(int input[], int start, int end)
	{
    	int pivot = input[end];
        int PartIndex = start;
        
        for (int i=start; i<end; i++)
        {
            if (input[i] <= pivot)
            {
                swap(input[i], input[PartIndex++]);
            }
        }
        swap(input[PartIndex], input[end]);
        return PartIndex;
	}
	
	void quick(int input[], int start, int end)
    {
        if (start >= end)
        {
            return;		//	start < end;..
        }
    	int pivotIndex = partition(input, 0, end);
    	quick(input, start, pivotIndex-1);
        quick(input, pivotIndex+1, end);
    }

	void quickSort(int input[], int size)
	{
		quick(input, 0, size-1);
	}


int32_t main()
{
    int ar[10] = {3,5, 1, 7, 2, 11, 55, 22, 88, 21};

    quickSort(ar, 10);

    for (int x: ar)
    {
        cout << x << " ";
    }cout << endl;
}