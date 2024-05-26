#include <fstream>
#include <iostream>
#include <optional>
#include <string>

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
	std::string search;
	std::string replace;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 5)
	{
		throw std::invalid_argument("Invalid argument count\nUsage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n");
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	args.search = argv[3];
	args.replace = argv[4];
	return args;
}

std::string ReplaceString(const std::string& subject,
	const std::string& searchString, const std::string& replacementString)
{
	if (searchString.empty())
	{
		return subject;
	}
	size_t pos = 0;
	std::string result;
	while (pos < subject.length())
	{
		size_t foundPos = subject.find(searchString, pos);
		result.append(subject, pos, foundPos - pos);
		if (foundPos == std::string::npos)
		{
			pos = subject.length();
		}
		else
		{
			result.append(replacementString);
			pos = foundPos + searchString.length();
		}
	}
	return result;
}

void CopyStreamWithReplacement(std::istream& input, std::ostream& output,
	const std::string& searchString, const std::string& replacementString)
{
	std::string line;

	while (std::getline(input, line))
	{
		if (!(output << ReplaceString(line, searchString, replacementString) << "\n"))
		{
			throw std::invalid_argument("Failed to write data to file\n");
		}
	}

	if (input.bad())
	{
		throw std::invalid_argument("Failed to read data from file\n");
	}
}

void CopyFileWithReplacement(std::string& inputFileName, std::string& outputFileName,
	const std::string& searchString, const std::string& replacementString)
{
	std::ifstream inputFile;
	inputFile.open(inputFileName);
	if (!inputFile.is_open())
	{
		throw std::invalid_argument("Failed to open input file for reading\n");
	}

	std::ofstream outputFile;
	outputFile.open(outputFileName);
	if (!outputFile.is_open())
	{
		throw std::invalid_argument("Failed to open output file for writing\n");
	}

	CopyStreamWithReplacement(inputFile, outputFile, searchString, replacementString);

	if (!outputFile.flush())
	{
		throw std::invalid_argument("Failed to write data\n");
	}
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
		CopyFileWithReplacement(args->inputFileName, args->outputFileName, args->search, args->replace);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}