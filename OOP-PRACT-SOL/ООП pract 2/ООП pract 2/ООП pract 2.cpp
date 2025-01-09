#include <iostream>

	
	enum Subject
	{
		A,
		GEOM,
		OOP,
		DIS
	};
	struct Student
	{
		char name[100];
		char egn[11];
		char facNum[11];
		int grade[5];
		Subject subject;
	};
	struct Classroom
	{
		Student array[20];

	};
	void initialize(Student& s) {
		std::cout << "Enter name of student: ";
		std::cin.getline(s.name, 100);
		std::cout << "Enter egn: ";
		std::cin.getline(s.egn, 11);
		std::cout << "Enter fac number: ";
		std::cin.getline(s.facNum, 11);
		std::cout << "Enter grades: ";
		for (size_t i = 0; i < 5; i++) {
			std::cin >> s.grade[i];
		}
		std::cin.ignore();
		char array[5];
		std::cout << "Enter favorite subject: ";
		std::cin.getline(array, 5);

		if (!strcmp(array, "A")) {
			s.subject = A;
		}
		else if (!strcmp(array, "GEOM")) {
			s.subject = GEOM;
		}
		else if (!strcmp(array, "OOP")) {
			s.subject = OOP;
		}
		else if (!strcmp(array, "DIS")) {
			s.subject = DIS;
		}
	}
	void print(const Student& s) {
		std::cout << "Name: " << s.name << ", " << "EGN: " << s.egn << ", "
				  << "Fac number: " << s.facNum << ", " << "Grades: ";
		for (size_t i = 0; i < 5; i++) {
			std::cout << s.grade[i] << " ";
		}
		std::cout << ", ";
		switch (s.subject)
		{
		case DIS: std::cout << "Favorite subject: DIS";
			break;
		case A: std::cout << "Favorite subject: A";
			break;
		case OOP: std::cout << "Favorite subject: OOP";
			break;
		case GEOM: std::cout << "Favorite subject: GEOM";
			break;
		}
		std::cout << ", ";
	}
	void printAverageMarks(Student students, size_t count) {
		double averageMarks = 0;
		for (size_t j = 0; j < 5; j++) {
			averageMarks += students.grade[j];
		}
		averageMarks /= 5;
		std::cout << "Average mark: " << averageMarks << std::endl;
	}
	Student& getBestStudent(Student* students, size_t count) {
		int maxAverageMarks = 0;
		int maxIndex = 0;
		double averageMarks;
		for (size_t i = 0; i < count; i++) {
			averageMarks = 0;
			for (size_t j = 0; j < 5; j++) {
				averageMarks += students[i].grade[j];
			}
			averageMarks /= 5;
			if (maxAverageMarks < averageMarks) {
				maxIndex = i;
			}
		}
		return students[maxIndex];
	}



	int main()
	{
		int n;
		std::cout << "Enter number of students: ";
		std::cin >> n;
		std::cin.ignore();
		Student* students = new Student[n];
		for (size_t i = 0; i < n; i++) {
			initialize(students[i]);
		}
		for (size_t i = 0; i < n; i++) {
			print(students[i]);
			printAverageMarks(students[i], n);
		}
		Student student = getBestStudent(students, n);
		std::cout << std::endl << "The best student: " << student.name;
	
		delete[] students;
	}



	/*2.
	struct point
	{
		int x;
		int y;
	};
	struct line
	{
		point line[2];
	};
	void inputcordofpoint(point& point) {
		std::cin >> point.x;
		std::cin >> point.y;
	}
	void outputcordofpoint(point& point) {
		std::cout << point.x << " ";
		std::cout << point.y << std::endl;
	}
	void initializeline(line& line) {
		for (size_t i = 0; i < 2; i++) {
			inputcordofpoint(line.line[i]);
		}
	}
	double distancebetweentwopoints(const point& firstpoint, const point& secondpoint) {
		int dx = firstpoint.x - secondpoint.x;
		int dy = firstpoint.y - secondpoint.y;

		return sqrt(dx * dx + dy * dy);
	}
	double longestline(double* arr, int size) {
		double maxline = arr[0];
		for (size_t i = 1; i < size; i++) {
			if (maxline < arr[i]) {
				maxline = arr[i];
			}
		}
		return maxline;
	}
	void swap(double& a, double& b) {
		int temp = a;
		a = b;
		b = temp;
	}
	void selectionsort(double* arr, int size) {
		int theshortestline;
		int minindex;
		for (size_t i = 0; i < size - 1; i++) {
			theshortestline = arr[i];
			minindex = i;
			for (size_t j = i + 1; j < size; j++) {
				if (theshortestline > arr[j]) {
					minindex = j;
					theshortestline = arr[j];
				}
			}
			if (i != minindex) {
				swap(arr[i], arr[minindex]);
			}
		}
	}
	void output(double* arr, int size) {
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
	}
	int main() {
		point a, b;
		inputcordofpoint(a);
		inputcordofpoint(b);
		outputcordofpoint(a);
		outputcordofpoint(b);
		std::cout << "distance between two point: " << distancebetweentwopoints(a, b);
		int size;
		std::cin >> size;
		line* pointsonline = new line[size];
		double* sizeoflines = new double[size];
		for (size_t i = 0; i < size; i++) {
			initializeline(pointsonline[i]);
			sizeoflines[i] = distancebetweentwopoints(pointsonline[i].line[0], pointsonline[i].line[1]);
		}
		double maxline = longestline(sizeoflines, size);
		std::cout << "longest line: " << maxline << std::endl;
		selectionsort(sizeoflines, size);
		std::cout << "sort array with size of line: ";
		output(sizeoflines, size);

		delete[] sizeoflines;
		delete[] pointsonline;
	}*/