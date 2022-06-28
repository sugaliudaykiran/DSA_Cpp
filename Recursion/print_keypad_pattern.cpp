#include <iostream>
#include <string>
using namespace std;

void helper(int num, string temp)
{	
    string input;
    if (num < 2)
    {
        cout << temp << "\n";
        return;
    }
    
    int n = num%10;
    
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
    
    for (int i=0; i<input.size(); i++)
    {   
        helper(num/10, input[i] + temp); 
    }
    
}

void printKeypad(int num){

    helper(num, "");
        
}


int32_t main()
{
    int num;
    cin >> num;

    printKeypad(num);    
}


/*

Given an integer n, using phone keypad 
find out and print all the possible strings that can be made using digits of input n.

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