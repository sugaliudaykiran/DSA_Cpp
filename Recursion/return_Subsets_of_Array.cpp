#include <iostream>
using namespace std;


int subset(int input[], int n, int output[][20]) {    
    if (n == 0)
    {
        output[0][0] = 0;
        return 1;
    }
    
    int smallTaskSize = subset(input+1, n-1, output);
    
    for (int i=0; i<smallTaskSize; i++)
    {
        output[smallTaskSize + i][0] = output[i][0] +1;
        
        for (int j=1; j<=output[smallTaskSize + i][0]; j++)
        {
            if (j == 1)
            {
                output[smallTaskSize + i][j] = input[0];
            }
            else 
            {
                output[smallTaskSize + i][j] = output[i][j-1];
            }
        }    
    }
    return 2 * smallTaskSize;
}


int main() {
  int input[20],length, output[3500][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
