// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 /usr/share/syde121/assignment3/displaymatrix.o /usr/share/syde121/assignment3/splitstring.o -o q2 q2.cpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector< string > stringvector;
typedef vector< float > floatvector;
typedef vector< floatvector > floatmatrix;

auto DisplayMatrix( floatmatrix, bool = false ) -> void;
auto SplitString( string s ) -> vector< string >;  

auto LoadMatrixCompact() -> floatmatrix 
{
    string currentLine; 
    getline(cin, currentLine); 
    vector <float> list; 
    floatmatrix result; 
    int counter = 0; 
    int error = false; 

    auto currItems = SplitString(currentLine); 
    int rows = stoi(currItems[0]); 
    int cols = stoi(currItems[1]);

    if (rows == 0 || cols == 0){
        //cout << "ERROR - Improrper Formatting" << endl; 
        return result; 
    }

    else {
        while (getline(cin, currentLine)){
            currItems = SplitString(currentLine); 
            counter++; 

            int currSize = currItems.size(); 

            if (cols != currSize){
                //list.clear(); 
                error = true; 
                cout << "Incorrect number of columns for row " + to_string(counter) + "[" + to_string(currSize) + "/" + to_string(cols) + "]" << endl;
            }
            else{
                for (auto item : currItems){
                    float floatItem = stof(item); 
                    list.push_back(floatItem); 
                }
            }
        result.push_back(list);  
        list.clear(); 
        }
    }
    if (error){
        floatmatrix empty; 
        return empty; 
    }
    return result;    
}

auto main() -> int
{
    DisplayMatrix( LoadMatrixCompact() );
}