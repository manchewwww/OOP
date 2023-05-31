#include <iostream>
#include <fstream>
#include "Base.h"
#include "Book.h"
#include "Periodical.h"
#include "Comic.h"
#include "User.h"
#include "Library.h"
#include <ctime>


void printFunction() {
	std::cout << "1.Add print edition." << std::endl;
	std::cout << "2.Remove print edition." << std::endl;
	std::cout << "3.Print print editions." << std::endl;
	std::cout << "4.Add user" << std::endl;
	std::cout << "5.Remove user" << std::endl;
	std::cout << "6.Print overdue print edition." << std::endl;
	std::cout << "7.Print users who have taken out a book with a library number." << std::endl;
	std::cout << "8.Print users." << std::endl;
	std::cout << "9.Borrow print edition." << std::endl;
	std::cout << "10.Return print edition." << std::endl;
	std::cout << "11.Exit." << std::endl;
}
void printEditions() {
	std::cout << "What type of print edition you must to add.\n";
	std::cout << "1.Book.\n";
	std::cout << "2.Periodical.\n";
	std::cout << "3.Comic.\n";

}
char* readFunction() {
	char buffer[1024];
	std::cin.getline(buffer, 1024);
	char* name = new char[strlen(buffer) + 1];
	strcpy(name, buffer);
	return name;
}

void saveEditionsInFile(const Library& other, const char* name) {
	std::ofstream file(name);
	if (!file.is_open()) {
		return;
	}
	unsigned size = other.getSizeOfLibrary();
	const Base* const* lib = other.getLibrary();
	const int* count = other.getCountOfBooks();
	for (size_t i = 0; i < size; i++) {
		lib[i]->saveInFile(file);
		file << count[i] << std::endl;
	}
	file.close();
}
char* readTypePerEdition(std::istream& in) {
	char buffer[1024];
	in.getline(buffer, 1024);
	char* name = new char[strlen(buffer) + 1];
	strcpy(name, buffer);
	return name;
}
void readEditionFromFile(Library& other, const char* name) {
	std::ifstream file(name);
	if (file.fail()) {
		return;
	}
	char* libraryType;
	while (!file.eof())
	{
		libraryType = readTypePerEdition(file);
		if (strcmp(libraryType, "Book") == 0) {
			Book book;
			int count;
			file >> book;
			file >> (Base&)book;
			file >> count;
			file.ignore();
			other.addPrintEdition(&book, count);
		}
		else if (strcmp(libraryType, "Periodical") == 0) {
			Periodical periodical;
			int count;
			file >> periodical;
			file >> (Base&)periodical;
			file >> count;
			file.ignore();
			other.addPrintEdition(&periodical, count);
		}
		else if (strcmp(libraryType, "Comic") == 0) {
			Comic comic;
			int count;
			file >> (Book&)comic;
			file >> (Periodical&)comic;
			file >> (Base&)comic;
			file >> count;
			file.ignore();
			other.addPrintEdition(&comic, count);
		}
		delete[] libraryType;
	}
	file.close();
}

void readUsersFromFile(Library& other, const char* name) {
	std::ifstream file(name);
	if (file.fail()) {
		return;
	}
	int size = 0;
	file >> size;
	file.ignore();
	for (unsigned i = 0; i < size; i++){
		User user;
		file >> user;
		other.addUser(user);
	}
	file.close();
}
void saveUsersInFile(const Library& other, const char* name) {
	std::ofstream file(name);
	if (!file.is_open()) {
		return;
	}

	int size = other.getSizeOfUsers();
	const User* users = other.getUsers();
	file << size << std::endl;
	for (size_t i = 0; i < size; i++) {
		file << users[i];
	}
}

