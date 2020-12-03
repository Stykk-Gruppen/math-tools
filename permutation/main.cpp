#include <iostream>
#include <algorithm>
#include <vector>



void help()
{
	std::cout << "Usage: ./perm matrix1 matrix2 ... matrixK" << std::endl;
	std::cout << "Usage: ./perm s3" << std::endl;
	std::cout << "Usage: ./perm d6" << std::endl;
	std::cout << "Usage: ./perm d8" << std::endl;
	std::cout << "Usage: ./perm d10" << std::endl;
}

bool compareMatrix(std::vector<int> v1, std::vector<int> v2){
	for(size_t i=0;i<v1.size();i++){
		if(v1[i] != v2[i]){
			return false;
		}
	}
	return true;
}

int findAlias(std::vector<std::vector<int>> matrixVector, std::vector<int> matrix){
	for(size_t i=0;i<matrixVector.size();i++){
		if(compareMatrix(matrixVector[i],matrix)){
			return i;
		}
	}
	return -1;
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

void printAliasVector(std::vector<std::vector<int>> matrixVector){
	for(size_t i=0;i<matrixVector.size();i++){
		std::cout << "s" << i << " ";
		printVector(matrixVector[i]);
		std::cout << std::endl;
	}
}

std::vector<int> matrixMultiplication(std::vector<int> matrixA, std::vector<int> matrixB){
	std::vector<int> output;
	if(matrixA.size() != matrixB.size()){
		help();
		return output;
	}

	for(size_t i=0;i<matrixB.size();i++){
		//Since vector starts at 0, but the matrix starts at 1, we do -1 (If first element is something else, this needs to be changed)
		int aIndex = matrixB[i]-1;
		output.push_back(matrixA[aIndex]);
	}

	return output;
}

void printAliasTable(std::vector<std::vector<int>> matrixVector, std::vector<std::vector<std::vector<int>>> table){
	int rowsAndColumns = matrixVector.size();
	for(int row=-1;row<rowsAndColumns;row++){
		for(int column=-1;column<rowsAndColumns;column++){
			if(row == 0 && column == -1){
				for(size_t i=0;i<matrixVector.size()+1;i++){
					std::cout<< "---";
				}
				std::cout << std::endl;
			}
			if(column == 0){
				std::cout << "| ";
			}
			if(row == -1 && column == -1){
				std::cout<< " *";
			} else if(row == -1){
				std::cout << "s" << findAlias(matrixVector,matrixVector[column]);
			} else if(column == -1){
				std::cout << "s" << findAlias(matrixVector,matrixVector[row]);
			} else {
				std::cout << "s" << findAlias(matrixVector,table[row][column]);
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
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
	std::vector<std::vector<int>> matrixVector;
	std::vector<std::vector<int>> s3 = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,2,1},{3,1,2}};
	std::vector<std::vector<int>> d6 = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,2,1},{3,1,2}};
	std::vector<std::vector<int>> d8 = {{1,2,3,4},{2,3,4,1},{3,4,1,2},{4,1,2,3},
									{2,1,4,3},{4,3,2,1},{1,4,3,2},{3,2,1,4}};
	std::vector<std::vector<int>> d10 = {{1,2,3,4,5},{2,3,4,5,1},{3,4,5,1,2},{4,5,1,2,3},{5,1,2,3,4},
									{1,5,4,3,2},{3,2,1,5,4},{5,4,3,2,1},{2,1,5,4,3},{4,3,2,1,5}};
	int matrixNumber = argc;
	if (argc < 2)
	{
		help();
		return 1;
	} else if(argc == 2){
		std::string m = argv[1];
		if(m.compare("s3") == 0){
			matrixVector = s3;
		} else if(m.compare("d6") == 0){
			matrixVector = d6;
		} else if(m.compare("d8") == 0){
			matrixVector = d8;
		} else if(m.compare("d10") == 0){
			matrixVector = d10;
		} else {
			help();
			return 1;
		}
	} else if(argc >= 3){
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
	}
	std::vector<std::vector<std::vector<int>>> matrixMultiplicationTable = createMultiplicationTable(matrixVector);
	printAliasVector(matrixVector);
	std::cout << std::endl;
	printAliasTable(matrixVector,matrixMultiplicationTable);
	std::cout << std::endl;
	std::cout << std::endl;
	printMultiplicationTable(matrixVector,matrixMultiplicationTable);
}
