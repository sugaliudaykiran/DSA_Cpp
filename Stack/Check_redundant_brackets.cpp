/*

Check redundant brackets :- 
    For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.
    Example:
        Expression: (a+b)+c
        Since there are no needless brackets, hence, the output must be 'false'.
        
    Expression: ((a+b))
            The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.


*/ 
#include <iostream>
#include <string>
#include<stack>
using namespace std;

bool checkRedundantBrackets(string exp) {
	// Write your code here
    
    stack <char> st;
    
    for (int i=0; i<exp.size(); i++)
    {
        if (exp[i] == ')')
        {
            if (st.top() == '(')
            {
                return true;
            }
            else
            {
                int count = 0;
                while (st.top() != '(')
                {
                    count++;
                    st.pop();
                }
                st.pop();
                if (count == 1)	//	(a) + b is an redundant bracket..
                {
                    return true;
                }
            }
        }
        else
        {
            st.push(exp[i]);
        }
    }
    return false;
    
}



int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}