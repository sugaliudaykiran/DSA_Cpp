/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a
    numeric string S. Write a program to return the list of all possible codes that
    can be generated from the given string.

    Sample Input:
        1123
        Sample Output:
        aabc
        kbc
        alc
        aaw
        kw
*/

#include<bits/stdc++.h>
#include <string.h>
#include<map>
using namespace std;

map <string, char> Keymap;

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    char x = 'a';
    for (int i=1; i<=26; i++, x++)      //  creating a map for string to char..
    {
    	Keymap[to_string(i)] = x;
    }

    int SingleSize = getCodes(input.substr(1), output);    
    int DoubleSize = 0;
    
    if (input.size() > 1 && stoi(input.substr(0, 2)) <= 26)		// input.substr(0, 2) - '0'   // stoi is string to int..
    {
    	DoubleSize = getCodes(input.substr(2), output+SingleSize);      
	}
    
    int res = SingleSize + DoubleSize;
    
    for (int i=0; i<SingleSize; i++)
    {
        output[i] = Keymap[string(1, input[0])] + output[i];        //  adding the single char to string..
    }

    for (int i=SingleSize; i<res; i++)
    {
        output[i] = Keymap[input.substr(0, 2)] + output[i];     //  adding the string to string..
    }
    
    return res;
}


int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}

/*

    #include <string.h>
#include <map>
using namespace std;

map <string, char> Keymap;

void printAllPossibleCodes(string input, string output="") {
    // Given the input as a string, print all its possible combinations. You do not need to return anything.
    
    
    if (input.empty())
    {
        cout << output << "\n";
        return;
    }
    
    char x = 'a';
    for (int i=1; i<=26; i++, x++)
    {
        Keymap[to_string(i)] = x;
    }
    
    printAllPossibleCodes(input.substr(1), output + Keymap[string(1, input[0])]);
    if (input.size() > 1 && stoi(input.substr(0, 2)) <= 26)
    {
    	printAllPossibleCodes(input.substr(2), output + Keymap[input.substr(0, 2)]);	
    }    
}

*/ 