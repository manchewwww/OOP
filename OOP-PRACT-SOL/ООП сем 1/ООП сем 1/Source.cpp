#include <iostream>
	/* Triangles!!!
	struct Point
	{
		double x, y;
	};
	void readPoint(Point& point)
	{
		std::cin >> point.x >> point.y;
	}
	double getSize(const Point& p1, const Point& p2)
	{
		double dx = p1.x - p2.x;
		double dy = p1.y - p2.y;
		return sqrt(dx * dx + dy * dy);
	}
	struct Triangle
	{
		Point p1, p2, p3;
	};
	void readTriangle(Triangle& triangle)
	{
		readPoint(triangle.p1);
		readPoint(triangle.p2);
		readPoint(triangle.p3);
	}
	double getArea(const Triangle& triangle)
	{
		double a = getSize(triangle.p1, triangle.p2);
		double b = getSize(triangle.p3, triangle.p2);
		double c = getSize(triangle.p1, triangle.p3);
		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	double* calculateArea(const Triangle* triangles, int N)
	{
		double* areas = new double[N];
		for (size_t i = 0; i < N; i++)
		{
			areas[i] = getArea(triangles[i]);
		}
		return areas;
	}
	void swap(double& a, double& b)
	{
		double temp = a;
		a = b;
		b = temp;
	}
	void selectionSort(double* array, int N)
	{
		size_t minIndex = 0;
		for (size_t i = 0; i < N; i++)
		{
			minIndex = i;
			for (size_t j = i; j < N; j++)
			{
				if (array[i] > array[j]) {
					minIndex = j;
				}
			}
			if (minIndex != i) {
				swap(array[i], array[minIndex]);
			}
		}
	}
	int main()
	{
		int n;
		std::cin >> n;
		Triangle* triangles = new Triangle[n];
		for (size_t i = 0; i < n; i++)
		{
			readTriangle(triangles[i]);
		}
		double* areas = calculateArea(triangles, n);
		selectionSort(areas, n);
		for (size_t i = 0; i < n; i++)
		{
			std::cout << areas[i] << " ";
		}
		delete[] areas;
		delete[] triangles;
	}*/

	/* 1.
	int isLowerValue(int a, int b) {
		return a < b ? a : b;
	}
	int isLowerPointer(int* a, int* b) {
		return *a < *b ? *a : *b;
	}
	int isLowerReference(int& a, int& b) {
		return a < b ? a : b;
	}
	int isLowerConstPointer(const int* a, const int* b) {
		return *a < *b ? *a : *b;
	}
	int isLowerConstReference(const int& a, const int& b) {
		return a < b ? a : b;
	}
	int main() {
		int a, b;
		std::cin >> a >> b;
		std::cout << isLowerValue(a, b) << std::endl;
		std::cout << isLowerPointer(&a, &b) << std::endl;
		std::cout << isLowerConstPointer(&a, &b) << std::endl;
		std::cout << isLowerReference(a, b) << std::endl;
		std::cout << isLowerConstReference(a, b);
	}*/

	/*2.
	void fillArray(int* array, int N) {
		for (size_t i = 0; i < N; i++) {
			std::cin >> array[i];
		}
	}
	void deallocate(int* array) {
		delete[] array;
	}
	int biggerNums(int* array, int N, char symbol) {
		int count = 0;
		for (size_t i = 0; i < N; i++){
			if (array[i] > (int)symbol) {
				count++;
			}
		}
		return count;
	}
	int main() {
		int N;
		std::cin >> N;
		int* array = new int[N];
		fillArray(array, N);
		char symbol;
		std::cin >> symbol;
		std::cout << biggerNums(array, N, symbol);
		deallocate(array);
	}*/

	/*3.
	int** allocate(int rows, int columns) {
		int** matrix = new int* [rows];
		for (size_t i = 0; i < rows; i++) {
			matrix[i] = new int[columns];
		}
		return matrix;
	}
	void deallocate(int** matrix, int rows) {
		for (size_t i = 0; i < rows; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	void fillMatrix(int** matrix, int rows, int columns) {
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < columns; j++) {
				std::cin >> matrix[i][j];
			}
		}
	}
	int** transposeMatrix(int** matrix, int rows, int columns) {
		int row = columns;
		int col = rows;
		int** transposedMatrix = allocate(row, col);
		for (size_t i = 0; i < row; i++) {
			for (size_t j = 0; j < col; j++) {
				transposedMatrix[i][j] = matrix[j][i];
			}
		}
		return transposedMatrix;
	}
	void print(int** matrix, int rows, int cols) {
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < cols; j++) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	int main() {
		int rows, cols;
		std::cin >> rows >> cols;
		int** matrix = allocate(rows, cols);
		fillMatrix(matrix, rows, cols);
		int** transposedMatrix = transposeMatrix(matrix, rows, cols);
		print(matrix, rows, cols);
		print(transposedMatrix, cols, rows);
		deallocate(matrix, rows);
		deallocate(transposedMatrix, cols);	
	}*/

	/*4.
	struct Student
	{
		char name[30];
		unsigned int egn;
	};
	void initStudents(Student& student){
		std::cin.getline(student.name, 30);
		std::cin >> student.egn;
	}
	void printStudents(Student& student) {
		std::cout << student.name << " " << student.egn;
	}
	int main() {
		Student firstStudent;
		initStudents(firstStudent);
		printStudents(firstStudent);
	}*/

	/*5.
	struct ComplexNum
	{
		int real;
		int imaginer;
	};
	void initialiaze(ComplexNum& complexNum) {
		std::cin >> complexNum.real >> complexNum.imaginer;
	}
	ComplexNum sumOfComplexNum(const ComplexNum& first, const ComplexNum& second) {
		return { 
			first.real + second.real, 
			first.imaginer + second.imaginer
		};
	}
	void print(const ComplexNum& complexNum) {
		std::cout << complexNum.real << " + i" << complexNum.imaginer << "\n";
	}
	int main() {
		ComplexNum first, second;
		initialiaze(first);
		initialiaze(second);
		ComplexNum sum = sumOfComplexNum(first, second);
		print(sum);
	}*/

	/*6.
	struct Point
	{
		int x, y;
	};
	void initializePoint(Point& point) {
		std::cin >> point.x >> point.y;
	}
	void print(const Point& point) {
		std::cout << point.x << " " << point.y << "\n";
	}
	double distanceFromCenturToPoint(const Point& point) {
		int dx = point.x - 0;
		int dy = point.y - 0;

		return sqrt(dx * dx + dy * dy);
	}
	double distanceFromPointToPoint(const Point& firstPoint, const Point& secondPoint) {
		int dx = firstPoint.x - secondPoint.x;
		int dy = firstPoint.y - secondPoint.y;

		return sqrt(dx * dx + dy * dy);
	}
	unsigned short quadrant(const Point& point) {
		if (point.x > 0 && point.y > 0) {
			return 1;
		}
		else if (point.x > 0 && point.y < 0) {
			return 2;
		}
		else if (point.x < 0 && point.y > 0) {
			return 3;
		}
		else if(point.x < 0 && point.y < 0) {
			return 4;
		}
	}
	bool isPointInCircle(const Point& point, const double radius) {
		double distanceFromCenter = distanceFromCenturToPoint(point);
		bool pointIsInCircle = false;
		if (distanceFromCenter < radius) {
			std::cout << "Point lies inside line the circle. \n";
			pointIsInCircle = true;
		}
		else if (distanceFromCenter == radius) {
			std::cout << "Point lies on the circle. \n";
			pointIsInCircle = true;
		}
		else if (distanceFromCenter > radius) {
			std::cout << "Point lies outside the circle. \n";
		}

		return pointIsInCircle;
	}

	int main() {
		Point a;
		Point b;
		initializePoint(a);
		initializePoint(b);
		print(a);
		print(b);
		double distanceFromCenterA = round(distanceFromCenturToPoint(a) * 100) / 100;
		double distanceFromCenterB = round(distanceFromCenturToPoint(b) * 100) / 100;
		std::cout << distanceFromCenterA << std::endl;
		std::cout << distanceFromCenterB << "\n";
		double distanceBetweenAandB = round(distanceFromPointToPoint(a, b) * 100) / 100;
		std::cout << distanceBetweenAandB << "\n";
		int quadrantA = quadrant(a);
		int quadrantB = quadrant(b);
		std::cout << quadrantA << "\n";
		std::cout << quadrantB << "\n";
		isPointInCircle(a, 5);
		isPointInCircle(b, 1);
	}*/