int main()
{
	Library test;
	readEditionFromFile(test, "Period editions.txt");
	readUsersFromFile(test, "Users.txt");
	while (true) {
		char* index;
		printFunction();
		std::cout << "Enter number before command: ";
		index = readFunction();
		if (strcmp(index, "1") == 0) {
			char printEd = 0;
			printEditions();
			std::cout << "Enter number before print edition: ";
			std::cin >> printEd;
			std::cin.ignore();
			switch (printEd)
			{
			case '1': {
				Book book;
				int count;
				std::cin >> book;
				std::cin >> (Base&)book;
				std::cout << "Enter count of book: ";
				std::cin >> count;
				std::cin.ignore();
				try
				{
					test.addPrintEdition(&book, count);
				}
				catch (const std::invalid_argument& e)
				{
					std::cout << e.what() << std::endl;
				}
			}break;
			case '2': {
				Periodical periodical;
				int count;
				std::cin >> periodical;
				std::cin >> (Base&)periodical;
				std::cout << "Enter count of periodical: ";
				std::cin >> count;
				std::cin.ignore();
				try
				{
					test.addPrintEdition(&periodical, count);
				}
				catch (const std::invalid_argument& e)
				{
					std::cout << e.what() << std::endl;
				}
			}break;
			case '3': {
				Comic comic;
				int count;
				std::cin >> (Book&)comic;
				std::cin >> (Periodical&)comic;
				std::cin >> (Base&)comic;
				std::cout << "Enter count of comic: ";
				std::cin >> count;
				std::cin.ignore();
				try
				{
					test.addPrintEdition(&comic, count);
				}
				catch (const std::invalid_argument& e)
				{
					std::cout << e.what() << std::endl;
				}
			} break;
			default: std::cout << "We don't support this type of print edition!\n";
				break;
			}
		}
		else if (strcmp(index, "2") == 0) {
			int libraryNumber;
			std::cout << "Enter library number: ";
			std::cin >> libraryNumber;
			std::cin.ignore();
			try{
				test.removePrintEdition(libraryNumber);
			} catch (const std::invalid_argument& e) {
				std::cout << e.what() << std::endl;
			}
		}
		else if (strcmp(index, "3") == 0) {
			test.print();
		}
		else if (strcmp(index, "4") == 0) {
			std::cout << "Enter username: ";
			char* name = readFunction();
			try {
				test.addUser(name);
			}
			catch (const std::invalid_argument& e) {
				std::cout << e.what() << std::endl;
			}
			delete[] name;
		}
		else if (strcmp(index, "5") == 0) {
			std::cout << "Enter username: ";
			char* name = readFunction();
			try {
				test.removeUser(name);
			}
			catch (const std::invalid_argument& e) {
				std::cout << e.what() << std::endl;
			}
			delete[] name;
		}
		else if (strcmp(index, "6") == 0) {
			try
			{
				test.printOverduePrintEdition();
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else if (strcmp(index, "7") == 0) {
			int libraryNumber;
			std::cout << "Enter library number: ";
			std::cin >> libraryNumber;
			std::cin.ignore();
			try
			{
				test.printUsersWhichHaveTakenBookWithLibraryNumber(libraryNumber);
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else if (strcmp(index, "8") == 0) {
			test.printUsers();
		}
		else if (strcmp(index, "9") == 0) {
			std::cout << "Enter username: ";
			char* name = readFunction();
			int libraryNumber;
			std::cout << "Enter library number: ";
			std::cin >> libraryNumber;
			std::cin.ignore();
			try {
				test.borrowingPrintEdition(name, libraryNumber);
			}
			catch (const std::invalid_argument& e) {
				std::cout << e.what() << std::endl;
			}
			delete[] name;
		}
		else if (strcmp(index, "10") == 0) {
			std::cout << "Enter username: ";
			char* name = readFunction();
			int libraryNumber;
			std::cout << "Enter library number: ";
			std::cin >> libraryNumber;
			std::cin.ignore();
			try {
				test.returnPrintEdition(name, libraryNumber);
			}
			catch (const std::invalid_argument& e) {
				std::cout << e.what() << std::endl;
			}
			delete[] name;
		}
		else if (strcmp(index, "11") == 0) {
			saveEditionsInFile(test, "Period editions.txt");
			saveUsersInFile(test, "Users.txt");
			std::cout << "Print editions are saved correctly.";
			delete[] index;
			return 0;
		}
		else {
			std::cout << "We don't have this function. Try again.\n";
		}
		delete[] index;
	}

//time_t* timeArray = new time_t[5];
//timeArray[0] = time(0);
//timeArray[1] = time(0);
//timeArray[2] = time(0);
//timeArray[3] = time(0);
//timeArray[4] = time(0);
//time_t secTime = time(0);
//for (size_t i = 0; i < 5; i++)
//{
//	std::cout << timeArray[i] << " ";
//}
//std::cout << secTime;
}