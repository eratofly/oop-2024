#include <climits>
#include <exception>
#include <iostream>
#include <set>
#include <vector>

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
		// вернуть пустое множество
		throw std::invalid_argument("Upper bound should be more than 2");
	}

	std::vector<bool> isPrime(upperBound + 1, true);
	//выяснить сложность вставки поиска и удаления элементов контейнер сет
	std::set<int> primeNumbers;

	for (int i = MIN_UPPER_BOUND; i <= upperBound; ++i)
	{
		if (isPrime[i])
		{
			primeNumbers.insert(primeNumbers.end(), i);

			//меньше или меньше и равно. написать комметнарий, что это более безопасная проверка i в квадрате не превышает аппер баунд 
			if (upperBound / i < i)
			{
				continue;
			}

			//перепрыгивать чётные числа когда i больше 2
			for (int j = i * i; j <= upperBound; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	return primeNumbers;
}