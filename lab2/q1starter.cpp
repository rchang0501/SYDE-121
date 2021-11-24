#include <string>
#include <iostream>

auto main() -> int
{
	std::string lineInput;
	int numRead = 0;
	int totalLength = 0;
	float avgLength = 0;

	while ( getline( std::cin, lineInput ) )
	{
		int lineLength = lineInput.length();

		numRead = numRead + 1; // increment 

		auto stringLineLength = std::to_string( lineLength );

		totalLength = totalLength + lineLength; // increment 
		
		auto outputLine = stringLineLength + "\t" + lineInput;
  		std::cout << outputLine << std::endl;
	}

	// convert to float 
	float totalLengthFloat = static_cast<float>(totalLength);
	float linesReadFloat = static_cast<float>(numRead);

	// find avg length of lines 
	avgLength = totalLengthFloat/linesReadFloat;

	// convert everyhting to string 
	std::string linesString = std::to_string(numRead);
	std::string totalLengthString = std::to_string(totalLength);
	std::string averageLengthString = std::to_string(avgLength);

	// output footer 
	std::cout << "lines: " << linesString << "\t" << "total length: " << totalLengthString << "\t" << "average length: " << averageLengthString << std::endl;
	return 0;
}
