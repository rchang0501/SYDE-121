/*
clang++ -std=c++20 -Wall -Werror -Wextra -Wpedantic -g3 /usr/share/syde121/lab5/splitstring.o /usr/share/syde121/lab5/stringfromstringvector.o -o q2 q2.cpp
*/

// Contributors: s62saha 

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath> // for isnan()

using namespace std;

typedef vector< string > stringvector;

auto SplitString( string s ) -> stringvector;  
auto StringFromStringVector( stringvector ) -> string; // function declaration

int lineNum=1;
map<string, float> dataMap;

const string EXTRA_DATA { "Extra data" };
const string INVALID_TYPE { "Invalid data type" };
const string MISSING_DATA { "Missing data" };
const string UNDECLARED_VARIABLE { "Variable not declared" };
const string NO_VALUE { "Attempting to calculate using a variable with no value" };

// helper function to determine the operation 
auto removeMarker(stringvector tempLine) -> stringvector {
    stringvector newLine = tempLine;
    newLine.erase(newLine.begin());
    return newLine;
}

// helper function to determine the error 
auto outputError(string error) -> void {
    cerr << "Error: " << error << " on line [" << lineNum << "]" << endl;
}

// helper function for "declare" operation
auto declareCommand(stringvector currentLine, int length) -> void {

    if (length > 2) {
        outputError(EXTRA_DATA);
    }

    // run if both operands are present
    else if (length == 2) {
        try {
            float temp = stof(currentLine[1]);
            dataMap[currentLine[0]] = temp;
        } catch (const std::invalid_argument) {
            outputError(INVALID_TYPE);
        }
    }

    // run if only given one operand
    else if (length == 1) {
        dataMap[currentLine[0]] = nan("");
    }

    else {
        outputError(MISSING_DATA);
    }  
}

// helper function when "display" is called
auto displayCommand(stringvector currentLine, int length) -> void {
    
    if (length > 1) {
        outputError(EXTRA_DATA);
    }

    // if operand A is given
    else if (length == 1) {
        try {
            cout << "[" << currentLine[0] << "]=[" << dataMap.at(currentLine[0]) << "]" << endl;
        } catch(const std::out_of_range) {
            outputError(UNDECLARED_VARIABLE);
        }
    }

    // if neither operand A nor B are given
    else if (length == 0) {
        for (auto& variable : dataMap) {
            cout << "[" << variable.first << "]=[" << variable.second << "]" << endl;
        }
    }
}

// helper function for when "swap" is calle
auto swapCommand(stringvector currentLine, int length) -> void {
    
    if (length > 2) {
        outputError(EXTRA_DATA);
    }

    // if bother operands are given
    else if (length == 2) {
        try {
            float temp = dataMap.at(currentLine[0]);
            dataMap.at(currentLine[0]) = dataMap.at(currentLine[1]);
            dataMap.at(currentLine[1]) = temp;
        } catch(const std::out_of_range) {
            outputError(UNDECLARED_VARIABLE);
        }
    }

    else {
        outputError(MISSING_DATA);
    }   
}

// helper function for when "set" is called
auto setCommand(stringvector currentLine, int length) -> void {
    
    if (length > 2) {
        outputError(EXTRA_DATA);
    }

    // Run when both Operand A and B given
    else if (length == 2) {
        try {
            float temp = stof(currentLine[1]);
            dataMap.at(currentLine[0]) = temp;
        }
        catch (const std::invalid_argument) {
            outputError(INVALID_TYPE);
        }
        catch (const std::out_of_range) {
            outputError(UNDECLARED_VARIABLE);
        }
    }

    else {
        outputError(MISSING_DATA);
    }  
}

// helper function for when "add" "subtract" or "multiply" is called
auto addSubtractMultiplyCommand(stringvector currentLine, int length, string operation) -> void {
    if (length > 3) {
        outputError(EXTRA_DATA);
    }

    else if (length < 2) {
        outputError(MISSING_DATA);
    }

    // checks if either of the operands given are NAN (have no value)
    try {
        if (isnan(dataMap.at(currentLine[0])) or isnan(dataMap.at(currentLine[1]))) {
            string error = NO_VALUE;
            throw error;
        }
    }
    catch (std::out_of_range) {}
    catch (string error) {
        outputError(error);
        return;
    }

    // if operand A, B and result are given
    if (length == 3) {
        // tries to complete operation assuming operand B is float
        try{
            if (operation == "+") {
                dataMap[currentLine[2]] = dataMap.at(currentLine[0]) + stof(currentLine[1]);
            }
            else if (operation == "-") {
                dataMap[currentLine[2]] = dataMap.at(currentLine[0]) - stof(currentLine[1]);
            }
            else if (operation == "*") {
                dataMap[currentLine[2]] = dataMap.at(currentLine[0]) * stof(currentLine[1]);
            }
        }

        // runs operand B is a variable name
        catch (const std::invalid_argument) {
            // tries to complete operation assuming Operand B is a valid variable
            try{
                if (operation == "+") {
                    dataMap[currentLine[2]] = dataMap.at(currentLine[0]) + dataMap.at(currentLine[1]);
                }
                else if (operation == "-") {
                    dataMap[currentLine[2]] = dataMap.at(currentLine[0]) - dataMap.at(currentLine[1]);
                }
                else if (operation == "*") {
                    dataMap[currentLine[2]] = dataMap.at(currentLine[0]) * dataMap.at(currentLine[1]);
                }
            }
            catch (const std::out_of_range) {
                outputError("varaible not declared");
            }
        }
    }

    // if operand A and B are given
    else if (length == 2) {
        // tries to complete operation assuming Operand B is float
        try{
            if (operation == "+") {
                cout << dataMap.at(currentLine[0]) + stof(currentLine[1]) << endl;
            }
            else if (operation == "-") {
                cout << dataMap.at(currentLine[0]) - stof(currentLine[1]) << endl;
            }
            else if (operation == "*") {
                cout << dataMap.at(currentLine[0]) * stof(currentLine[1]) << endl;
            }
        }
        // runs operand B is a variable name
        catch (const std::invalid_argument) {
            // tries to complete operation assuming Operand B is a valid variable
            try{
                if (operation == "+") {
                    cout << dataMap.at(currentLine[0]) + dataMap.at(currentLine[1]) << endl;
                }
                else if (operation == "-") {
                    cout << dataMap.at(currentLine[0]) - dataMap.at(currentLine[1]) << endl;
                }
                else if (operation == "*") {
                    cout << dataMap.at(currentLine[0]) * dataMap.at(currentLine[1]) << endl;
                }
            }
            catch (const std::out_of_range) {
                outputError("varaible not declared");
            }
        }
    }   
}

