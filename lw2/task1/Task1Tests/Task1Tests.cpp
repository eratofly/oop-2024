#include "pch.h"
#include "../task1/task1.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Task1Tests
{
	TEST_CLASS(Task1Tests)
	{
	public :

		TEST_METHOD(ParsingDoublesToVector)
		{
			std::istringstream input("2.5 5.5 1.0 4 13");
			std::vector<double> result = ParseDoublesToVector(input);
			std::vector<double> expected = { 2.5, 5.5, 1, 4, 13 };
			for (unsigned int i = 0; i < expected.size(); ++i)
				Assert::AreEqual(expected[i], result[i]);
		}

		TEST_METHOD(ParsingEmptyVector)
		{
		std::istringstream input("");
		std::vector<double> result = ParseDoublesToVector(input);
		std::vector<double> expected = {};
		for (unsigned int i = 0; i < expected.size(); ++i)
			Assert::AreEqual(expected[i], result[i]);
		}

		TEST_METHOD(AddElementsInEmptyVector)
		{
			std::vector<double> result = {};
			std::vector<double> expected = {};
			AddThreeMinNumbers(result);
			for (unsigned int i = 0; i < expected.size(); ++i)
				Assert::AreEqual(expected[i], result[i]);
		}

		TEST_METHOD(AddOneElementInVector)
		{
		std::vector<double> result = { 5 };
		std::vector<double> expected = { 10 };
		AddThreeMinNumbers(result);
		for (unsigned int i = 0; i < expected.size(); ++i)
			Assert::AreEqual(expected[i], result[i]);
		}

		TEST_METHOD(AddTwoElementsInVector)
		{
		std::vector<double> result = {1.13, 2.14};
		std::vector<double> expected = {4.4, 5.41};
		AddThreeMinNumbers(result);
		for (unsigned int i = 0; i < expected.size(); ++i)
			Assert::AreEqual(expected[i], result[i]);
		}

		TEST_METHOD(AddThreeElementsInVector)
		{
		std::vector<double> result = {16, 1, 5.5};
		std::vector<double> expected = {38.5, 23.5, 28};
		AddThreeMinNumbers(result);
		for (unsigned int i = 0; i < expected.size(); ++i)
			Assert::AreEqual(expected[i], result[i]);
		}

		TEST_METHOD(AddMoreThreeElementsInVector)
		{
		std::vector<double> result = { 6.7, 12.9, 48.443, 10.1, 17.05, 3.2 };
		std::vector<double> expected = { 26.7, 32.9, 68.443, 30.1, 37.05, 23.2 };
		AddThreeMinNumbers(result);
		for (unsigned int i = 0; i < expected.size(); ++i)
			Assert::AreEqual(expected[i], result[i]);
		}
	};
}
