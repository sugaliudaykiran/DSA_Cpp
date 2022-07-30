#include<bits/stdc++.h>
#include <stack>
using namespace std;

bool isBalanced(string exp) 
{
    int index = 0, size = exp.size();
    
    stack <char> st;
    
    while (index < size)
    {
        if(exp[index] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
                index++;
            }
            else
            {
                return false;
            }
        }
        else
        {
            st.push(exp[index]);
            index++;
        }
    }
    return (st.empty());
}

int32_t main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}

/*

Code : Balanced Parenthesis
    For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.
        Example:
        Expression: (()())
        Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.

    Sample Input 2 :
        ()()(()
    Sample Output 2 :
        false
*/ 