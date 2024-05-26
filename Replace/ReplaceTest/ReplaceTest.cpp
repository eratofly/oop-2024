#include "pch.h"
#include "CppUnitTest.h"
#include "../Replace/Replace.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ReplaceTest
{
	TEST_CLASS(ReplaceTest)
	{
	public:
		
		TEST_METHOD(ReplaceTestMethod1)
		{
			std::string inputString = "";
			std::string searchString = "1";
			std::string replaceString = "2";
			std::string expectedString = "";

			std::string outputString = ReplaceString(inputString, searchString, replaceString);
			Assert::AreEqual(outputString, expectedString);
		}

		TEST_METHOD(ReplaceTestMethod2)
		{
			std::string inputString = "mamamamama";
			std::string searchString = "mama";
			std::string replaceString = "ma";
			std::string expectedString = "mamama";

			std::string outputString = ReplaceString(inputString, searchString, replaceString);
			Assert::AreEqual(outputString, expectedString);
		}

		TEST_METHOD(ReplaceTestMethod3)
		{
			std::string inputString = "qwerty";
			std::string searchString = "y";
			std::string replaceString = "123456";
			std::string expectedString = "qwert123456";

			std::string outputString = ReplaceString(inputString, searchString, replaceString);
			Assert::AreEqual(outputString, expectedString);
		}

		TEST_METHOD(ReplaceTestMethod4)
		{
			std::string inputString = "qwerty";
			std::string searchString = "";
			std::string replaceString = "12";
			std::string expectedString = "qwerty";

			std::string outputString = ReplaceString(inputString, searchString, replaceString);
			Assert::AreEqual(outputString, expectedString);
		}
	};
}
