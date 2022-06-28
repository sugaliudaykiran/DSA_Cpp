/*

Check AB
    Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
    a. The string begins with an 'a'
    b. Each 'a' is followed by nothing or an 'a' or "bb"
    c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.

    Sample Input 1 :
    abb
    Sample Output 1 :
    true
    Sample Input 2 :
    abababa
    Sample Output 2 :
    false
*/ 

#include<bits/stdc++.h>
using namespace std;


bool checkAB(char input[]) {
	int size = strlen(input);
    
    if (size == 0)
    {
        return true;
    }
	
    if (input[0] == 'a')
    {
        if ((size -1) > 1 and input[1] == 'b' and input[2] == 'b')
        {
            return checkAB(input+3);    //  in case of "abb"
        }
        else
        {
            return checkAB(input+1);        //  in case "aa"
        }
    }
    return false;
}



int32_t main()
{
    char str[5];
    cin >> str;
    
    cout << checkAB(str) << "\n";
}