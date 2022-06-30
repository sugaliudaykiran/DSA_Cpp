#include<bits/stdc++.h>
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
    
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    
    int smallTaskSize = returnPermutations(input.substr(1), output);
    
    string temp;
    for (int i=0; i<smallTaskSize; i++)
    {
        temp = output[i];
        for (int j=0; j<=temp.size(); j++)		//	INsert the input[0]  in all possible positions..
        {
            temp.insert(j, 1, input[0]);
            output[j * smallTaskSize + i] = temp;	
            temp.erase(j, 1);
        }
    }
    return smallTaskSize * output[0].size();
    
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

/*
#include <iostream>
#include<bits/stdc++.h>
#include <string>
using namespace std;

void printPermutations(string input, string output=""){
	if (input == "")
    {
        cout << output << "\n";
        return;
    }
    for (int i=0; i<input.size(); i++)
    {
    	printPermutations(input.substr(1), output+input[0]);
    	rotate(input.begin(), input.begin()+1, input.end());	//	Which rotate the input string by leftmost by '1'..    
    }
}


*/ 