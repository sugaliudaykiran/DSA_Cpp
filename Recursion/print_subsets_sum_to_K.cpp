#include<bits/stdc++.h>
using namespace std;

void printSubsetSumToK(int input[], int size, int k, string output = "") {
    
    if (size == 0)  //  reached to end of the array..
    {
        if (k == 0) //  When subset is find then k becomes '0'..
        {
            cout << output << "\n";
            return;
        }
        else
        {
            return;
        }
    }
    printSubsetSumToK(input+1, size-1, k, output);      //  Here with out adding the first element..
    printSubsetSumToK(input+1, size-1, k-input[0], output += to_string(input[0]) + " ");    ////  Here with adding the first element..
}



int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
