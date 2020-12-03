#include <iostream>
#include <algorithm>

void help()
{
	std::cout << "Usage: ./permutation <permutation> <n-times>" << std::endl;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		help();
		return 1;
	}

	std::string permutation = argv[1];
	int n;
	try
	{
		n = std::stoi(argv[2]);
	}
	catch (std::invalid_argument const &e)
	{
		help();
		return 1;
	}

	std::string tempPermutation = permutation;
	std::cout << "1: " << tempPermutation << std::endl;

	for (int i = 1; i < n; i++)
	{
		std::string result = "";
		for (int j = 0; j < permutation.length(); j++)
		{
			result += tempPermutation[static_cast<int>(permutation[j]) - 49];
		}
		tempPermutation = result;
		std::cout << (i + 1) << ": " << result << std::endl;
	}
}	

		


