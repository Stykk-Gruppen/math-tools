#include <iostream>
#include <algorithm>
#include <vector>

std::string spacePadding(const int a)
{
	std::string ret = "  ";
	int temp = a;
	while (temp /= 10)
	{
		ret.pop_back();
	}
	return ret;
}

void help()
{
	std::cout << "Usage: ./multiplikasjonstabell <integer>" << std::endl;
}

int main(int argc, char *argv[])
{
	int a;
	if (argc < 2)
	{
		help();
		return 1;
	}

	std::string argument = argv[1];
	try
	{
		a = std::stoi(argument);
	}
	catch (std::invalid_argument const &e)
	{
		help();
		return 1;
	}
	std::vector<std::string> ideals = {"Z/0"};
	std::string dashes = "---";
	std::cout << "*  |  ";

	for (int i = 0; i < a; i++)
	{
		dashes += "---";
		std::cout << i << spacePadding(i);
	}
	std::cout << std::endl << dashes << std::endl;

	for (int i = 0; i < a; i++)
	{
		std::cout << i << spacePadding(i) << "|  ";
		for (int j = 0; j < a; j++)
		{
			int temp = (i*j) % a;
			if (i != 0 && j != 0 && temp == 0)
			{
				std::string str = "Z/";
				str += std::to_string(i);
				if (std::find(ideals.begin(), ideals.end(), str) == ideals.end())
				{
					ideals.push_back(str);
				}
			}
			std::cout << temp << spacePadding(temp);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "Idealer: {";
	for (int i = 0; i < ideals.size(); i++)
	{
		std::cout << ideals[i]; 
		if (i < (ideals.size() - 1))
		{
			std::cout << ", ";
		}

	}
	std::cout << "}" << std::endl;
}
