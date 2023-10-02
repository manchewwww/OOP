#pragma once
#include "Set.hpp"
#include <fstream>
template<typename T>
class Program {
private:
	Set<T>** sets;
	unsigned size = 0;
public:
	Program(const Program& other);
	Program<T>& operator=(const Program& other);
	~Program();
	void run(const char* fileName);
private:
	void free();
	void copyFrom(const Program& other);
	unsigned getLineCount(std::ifstream& ifs);
	void readBinaryFile(const char* fileName);
};

template<typename T>
inline Program<T>::Program(const Program& other)
{
	copyFrom(other);
}

template<typename T>
inline Program<T>& Program<T>::operator=(const Program& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline Program<T>::~Program()
{
	free();
}

template<typename T>
inline void Program<T>::run(const char* fileName)
{
	std::ifstream ifs(fileName);
	if (!ifs.good()) {
		throw std::invalid_argument("File is not open");
	}
	size = getLineCount(ifs);
	for (size_t i = 0; i < size; i++) {
		char buff[1024];
		ifs.getline(buff, 1024);

	}
	ifs.close;
}

template<typename T>
inline void Program<T>::free()
{
	for (size_t i = 0; i < size; i++) {
		delete sets[i];
	}
	delete[] sets;
}

template<typename T>
inline void Program<T>::copyFrom(const Program& other)
{
	size = other.size;
	sets = new Set<T>*[size];
	for (size_t i = 0; i < size; i++) {
		sets[i] = other.sets[i]->clone;
	}
}

template<typename T>
inline unsigned Program<T>::getLineCount(std::ifstream& ifs)
{
	int currPos = ifs.tellg();
	ifs.seekg(0, std::ios::beg);
	unsigned size = 0;
	while (!ifs.eof())
	{
		char* buff[1024];
		ifs.getline(buff, 1024);
		size++;
	}
	ifs.seekg(currPos);
	return (size - 1);
}

template<typename T>
inline void Program<T>::readBinaryFile(const char* fileName)
{
	int N, P;
	std::ifstream ifs(fileName, std::ios::binary);
	if (!ifs.good()) {
		throw std::invalid_argument("File is not open");
	}
	ifs.read(N, sizeof(int));
	ifs.read(P, sizeof(int));

	ifs.close();
}
