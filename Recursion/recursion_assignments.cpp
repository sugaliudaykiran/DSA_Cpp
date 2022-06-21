/*

    Given a string,
     compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

     Approach :  
        * If there is only one character in a string or the string is empty break the recursive call
        * Else keep the first character of the string with yourself and pass the rest of the string to recursion. 
        * If the first character is not ‘p’ then just put that character in front of the answer which came from recursion.
        * Else if the first character is ‘p’ and the first character of the part passed to recursion is ‘i’ then replace “pi” with “3.14”

    Ref :-  https://www.geeksforgeeks.org/recursive-program-to-replace-all-occurrences-of-pi-with-3-14-in-a-given-string/

#include<bits/stdc++.h>
#include<string>
using namespace std;

void helper(char input[], int start)
{
    int n = strlen(input);
    
    if (input[start] == '\0' || input[start+1] == '\0')
    {
        return;
    }
    
    helper(input, start+1);
    
    if (input[start] == 'p' && input[start+1] == 'i')
    {
        for (int i=strlen(input); i>= start+2; i--)
        {
            input[i+2] = input[i];
        }
        input[start] = '3', input[start+1] = '.', input[start+2] = '1', input[start+3] = '4';
    }
}

void replacePi(char input[]) {
	helper(input, 0);
}

------------------------------------------------------>

Given a string,
 compute recursively a new string where all 'x' chars have been removed.

#include<bits/stdc++.h>
using namespace std;

void removeX(char input[]) {
    
    if (input[0] == '\0')
    {
        return;
    }
    
    removeX(input+1);
    
    if (input[0] == 'x')
    {
        strcpy(input, input+1);
        // memmove(input, input + 1, strlen(input + 1) + 1);
        removeX(input);
    }
}

How is it different from memcpy()? 

memcpy() simply copies data one by one from one location to another.
    On the other hand memmove() copies the data first to an intermediate buffer, 
     then from the buffer to destination.
memcpy() leads to problems when strings overlap. 


---------------------------------->

Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)


#include<bits/stdc++.h>
using namespace std;


int stringToNumber(char input[]) {
    // Write your code here
	int n = strlen(input);
    
    if (n == 1)
    {
        return (input[0] - '0');
    }
    
    int res = stringToNumber(input+1);
    
    return (input[0] - '0') * pow(10, n-1) + res;
}
------------------------------------------>

Given a string S, compute recursively a new string where identical chars 
    that are adjacent in the original string are separated from each other by a "*".

    Sample Input 1 :
    hello
    Sample Output 1:
    hel*lo
    Sample Input 2 :
    aaaa
    Sample Output 2 :
    a*a*a*a


// Change in the given string itself. So no need to return or print the changed string.

#include<bits/stdc++.h>
using namespace std;

void pairStar(char input[]) {
    int n = strlen(input);
    
    if (n == 0)
    {
        return;
    }
 	
    pairStar(input+1);
    
    if (input[0] == input[1])
    {
        for (int i=strlen(input); i>=1; i--)
        {
            input[i+1] = input[i];
        }
        input[1] = '*';
    }
}

----------------------------->



*/ 