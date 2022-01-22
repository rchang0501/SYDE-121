/*
clang++ -std=c++20 -Wall -Werror -Wextra -Wpedantic -g3 /usr/share/syde121/lab5/displaymatrix.o /usr/share/syde121/lab5/splitstring.o -o q1 q1.cpp
*/

// Contributors: s62saha 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector< string > stringvector;
typedef vector< float > floatvector;
typedef vector< floatvector > floatmatrix;

struct fillresult 
{ 
    int errorCode; 
    unsigned int line;
};

auto returnResult(fillresult& result, int error, unsigned int line) -> fillresult
{
    result.errorCode = error;
    result.line = line;
    return result;
}

auto DisplayMatrix( floatmatrix, bool = false ) -> void;
auto SplitString( string s ) -> vector< string >;  

auto FillStructuredMatrix( floatmatrix & matrixToFill ) -> fillresult 
{
    const int SUCESSS = 0;
    const int MISSING_STARTMATRIX = -1;
    const int MISSING_ENDMATRIX = -2;
    const int ROW_DATA = 1;
    const int COL_DATA = 2;
    const int INVALID_ENTRY_DATA = 3;
    const int EXTRA_DATA = 4;
    
    fillresult result { .errorCode = SUCESSS, .line = 0 };

    int counter = 0;
    int row = 0;
    int col = 0;
    int printedRow = 0;

    string currentLine;

    bool isDimensions = true;
    bool isEndMatrix = false;

    while ( getline( cin, currentLine ) ) {
        auto currentItem = SplitString( currentLine );
        int currentItemSize = currentItem.size();

        if ( counter == 0 ) {
            try {
                if ( currentItem[0] != "startmatrix" ) {
                    throw MISSING_STARTMATRIX;
                } 
            } catch ( int errorCode ) {
                return ( returnResult(result, errorCode, counter+1) );  
            }

            try {   
                if ( currentItemSize > 1 ) {
                    throw EXTRA_DATA;
                } 
            } catch ( int errorCode ) {
                return ( returnResult(result, errorCode, counter+1) );
            }
        }

        if ( counter == 1 ) {
            if ( currentItem[0] == "dimensions" ) {

                try {   
                    if ( currentItemSize > 3 ) {
                        throw EXTRA_DATA;
                    } 
                } catch ( int errorCode ) {
                    return ( returnResult(result, errorCode, counter+1) );
                }

                try {   
                    row = stoi( currentItem[1] );
                    col = stoi( currentItem[2] );
                } catch (const std::invalid_argument) {
                    return ( returnResult(result, INVALID_ENTRY_DATA, counter+1) );
                }
            }
            else {
                isDimensions = false;
            } 
        }

        if ( counter > 0 && currentItem[0] == "row" ) {
            bool fVal {false};
            floatvector currentRow;

            printedRow++;
            for ( auto value : currentItem ) {

                if ( fVal ) {

                    try {       
                        currentRow.push_back( stof(value) );
                    }
                    catch (const std::invalid_argument) {
                        return ( returnResult(result, INVALID_ENTRY_DATA, counter+1) );
                    }

                    
                } else {
                    fVal = true;

                    if ( col == 0 ) {
                        col = (int) currentItemSize - 1;
                    }
                    
                }
                
            }

            try {  
                if ( col != (int) currentItemSize - 1 ) {
                    throw COL_DATA;
                }
            } catch (int errorCode) {
                return ( returnResult(result, errorCode, counter+1) );
            }

            matrixToFill.push_back(currentRow);
            
        }

        try {   
            if ( (int) matrixToFill.size() > row && row != 0 ) {
                throw ROW_DATA;
            } 
        } catch ( int errorCode ) {
            result.errorCode = errorCode;
            result.line = counter+1;
            return result;
        }

        if ( counter > 0 && currentItem[0] != "dimensions" && currentItem[0] != "row" ) {

            isEndMatrix = true;

            try {   
                if ( (int) matrixToFill.size() != row && row != 0) {
                    throw ROW_DATA;
                } 
            } catch ( int errorCode ) {
                result.errorCode = errorCode;
                result.line = counter+1;
                return result;
            }

            try {   
                if ( currentItemSize > 1 ) {
                    throw EXTRA_DATA;
                } 
            } catch ( int errorCode ) {
                result.errorCode = errorCode;
                result.line = counter+1;
                return result;
            }
        }

        counter++;
    }
    
    try {   
        if ( !isEndMatrix ) {
            throw MISSING_ENDMATRIX;
        } 
    }
    catch ( int errorCode ) {
        result.errorCode = errorCode;
        result.line = counter;
        return result;
    }

    return result;
};

auto main() -> int
{
    floatmatrix newMatrix;
    auto fillResult { FillStructuredMatrix( newMatrix ) };
    if ( fillResult.errorCode )
    {
        cout << "Error [" << fillResult.errorCode << 
            "] on line [" << fillResult.line << "]" << endl; 
    }
    else
    {
        DisplayMatrix( newMatrix );
    }
    return fillResult.errorCode; 
}
