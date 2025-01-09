#include <iostream>
using namespace std;

//struct Student {
//    char name[50];
//    char surname[50];
//    int age;
//    char specialty[50];
//};
//int main()
//{
//    Student firstStudent;
//    Student firstStudent1;
//    std::cout << "Name: ";
//    std::cin.getline(firstStudent.name,50);
//    std::cout << "Surname: ";
//    std::cin.getline(firstStudent.surname,50);
//    std::cout << "Age: ";
//    std::cin >> firstStudent.age;
//    std::cin.ignore();
//    std::cout << "Specialty: ";
//    std::cin.getline(firstStudent.specialty,50);
//
//    std::cout << "Name: ";
//    std::cin.getline(firstStudent1.name,50);
//    std::cout << "Surname: ";
//    std::cin.getline(firstStudent1.surname,50);
//    std::cout << "Age: ";
//    std::cin >> firstStudent1.age;
//    std::cin.ignore();
//    std::cout << "Specialty: ";
//    std::cin.getline(firstStudent1.specialty, 50); 
//
//    for (size_t i = 0; firstStudent.name[i] != '\0'; i++) {
//        std::cout << firstStudent.name[i];
//    }
//    std::cout << " ";
//    for (size_t i = 0; firstStudent.surname[i] != '\0'; i++) {
//        std::cout << firstStudent.surname[i];
//    }
//    std::cout << " " << firstStudent.age << " ";
//    for (size_t i = 0; firstStudent.specialty[i] != '\0'; i++) {
//        std::cout << firstStudent.specialty[i];
//    }
//    std::cout << std::endl;
//
//    for (size_t i = 0; firstStudent1.name[i] != '\0'; i++) {
//        std::cout << firstStudent1.name[i];
//    }
//    std::cout << " ";
//    for (size_t i = 0; firstStudent1.surname[i] != '\0'; i++) {
//        std::cout << firstStudent1.surname[i];
//    }
//    std::cout << firstStudent1.age << " ";
//    for (size_t i = 0; firstStudent1.specialty[i] != '\0'; i++) {
//        std::cout << firstStudent1.specialty[i];
//    }
//}




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
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void selectionSort(double* array, int N)
{
	size_t minIndex = 0;
	for (size_t i = 0; i < N; i++)
	{
		minIndex = i;
		for (size_t	j = i; j < N; j++)
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
}
