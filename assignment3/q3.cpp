// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 /usr/share/syde121/assignment3/displaymatrix.o /usr/share/syde121/assignment3/splitstring.o /usr/share/syde121/assignment3/loadmatrixcompact.o -o q3 q3.cpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector< string > stringvector;
typedef vector< float > floatvector;
typedef vector< floatvector > floatmatrix;

auto DisplayMatrix( floatmatrix, bool = false ) -> void;
auto LoadMatrixCompact() -> floatmatrix;

auto MultiplyMatrices( floatmatrix m1, floatmatrix m2) -> floatmatrix {
     floatmatrix result; 
     floatvector list; 

     int row1 = m1.size();
     int col1 = m1[0].size();

     int row2 = m2.size();
     int col2 = m2[0].size();

     float dotSum = 0.0; 

     if (col1 != row2){
         cout << "Cannot multiply these matrices" << endl; 
         return result; 
     }
     
     for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) { 
            for (int k = 0; k < row2; k++) {
                dotSum += m1[i][k] * m2[k][j];
            }
            list.push_back(dotSum);
            dotSum = 0; 
        }

        result.push_back(list);
        list.clear();
     }
     return result;
}

auto main() -> int
{
    auto leftMatrix { LoadMatrixCompact() };
    auto rightMatrix { LoadMatrixCompact() };
    auto resultMatrix { MultiplyMatrices( leftMatrix, rightMatrix ) };
    cout << "Left Matrix" << endl;
    DisplayMatrix( leftMatrix );
    cout << "Right Matrix" << endl;
    DisplayMatrix( rightMatrix );
    cout << "Result Matrix" << endl;
    DisplayMatrix( resultMatrix );
}

// CITATIONS
// https://www.geeksforgeeks.org/c-program-multiply-two-matrices/