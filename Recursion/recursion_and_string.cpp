#include<bits/stdc++.h>
using namespace std;

void removeX(char str[])
{
    if (str[0] == '\0')
    {
        return;
    }

    if (str[0] != 'x')
    {
        removeX(str+1);
    }
    else
    {
        int i=1;
        for (; str[i] != '\0'; i++)
        {
            str[i-1] = str[i];
        }
        str[i-1] = str[i];      //  Which to convert the repating last character to NULL..
        
        removeX(str);       //  We need to do until the entire 'x' is removed from the string..
    }
}

int length(char str[])
{
    if (str[0] == '\0')
    {
        return 0;
    }

    int smallTask = length(str+1);
    return 1 + smallTask;
}

int32_t main()
{

    char str[100];
    cin >> str;

    int len = length(str);
    cout << len << endl;

    removeX(str);
    len = length(str);

    cout << len << endl;
    cout << str << endl;
    return 0;
}

/*

Given an input string S and two characters c1 and c2, you need to replace every occurrence
     of character c1 with character c2 in the given string.
    Do this recursively.


void replaceCharacter(char input[], char c1, char c2) {
    if (input[0] == '\0')
    {
        return;         //  Base Case..
    }
    
    if (input[0] == c1)     //  comparing first character with given one,,
    {
        input[0] = c2;      //  changing to required character..
    }
    
    replaceCharacter(input+1, c1, c2);  //  calling for remaining characters..
}

--------------------------------->

Given a string S, remove consecutive duplicates from it recursively.

void removeConsecutiveDuplicates(char *input) {
	if (input[0] == '\0')
    {
        return;
    }
    removeConsecutiveDuplicates(input+1);
	    
    if (input[0] == input[1])
    {	
        int i=1;
        for (; input[i] != '\0'; i++)
        {
            input[i] = input[i+1];      //  Does the left shit..
        }
        input[i-1] = input[i];      //  remove the last repating character..
    }
}
*/ 