#include<bits/stdc++.h>
using namespace std;

int keypad(int num, string output[]){
    
    if (num < 2)
    {
        output[0] = "";
        return 1;
    }
    
    int n = num%10;
    num = num/10;
    
    int smallOutputSize = keypad(num, output);
    
    string input;
    switch(n)
    {
        case 2: input = "abc";
            break;
        case 3: input = "def";
            break;
        case 4: input = "ghi";
            break;
        case 5: input = "jkl";
            break;
        case 6: input = "mno";
            break;
        case 7: input = "pqrs";
            break;
        case 8: input = "tuv";
            break;
        case 9: input = "wxyz";
            break;
    }
    
    int resSize = smallOutputSize * (input.size());
    string temp[resSize];

    int k = 0;
    for (int i=0; i<smallOutputSize; i++)
    {
        for (int j=0; j<input.size(); j++)
        {
            temp[k++] = output[i] + input[j];
        }
    }
    
    for (int i=0; i<k; i++)
    {
        output[i] = temp[i]; 
    }
    
    return k;
}


int32_t main()
{
    int input;
    cin >> input;

    string *output = new string[1000];

    int res = keypad(input, output);

    for (int i=0; i<res; i++)
    {
        cout << output[i] << endl;
    }
}

/*

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.


Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/ 