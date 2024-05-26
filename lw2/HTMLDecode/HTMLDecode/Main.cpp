#include "HTMLDecode.h"
#include <iostream>
#include <string>

int main()
{
	std::string str;

	while (getline(std::cin, str))
	{
		std::string decodedStr = HtmlDecode(str);

		std::cout << decodedStr << std::endl;
	}

	return 0;
}
