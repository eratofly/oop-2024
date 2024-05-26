#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

std::vector<double> ParseDoublesToVector(std::istream& input)
{
	std::vector<double> v(std::istream_iterator<double>(input), (std::istream_iterator<double>()));

	return v;
};

void AddThreeMinNumbers(std::vector<double>& v)
{
	const size_t REQUIRED_NUMBER_OF_ELEMNTS = 3;
	
	if (v.empty())
	{
		return;
	}

	std::vector<double> sortedVector(std::min(REQUIRED_NUMBER_OF_ELEMNTS, v.size()));
	
	std::partial_sort_copy(v.begin(), v.end(), sortedVector.begin(), sortedVector.end());
	double sum = std::accumulate(sortedVector.begin(), sortedVector.end(), 0.0);

	std::ranges::transform(
		v,
		v.begin(),
		[sum](double element) {
			return element + sum;
		});
}

int main()
{
	std::vector<double> inputData = ParseDoublesToVector(std::cin);

	AddThreeMinNumbers(inputData);
	std::ranges::sort(inputData);

	std::ranges::copy(inputData, std::ostream_iterator<double>(std::cout, " "));

	return EXIT_SUCCESS;
}