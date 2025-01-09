#include <iostream>

	/*1.
	int* allocate(size_t size) {
		int* array = new int[size];
		return array;
	}
	void deallocate(int* array) {
		delete[] array;
	}
	void fillArray(int* array, const size_t& size) {
		for (size_t i = 0; i < size; i++) {
			std::cin >> array[i];
		}
	}
	int commonElements(const int* array, const int* array1, const size_t& size, const size_t& size1) {
		int commonEl = 0;
		for (size_t i = 0; i < size; i++) {
			for (size_t j = 0; j < size1; j++) {
				if (array[i] == array[j]) {
					commonEl++;
				}
			}
		}
		return commonEl;
	}
	void sameNum(int* newArray, const int* firstArray, 
		const int* secondArray, const int N, const int M) {
		int index = 0;
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j < M; j++) {
				if (firstArray[i] == secondArray[j]) {
					newArray[index] = firstArray[i];
					index++;
				}
			}
		}
	}
	void print(const int* array, int size) {
		for (size_t i = 0; i < size; i++) {
			std::cout << array[i] << " ";
		}
	}
	int main()
	{
		size_t N, M;
		std::cin >> N >> M;
		int* firstArray = allocate(N);
		int* secondArray = allocate(M);
		fillArray(firstArray, N);
		fillArray(secondArray, M);
		int commonEl = commonElements(firstArray, secondArray, N, M);
		int* newArray = new int[commonEl];
		sameNum(newArray, firstArray, secondArray, N, M);
		print(newArray, commonEl);
		deallocate(firstArray);
		deallocate(secondArray);
		deallocate(newArray);
	}*/




	/*2.
	int* allocate(size_t size) {
		int* array = new int[size];
		return array;
	}
	void deallocate(int* array) {
		delete[] array;
	}
	void fillarray(int* array, const size_t& size) {
		for (size_t i = 0; i < size; i++) {
			std::cin >> array[i];
		}
	}
	int aritprnums1loop(int* array, int n) {
		int d = array[1] - array[0];
		int count = 2;
		int multiplynum = 2;
		for (size_t i = 2; i < n; i++) {
			if (array[0] + d * multiplynum == array[i]) {
				multiplynum++;
				count++;
			}

		}
		return count;
	}
	int aritprnums2loops(int* array, int n) {
		int d = array[1] - array[0];
		int count = 2;
		for (size_t i = 2; i < n; i++) {
			for (size_t j = i; j < n ; j++) {
				if (array[0] + d * i == array[j]) {
					count++;
					break;
				}
			}
		}
		return count;
	}
	void aritpr(int* newarray ,int* array, int n) {
		int d = array[1] - array[0];
		int index = 2;
		newarray[0] = array[0];
		newarray[1] = array[1];
		for (size_t i = 2; i < n; i++) {
			for (size_t j = i; j < n; j++) {
				if (array[0] + d * i == array[j]) {
					newarray[index] = array[j];
					index++;
				}
			}
		}
	}
	void print(const int* array, int size) {
		for (size_t i = 0; i < size; i++) {
			std::cout << array[i] << " ";
		}
	}
	void isgeom(int* newarray, int* array1, int* array2, int size1, int size2) {
		int index = 0;
		bool flag = false;
		for (size_t i = 0; i < size1; i++)
		{
			flag = false;
			for (size_t j = 0; j < size2; j++)
			{
				if (array1[i] == array2[j]) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				newarray[index] = array1[i];
				index++;
			}
		}
	}
	bool isgeompr(int* array, int size) {
		double q = array[1] / (double)array[0];
		for (size_t i = 2; i < size; i++)
		{
			if (q != (array[i] / (double)array[i - 1])) {
				return false;
			}	
		}
		return true;
	}
	int main() {
		size_t n;
		std::cin >> n;
		int* array = allocate(n);
		fillarray(array, n);
		int newSize = aritprnums1loop(array, n);
		int* newarray = allocate(newSize);
		aritpr(newarray, array, n);
		print(newarray, newSize);
		int geomSize = n - newSize;
		int* geomarray = allocate(geomSize);
		isgeom(geomarray, array, newarray, n, newSize);
		std::cout << std::endl << std::boolalpha << isgeompr(geomarray, geomSize);
		deallocate(newarray);
		deallocate(array);
		deallocate(geomarray);
	}*/

	/* 3.
	void dynamicStringCopy(char* destination, const char* source) {
		int index = 0;
		for (size_t i = 0; destination[i] != '\0' ; i++) {
			destination[index] = source[i];
			index++;
		}
		destination[index] = '\0';
	}
	void print(const char* array) {
		for (size_t i = 0; array[i] != '\0'; i++) {
			std::cout << array[i] << " ";
		}
	}
	int main() {
		char* array = new char[1024];
		std::cin.getline(array, 1024);
		char* array1 = new char[1024];
		dynamicStringCopy(array1, array);
		print(array1);
		delete[] array;
		delete[] array1;
	}*/

	/*4.
	int* allocate(int size) {
		int* array = new int[size];
		return array;
	}
	void deallocate(int* array) {
		delete[] array;
	}
	void fillArray(int* array, const size_t& size) {
		for (size_t i = 0; i < size; i++) {
			std::cin >> array[i];
		}
	}
	void searchNumNotRec(int* array, int size, int M) {
		bool flag = false;
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				for (size_t k = 0; k < size; k++)
				{
					if (array[i] * array[j] * array[k] == M && !flag) {
						std::cout << "Yes! The numbers are ( " << array[i] << " * " << array[j]
							<< " * " << array[k] << " = " << M << ").";
						flag = true;
					}
				}
			}
		}
		if(!flag) {
			std::cout << "No!";
		}
	}
	void searchNumRec(int* array, int size, int M, int index, int sum = 1) {
		if (sum == M) {
			std::cout << "Yes";
			return;
		}
		else if (sum > M) {
			sum = 1;
			index = 0;
			searchNumRec(array, size, M, index , array[index + 1] * sum);
		}


	}
	int main() {
		int N, M;
		std::cin >> N >> M;
		int* array = allocate(N);
		fillArray(array, N);
		searchNumNotRec(array, N, M);

		deallocate(array);
	}*/

	//int specialElement(int array, int size) {
	//	for (size_t i = 0; i < size; i++) {
	//		if (array > array + 1) {
	//			return ++array;
	//		}
	//		++array;
	//	}
	//}
	//int getSpecialElement(int firstElementOfArray, int size) {
	//	if (size < 3) {
	//		return 0;
	//	}
	//	int a = specialElement(firstElementOfArray, size);
	//	for (size_t i = 0; i < size; i++)
	//	{
	//		if (firstElementOfArray < a) {
	//			++firstElementOfArray;
	//		}
	//		if (&firstElementOfArray == &a) {
	//			for (size_t i = 0; i < size; i++)
	//			{
	//				if (firstElementOfArray >= a) {
	//					++firstElementOfArray;
	//				
	//					continue;
	//				}
	//				else {
	//					return 0;
	//				}
	//			}
	//		}
	//	}
	//	return a;
	//}
	//void fillArray(int* array, const size_t& size) {
	//	for (size_t i = 0; i < size; i++) {
	//		std::cin >> array[i];
	//	}
	//}
	//int main() {
	//	int size;
	//	std::cin >> size;
	//	int* array = new int[size];
	//	fillArray(array, size);
	//	*array = getSpecialElement(*array, size);
	//	if (*array == 0) {
	//		array = nullptr;
	//		std::cout << "The array is not special";
	//	}
	//	else {
	//		std::cout << "The array is special. Special element is " << *array;
	//	}




	//}

