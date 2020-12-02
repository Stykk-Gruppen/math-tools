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

void printAddTable(int a)
{
	//Create table
	std::vector<std::vector<int>> table(a, std::vector<int>(a));
	for(int i = 0; i < table.size(); i++)
	{
		for(int j = 0; j < table.size(); j++)
		{
			table.at(i).at(j) = (i + j) % a;
		}
	}

	std::cout << "Addisjonstabell:\n";
	//Print Table top row
	std::cout << "*  |";
	for(int i = 0; i < a; i++)
	{
		std::cout << "  " << i;
	}
	std::cout << std::endl;

	std::cout << "----";
	for(auto v : table)
		std::cout << "---";

	std::cout << "\n";


	for(int i = 0; i < table.size(); i++)
	{
		std::cout << i << "  |";

		for(int j = 0; j < table.at(i).size(); j++)
		{
			std::cout << "  " << table.at(i).at(j);
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n\n";
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


	printAddTable(a);


	std::cout << "Multiplikasjonstabell:\n";
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
		bool isIdeal = false;
		for (int j = 0; j < a; j++)
		{
			int temp = (i*j) % a;
			if (i != 0 && j != 0 && temp == 0)
			{
				isIdeal = true;
			}
			std::cout << temp << spacePadding(temp);
		}

		if (isIdeal)
		{
			std::string str = "Z/";
			str += std::to_string(i);
			ideals.push_back(str);
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
