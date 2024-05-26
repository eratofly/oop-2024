#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <exception>

const int MIN_UPPER_BOUND = 2;
const int MAX_UPPER_BOUND = 100000000;

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{	
	if (upperBound > MAX_UPPER_BOUND)
	{
		throw std::invalid_argument("The upper limit shall not exceed 100000000");
	}

	if (upperBound < MIN_UPPER_BOUND)
	{
		throw std::invalid_argument("Upper bound should be more than 2");
	}

	std::vector<bool> isPrime(upperBound, true);
	std::set<int> primeNumbers;

	for (int i = MIN_UPPER_BOUND; i <= upperBound; ++i)
	{
		if (isPrime[i])
		{
			primeNumbers.insert(primeNumbers.end(), i);

			if (upperBound / i < i)
			{
				continue;
			}

			for (int j = i * i; j <= upperBound; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	return primeNumbers;
}