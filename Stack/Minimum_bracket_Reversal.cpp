/*

Minimum bracket Reversal :- 
        For a given expression in the form of a string, find the minimum number of 
            brackets that can be reversed in order to make the expression balanced. 
            The expression will only contain curly brackets.
            If the expression can't be balanced, return -1.
Example:
    Expression: {{{{
        If we reverse the second and the fourth opening brackets, 
            the whole expression will get balanced. Since we have to reverse two brackets
            to make the expression balanced, the expected output will be 2.

Expression: {{{
        In this example, even if we reverse the last opening bracket, 
        we would be left with the first opening bracket and hence will not be able 
        to make the expression balanced and the output will be -1.

Input Format :
    The first and the only line of input contains a string expression,
     without any spaces in between.
Output Format :
    The only line of output will print the number of reversals required to balance 
        the whole expression. Prints -1, otherwise.
*/ 

#include <iostream>
#include <string>
using namespace std;


#include<stack>
int countBracketReversals(string input) {
	// Write your code here
    int i = 0, n = input.size(), res = 0;
    if (n % 2 != 0)
    {
        return -1;
    }
    stack<char> st;
    
    for(i=0; i<n; i++)
    {
        if (st.empty() && input[i] == '}')
        {
            st.push(input[i]);
        }
        else if (!st.empty() && input[i] == '}' && st.top() == '{')
        {
            st.pop();
        }
        else 
        {
            st.push(input[i]);
        }
    }
    
    while (!st.empty() && st.size() >= 2)
    {
        char x = st.top();
        st.pop();
        
        char y = st.top();
        st.pop();
        
        if (x == y)
        {
            res++;
        }
        else if (x != y)
        {
            res += 2;
        }
    }
    return res;
}



int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}