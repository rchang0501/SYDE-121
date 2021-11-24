#include <string>
#include <iostream>

auto main() -> int
{
	std::string lineInput;

	while ( getline( std::cin, lineInput ) )
	{
		// cast to int 
		int curr = stoi(lineInput);

		// core logic 
		if (curr % 3 == 0 && curr % 5 == 0)
		{
			std::cout << curr << " Fizz Buzz" << std::endl;
		}
		else if (curr % 3 == 0)
		{
			std::cout << curr << " Fizz" << std::endl;
		}
		else if (curr % 5 == 0)
		{
			std::cout << curr << " Buzz" << std::endl;
		}
		else
		{
			std::cout << curr << std::endl;
		}
	}
	return 0;
}
