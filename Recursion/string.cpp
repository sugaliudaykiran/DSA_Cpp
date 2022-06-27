#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    string str = "abc"; //  String is a type which defind as Class..It is overcomes the char arrays.. 
    cout << str << "\n";

    string s1;
    s1 = "def";
    cout << s1 << "\n";

    string *s = new string;
    *s = "sai";
    cout << s << "\n";      //  return address of 's'
    cout << *s << "\n";

    // cin >> str;
    // cout << str << "\n";        //  uday''kiran  in this we assumes the space is '\0'..

    getline(cin, *s);
    cout << *s << "\n";

    string s2 = "gfg";
    s2 = "cpp";         //  "=" operator is used for assign and changing purposes..
    cout << s2 << "\n"; 

    //  We can change the single char using index of the string.. and get the single char to print..
    s2[0] = 'a';
    cout << s2 << "\n";
    cout << s2[0] << "\n";

    //  concate the string using another string..
    string s3 = "Hello";
    s1 = "good";
    s2 = "Morning";
    s3 = s1 + s2;
    cout << s3 << "\n";     //  O/p :-  goodMorning NOT the Hello neither HellogoodMorning..
    
    s2 += s1;
    cout << s2 << "\n";

    string s4 = "abcdefdef";        //  To know the size of string..
    cout << s4.size() << "\n";  
    cout << s4.length() << "\n";

    cout << s4.substr(3) << "\n";       
    cout << s4.substr(3, 3) << "\n";    //  substr(startIndex, Size_of_String)..
    //  Assing the substr to another string..
    s1 = s4.substr(3);
    cout << s1 << "\n";

    //  find() is used for get the substring is present in the given string or if present then return index of First occurance..
    cout << s4.find("def") << "\n";     //  Return Index if present.. else points to "\0"..

    return 0;
}