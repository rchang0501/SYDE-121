// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o q1 q1.cpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

auto StringFromStringVector( vector< string > ) -> string;

auto SplitString( string str ) -> vector< string >{
    vector <string> list; 
    string temp; 
    int strLen = str.length(); 

    for (int i = 0 ; i < strLen ; i++){
        if (!isspace(str[i]) && str[i] != '\t'){
            temp.push_back(str[i]); 

            if (i == strLen - 1){
                list.push_back(temp); 
            }
        }
        else {
            if (!temp.empty()){
                list.push_back(temp); 
            }
            temp.clear(); 
        }
    }

    return list; 
}

auto main() -> int
{
    string currentLine;
	while ( getline( cin, currentLine ) )
	{
        cout << currentLine << "\t" << 
            StringFromStringVector( SplitString(  currentLine ) ) << endl;
    }
}

auto StringFromStringVector( vector< string > vs) -> string
{
    string returnString;
    returnString += "[";
    auto prefix = '\0';
    for ( auto currentString : vs )
    {
        if ( prefix != '\0' ) { returnString += prefix; }
        returnString += "\"";
        returnString += currentString;
        returnString += "\"";
        prefix = ',';
    }
    returnString += "]";
    return returnString;
}
