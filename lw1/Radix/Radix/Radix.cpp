#include <cmath>
#include <iostream>
#include <optional>

struct Args
{
	std::string sourceNotation;
	std::string destinationNotation;
	std::string value;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 4)
	{
		throw std::invalid_argument("Invalid argument count\nUsage: radix.exe <sourceNotation> <destinationNotation> <value>\n");
	}
	Args args;
	args.sourceNotation = argv[1];
	args.destinationNotation = argv[2];
	args.value = argv[3];
	return args;
}

size_t CharToInt(const char& ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return (ch - '0');
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		return (ch - 'A' + 10); // вынести в константу
	}
	// тут исключение надо, инвалид аргумент
}

size_t IntToChar(const int& number)
{
	if (number >= 0 && number <= 9)
	{
		return (number + '0');
	}
	else if (number >= 10 && number <= 35)
	{
		return (number + 'A' - 10); // вынести в константу
	}
	// тут исключение надо, инвалид аргумент
}

// как лучше: создать переменную, вызвать в ней функцию, а потом использоввать или вызывать

int StringToInt(const std::string& str, int radix /*, bool& wasError*/)
{
	size_t number = 0;
	size_t i = str.length() - 1;

	for (char ch : str)
	{
		if (CharToInt(ch) < radix && CharToInt(ch) >= 2)
		{
			number += pow(radix, i) * CharToInt(ch);
			--i;
		}
		else
		{
			// кидаем исключение
		}
	}

	return number;
}



std::string IntToString(int n, int radix/*, bool& wasError*/)
{
	std::string str = "";
	size_t digit = n % 10;
	if (IntToChar(digit) < radix && IntToChar(digit) >= 2)
	{
		str += IntToChar(digit);
	}
	else
	{
		// кидаем исключение
	}

	std::reverse(str.begin(), str.end());

	return str;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return EXIT_FAILURE;
	}

	size_t number = StringToInt("100", 2);
	char ch = IntToChar(4);

	std::string numb = IntToString(StringToInt("100", 2), 10);

	std::cout << number;
}
