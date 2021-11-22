// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o q5 q5.cpp

#include<string>
#include<iostream>

using namespace std;

auto IsStringInString (string og, string targ) -> bool{
    int targLength = targ.size(); 
    int ogLength = og.size(); 
    int count = 0; 
    int same = 0; 

    if (ogLength == 0 || targLength == 0)
        return false; 

    else if (og == targ)
        return true; 

    for (int i = 0 ; i < ogLength ; i++){
        if (same == targLength){
            return true; 
        }
        else if (og[i] == targ[count]){
            same++; 
            count++; 
        }
        else {
            count = 0; 
        }
    }
    
    return false; 
}

auto main() -> int
{
    int linesRead {0};
    string currentLine;
    string sourceString;
    string targetString;

    cout << boolalpha;

	while ( getline( cin, currentLine ) )
	{
        linesRead += 1;
        if ( ( linesRead % 2 ) == 1 ) { sourceString = currentLine; }
        else
        {
            targetString = currentLine;
            cout << sourceString << "\t" << targetString << "\t" << IsStringInString( sourceString, targetString ) << endl;
        }
    }
}