#include <string>
#include <optional>
#include <stdexcept>
#include <iostream>
#include "PrimeNumbers.h"

struct Args
{
	std::string inputUpperBound;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		throw std::invalid_argument("Invalid argument count\nUsage: primenumbers.exe <inputUpperBound>\n");
	}
	Args args;
	args.inputUpperBound = argv[1];
	return args;
}

int main(int argc, char* argv[])
{	
	try
	{
		auto args = ParseArgs(argc, argv);
		if (!args)
		{
			return EXIT_FAILURE;
		}
		std::set<int> primeNumbers = GeneratePrimeNumbersSet(std::stoi(args->inputUpperBound));
		for (auto number : primeNumbers)
		{
			std::cout << number << " ";
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}