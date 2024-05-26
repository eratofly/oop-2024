#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <windows.h>

using Dictionary = std::map<std::string, std::vector<std::string>>;

void InitDictionary(Dictionary& dictionary, std::istream& dictionaryFile)
{
	std::string word;

	while (std::getline(dictionaryFile, word))
	{
		std::string translatedWord;
		std::vector<std::string> translations;
		translatedWord = word;
		while (std::getline(dictionaryFile, word) && word != "")
		{
			translations.push_back(word);
		}
		dictionary.emplace(translatedWord, translations);
	}
	if (!dictionaryFile.eof())
	{
		throw std::ifstream::failure("Failed to read data");
	}
}

void SaveDictionaryToFile(const Dictionary dictionary, const std::string& filename)
{
	std::ofstream dictionaryFile;
	dictionaryFile.open(filename); 
	if (!dictionaryFile.is_open())
	{
		throw std::ofstream::failure("Failed to write data");
	}
	for (const auto& word : dictionary)
	{
		dictionaryFile << word.first << std::endl;
		for (const auto& translation : word.second)
		{
			dictionaryFile << translation << std::endl;
		}
		dictionaryFile << std::endl;
	}
	if (!dictionaryFile.flush())
	{
		throw std::ofstream::failure("Failed to save data on disk\n");
	}
}

bool SaveNewWord(std::map<std::string, std::string>& dictionary, const std::string& word)
{
	std::string translation;
	std::getline(std::cin, translation);
	if (!translation.empty())
	{
		dictionary.emplace(word, translation);
		std::cout << "The word \"" << word << "\" is saved in the dictionary \"" << translation << "\"." << std::endl;
		return 1;
	}
	else
	{
		std::cout << "The word \"" << word << "\" is ignored" << std::endl;
		return 0;
	}
}

bool FindWordInDictionry(const std::map<std::string, std::string>& dictionary, const std::string& word)
{
	bool isChangesMade = 0;
	auto it = dictionary.find(word);
	if (it != dictionary.end())
	{
		std::cout << it->second << std::endl;
	}
	else
	{
		std::cout << "Unknown word \"" << word << "\". Enter a translation or an empty line to reject." << std::endl;
		bool isChangesMade = SaveNewWord;
	}
	return isChangesMade;
}

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	if (argc != 2)
	{
		std::cout << "Invalid arguments count" << std::endl;
		return EXIT_FAILURE;
		// throw std::invalid_argument("Invalid argument count\nUsage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n");
	}

	std::string inputFileName = argv[1];
	std::ifstream input;
	input.open(inputFileName);
	if (!input.is_open())
	{
		std::cout << "Failed to open '" << inputFileName << "' for reading" << std::endl;
		return EXIT_FAILURE;
	}

	std::map<std::string, std::string> dictionary;

	std::string engWord, rusTranslation;
	while (input >> engWord >> rusTranslation)
	{
		//dictionary[engWord] = rusTranslation;
		dictionary.emplace(engWord, rusTranslation);
	}

	bool isChangesMade = false;
	while (true)
	{
		std::string inputWord;
		std::cout << "> ";
		std::getline(std::cin, inputWord);

		if (inputWord == "...")
		{
			if (isChangesMade)
			{
				char acceptChanges;
				std::cout << "Changes have been made to the dictionary. Enter Y or y to save before exiting." << std::endl;
				std::cin >> acceptChanges;
				if (acceptChanges == 'Y' || acceptChanges == 'y')
				{
					saveDictionary(inputFileName, dictionary);
					std::cout << "The changes are saved." << std::endl;
				}
				else
				{
					std::cout << "The changes are not saved." << std::endl;
				}
			}
			else
			{
				std::cout << "Bye!" << std::endl;
			}
			break;
		}

		isChangesMade = false;
		FindWordInDictionry

		auto it = dictionary.find(inputWord);
		if (it != dictionary.end())
		{
			std::cout << it->second << std::endl;
		}
		else
		{
			std::cout << "Unknown word \"" << inputWord << "\". Enter a translation or an empty line to reject." << std::endl;
			std::string translation;
			std::getline(std::cin, translation);
			if (!translation.empty())
			{
				//dictionary[inputWord] = translation;
				dictionary.emplace(engWord, rusTranslation);
				isChangesMade = true;
				std::cout << "The word \"" << inputWord << "\" is saved in the dictionary \"" << translation << "\"." << std::endl;
			}
			else
			{
				std::cout << "The word \"" << inputWord << "\" is ignored" << std::endl;
			}
		}
	}

	return 0;
}