// helper function for when divide is called
auto divideCommand(stringvector currentLine, int length) -> void
{
    if (length > 3) {
        outputError(EXTRA_DATA);
    }
    else if (length < 2) {
        outputError(MISSING_DATA);
    }

    // checks if either of the operands given are NAN (have no value)
    try {
        if (isnan(dataMap.at(currentLine[0])) or isnan(dataMap.at(currentLine[1]))) {
            string error = NO_VALUE;
            throw error;
        }
    }
    catch (std::out_of_range) {}
    catch (string error) {
        outputError(error);
        return;
    }

    // if operand A, B and result are given
    if (length == 3) {
        // tries to complete operation assuming Operand B is float
        try{
            // Checks if divison by 0 occuring
            if (stof(currentLine[1]) == 0) {
                 dataMap[currentLine[2]]=nan("");
            }
            else {
                dataMap[currentLine[2]] = dataMap.at(currentLine[0]) / stof(currentLine[1]);
            }
        }
        // tries to complete operation assuming Operand B is a valid variable
        catch (const std::invalid_argument) {
            try{
                if (dataMap.at(currentLine[1]) == 0) {
                    dataMap[currentLine[2]]=nan("");
                }
                else {
                    dataMap[currentLine[2]] = dataMap.at(currentLine[0]) / dataMap.at(currentLine[1]);
                }
            }
            catch (const std::out_of_range) {
                outputError("varaible not declared");
            }
        }
    }

    // if operand A and B are given
    else if (length == 2) {
        // tries to complete operation assuming operand B is float
        try{
            // Checks if divison by 0 occuring
            if (stof(currentLine[1]) == 0) {
                 cout << nan("") << endl;
            }
            else {
                cout << dataMap.at(currentLine[0]) / stof(currentLine[1]) << endl;
            }
        }
        // tries to complete operation assuming operand B is a valid argument
        catch (const std::invalid_argument) {
            try{
                // checks if divison by 0 occuring
                if (dataMap.at(currentLine[1]) == 0) {
                    cout << nan("") << endl;
                }
                else {
                    cout << dataMap.at(currentLine[0]) / dataMap.at(currentLine[1]) << endl;
                }
            }
            catch (const std::out_of_range) {
                outputError("varaible not declared");
            }
        }
    }
}

auto main() -> int
{
    string currentLine;
    while ( getline( cin, currentLine ) )
    {
        auto splitLine { SplitString( currentLine ) };

        int lineLength { (int)splitLine.size()-1 }; 

        // check the operation and call the respective helper function
        if (splitLine[0] == "declare") {
            declareCommand( removeMarker(splitLine), lineLength );
        }
        else if (splitLine[0] == "display") {
            displayCommand( removeMarker(splitLine), lineLength );
        }
        else if (splitLine[0] == "swap") {
            swapCommand( removeMarker(splitLine), lineLength );
        }
        else if (splitLine[0] == "set") {
            setCommand( removeMarker(splitLine), lineLength );
        }
        else if (splitLine[0] == "add" or splitLine[0] == "+") {
            addSubtractMultiplyCommand( removeMarker(splitLine), lineLength, "+" );
        }
        else if (splitLine[0] == "subtract" or splitLine[0] == "-") {
            addSubtractMultiplyCommand( removeMarker(splitLine), lineLength, "-" );
        }
        else if (splitLine[0] == "multiply" or splitLine[0] == "*") {
            addSubtractMultiplyCommand( removeMarker(splitLine), lineLength, "*" );
        }
        else if (splitLine[0] == "divide" or splitLine[0] == "/") {
            divideCommand( removeMarker(splitLine), lineLength );
        }
        else {
            outputError("No valid operation");
        }
        
        lineNum += 1;
    }
}
