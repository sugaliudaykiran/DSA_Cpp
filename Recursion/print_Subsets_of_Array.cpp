
#include <iostream>
using namespace std;

void prints(int input[], int size, int output[], int m)
{
    int temp[1000];
    if (size == 0)
    {
        for (int i=0; i<m; i++)
        {
            cout << output[i] << " ";
        }cout << "\n";
    	return;
    }
    
    prints(input+1, size-1, output,  m);        //  In this we doesn't include the input[0]..
    
    for (int i=0; i<m; i++)
    {
        temp[i] = output[i];
    }
    temp[m++] = input[0];       //  In this we include the input[0]..
    
    prints(input+1, size-1, temp, m);   
}



void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[1000];
    
    return prints(input, size, output, 0);
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
