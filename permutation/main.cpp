#include <iostream>
#include <algorithm>
#include <vector>



void help()
{
	std::cout << "Usage: ./perm matrix1 matrix2 ... matrixK" << std::endl;
}

void printVector(std::vector<int> v){
	std::cout << "(";
	for(size_t i=0;i<v.size();i++){
		if(i != 0){
			std::cout << ",";
		}
		std::cout << v[i];
	}
	std::cout << ")";
}

std::vector<int> matrixMultiplication(std::vector<int> matrixA, std::vector<int> matrixB){
	std::vector<int> output;
	if(matrixA.size() != matrixB.size()){
		help();
		exit;
	}

	for(size_t i=0;i<matrixB.size();i++){
		//Since vector starts at 0, but the matrix starts at 1, we do -1 (If first element is something else, this needs to be changed)
		int aIndex = matrixB[i]-1;
		output.push_back(matrixA[aIndex]);
	}

	return output;
}

void printMultiplicationTable(std::vector<std::vector<int>> matrixVector, std::vector<std::vector<std::vector<int>>> table){
	int rowsAndColumns = matrixVector.size();
	for(int row=-1;row<rowsAndColumns;row++){
		for(int column=-1;column<rowsAndColumns;column++){
			if(row == 0 && column == -1){
				for(size_t i=0;i<matrixVector.size()+1;i++){
					std::cout<< "--------";
				}
				std::cout << std::endl;
			}
			if(column == 0){
				std::cout << "| ";
			}
			if(row == -1 && column == -1){
				std::cout << "(";
				for(size_t i=0;i<matrixVector[0].size();i++){
					if(i != 0){
						std::cout << ",";
					}
					std::cout<< "*";
				}
				std::cout << ")";
			} else if(row == -1){
				printVector(matrixVector[column]);
			} else if(column == -1){
				printVector(matrixVector[row]);
			} else {
				printVector(table[row][column]);
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

std::vector<std::vector<std::vector<int>>> createMultiplicationTable(std::vector<std::vector<int>> matrixVector){
	int rowsAndColumns = matrixVector.size();
	std::vector<std::vector<std::vector<int>>> output;
	for(int row=0;row<rowsAndColumns;row++){
		std::vector<std::vector<int>> tempRow;
		for(int column=0;column<rowsAndColumns;column++){
			std::vector<int> tempMatrix = matrixMultiplication(matrixVector[row],matrixVector[column]);
			tempRow.push_back(tempMatrix);
		}
		output.push_back(tempRow);

	}
	return output;
}

int main(int argc, char *argv[])
{
	int matrixNumber = argc;
	if (argc < 2)
	{
		help();
		return 1;
	}

	std::vector<std::vector<int>> matrixVector; 
	try
	{
		for(int i=1;i<matrixNumber;i++){
			std::vector<int> tempVector;
			std::string stringMatrix = argv[i];
			for(size_t j=0;j<stringMatrix.size();j++){
				int tempInt = ((int)stringMatrix[j])-48;
				tempVector.push_back(tempInt);
			}
			matrixVector.push_back(tempVector);
		}
	}

	catch (std::invalid_argument const &e)
	{
		help();
		return 1;
	}
	//printVector(matrixMultiplication(matrixVector[0],matrixVector[1]));
	std::vector<std::vector<std::vector<int>>> matrixMultiplicationTable = createMultiplicationTable(matrixVector);
	printMultiplicationTable(matrixVector,matrixMultiplicationTable);
	
}
