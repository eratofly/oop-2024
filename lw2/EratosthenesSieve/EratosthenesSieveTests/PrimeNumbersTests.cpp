#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include <iostream>
#include <set>
#include "../EratosthenesSieve/PrimeNumbers.h"

TEST_CASE("Get prime numbers with upper bound less than 2")
{
	int upperBound = 1;
	std::set<int> result = GeneratePrimeNumbersSet(upperBound);
	std::string expectedErrorMessage = "Upper bound can not be negative number";
	CHECK_THROWS_WITH(result, expectedErrorMessage);
}

TEST_CASE("Get prime numbers with upper bound more than 100000000")
{
	int upperBound = 100000001;
	std::set<int> result = GeneratePrimeNumbersSet(upperBound);
	std::string expectedErrorMessage = "The upper limit shall not exceed 100000000";
	CHECK_THROWS_WITH(result, expectedErrorMessage);
}

TEST_CASE("Dewdwegrgrcoding an empty string")
{
	int upperBound = 2;
	std::set<int> result = GeneratePrimeNumbersSet(upperBound);
	std::set<int> expected = { 2 };
	CHECK(result == expected);
}

TEST_CASE("Dewdwegrgrcoding an empty string")
{
	int upperBound = 100000000;
	std::set<int> result = GeneratePrimeNumbersSet(upperBound);
	int expectedSize = 5761455;
	CHECK(result.size() == expectedSize);
}

TEST_CASE("Dewdwegrgrcoding an empty string")
{
	int upperBound = 9;
	std::set<int> result = GeneratePrimeNumbersSet(upperBound);
	std::set<int> expected = { 2, 3, 5, 7 };
	CHECK(result == expected);
}

TEST_CASE("Dewdwegrgrcoding an empty string")
{
	int upperBound = 10;
	std::set<int> result = GeneratePrimeNumbersSet(upperBound);
	std::set<int> expected = { 2, 3, 5, 7 };
	CHECK(result == expected);
}
