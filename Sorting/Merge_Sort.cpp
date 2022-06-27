#include<bits/stdc++.h>
using namespace std;


void merge(int *input, int size, int *part1, int size1, int *part2, int size2)
{
    int i=0, j=0, k=0;
    while (i < size1 && j < size2)
    {
        if (part1[i] < part2[j])
        {
            input[k++] = part1[i++];
        }
        else
        {
            input[k++] = part2[j++];
        }
    }
    
    while (i < size1)
    {
        input[k++] = part1[i++];
    }
        
    while (j < size2)
    {
        input[k++] = part2[j++];
    }
}


void mergeSort(int input[], int size){
	if (size < 2)
    {
        return;
    }
    
    int *part1 = new int[size/2];
    int size1 = size/2;
    
    int *part2 = new int[size-size/2];
	int size2 = size - size/2;
    
    for (int i=0; i<size1; i++)
    {
        part1[i] = input[i];
    }
    
    int k = 0;		// size-j-1
    for (int j=size1; j<size; j++)
    {
        part2[k++] = input[j];
    }
    
    mergeSort(part1, size1);
    mergeSort(part2, size2);
    
    merge(input, size, part1, size1, part2, size2);
}


int32_t main()
{
    int ar[10] = {1, 5,32, 15,22, 66, 23, 11, 9, 10};
    mergeSort(ar, 10);

    for (int x: ar)
    {
        cout << x << " ";
    }cout << endl;
}