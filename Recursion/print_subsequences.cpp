#include<bits/stdc++.h>
using namespace std;

void printSubseq(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << "\n";
        return;
    }

    printSubseq(input.substr(1), output);   //  In this we getting both the case which is include that current char or NOT..
    printSubseq(input.substr(1), output + input[0]);
}


int32_t main()
{
    string input;
    cin >> input;

    string *output = new string;
    *output = "";
    printSubseq(input, *output);
}