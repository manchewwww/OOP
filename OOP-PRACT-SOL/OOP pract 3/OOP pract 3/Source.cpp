#include <iostream>
#include <fstream>
#pragma warning (disable: 4996)
const int MAXSIZE = 1024;

	/*1.
	int main()
	{
		std::ifstream sourceFile("test.txt");
		if (!sourceFile.is_open()) {
			std::cout << "File is not open";
			return -1;
		}
		std::ofstream destFile("test1.txt", std::ios::trunc);
		if (!destFile.is_open()) {
			std::cout << "File is not open";
			return -1;
		}
		char buffer[MAXSIZE];
		while (!myFile.eof())
		{
			sourceFile.getline(buffer, 1024, '\n');
			destFile << buffer;
			destFile << '\n';
		}
		sourceFile.close();
		destFile.close();
	}*/

	/*2.
	int isContain(const char* buffer, const char* array) {
		int counter = 1;
		char currentWord[MAXSIZE];
		int size = 0;
		for (size_t i = 0; buffer[i] != '\0'; i++) {
			if (buffer[i] == ' ') {
				currentWord[size] = '\0';
				if (!strcmp(array, currentWord)) {
					return counter;
				}	
				counter++;
				size = 0;
				continue;
			}

			currentWord[size] = buffer[i];
			size++;
		}
		currentWord[size] = '\0';
		if (!strcmp(array, currentWord)) {
			return counter;
		}
		return -1;
	}
	int main()
	{
		char array[] = "Hello";
		std::ifstream sourceFile("test.txt");
		if (!sourceFile.is_open()) {
			std::cout << "File is not open";
			return -1;
		}
		char buffer[MAXSIZE];
		int counter = 0;
		int cont;
		while (!sourceFile.eof()) {
			sourceFile >> buffer;
			counter++;
			cont = isContain(buffer, array);
			if (cont != -1) {
				std::cout << counter << " " << cont;
			}
		}
	}*/

enum AnimalType
{
	dog,
	cat,
	rabbit
};
enum GenderType
{
	man,
	women
};
struct Animal
{
	AnimalType typeAnimal;
	char name[MAXSIZE];
	int year;
	GenderType gender;
};

void writeInFile(Animal& animal,const char* fileName)
{
	std::ofstream newFile(fileName);
	if (!newFile.is_open()) {
		std::cout << "File is not open \n";
		return;
	}
	newFile << animal.typeAnimal << "\n" << animal.name << "\n" << animal.year << "\n" << animal.gender;
	newFile.close();
}
void saveToObject(Animal& animal, const char* fileName)
{
	std::ifstream sourceFile(fileName);
	if (!sourceFile.is_open()) {
		std::cout << "File is not open \n";
		return;
	}
	int type;
	sourceFile >> type;
	sourceFile >> animal.name;
	sourceFile >> animal.year;

	
}
int main()
{
	Animal animal;
	animal.typeAnimal = dog;
	strcpy(animal.name, "Vancho");
	animal.year = 17;
	animal.gender = man;
	Animal newAnimal;
	writeInFile(animal, "test.txt");
	saveToObject(newAnimal, "test.txt");
}