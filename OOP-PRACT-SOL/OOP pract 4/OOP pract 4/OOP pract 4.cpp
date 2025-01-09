#include <iostream>
#include <fstream>
#include <cstring>
    /*1.
    struct Student
    {
        char name[50];
        int year;
        char gender[50];
        char place[50];
    };
    Student initStudent(Student& student)
    {
        std::cin.getline(student.name, 50);
        std::cin >> student.year;
        std::cin.ignore();
        std::cin.getline(student.gender, 50);
        std::cin.getline(student.place, 50);
    
        return student;
    }
    void writeStudentInBinaryFail(std::ofstream& file, const Student& student)
    {
        if (!file.is_open()){
            std::cout << "File is not open";
            return;
        };
        file.write((const char*)& student, sizeof(student));
    }
    void readStudentFromBinaryFail(std::ifstream& file, Student& student)
    {
        if (!file.is_open()) {
            std::cout << "File is not open";
            return;
        };
        file.read((char*)&student, sizeof(student));
    }
    void print(const Student& student)
    {
        std::cout << student.name << std::endl;
        std::cout << student.year << std::endl;
        std::cout << student.gender << std::endl;
        std::cout << student.place << std::endl;
    }
    int main()
    {
        Student student;
        initStudent(student);
        std::ofstream file("id.dat", std::ios::out | std::ios::binary);
        writeStudentInBinaryFail(file, student);
        file.close();
        Student newStudent;
        std::ifstream newFile("id.dat", std::ios::in | std::ios::binary);
        readStudentFromBinaryFail(newFile, newStudent);
        print(newStudent);
    }*/
const int MAXSIZE = 50;
enum AnimalType
{
    dog,
    cat,
    rabbit,
    cow
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
struct ZooMag
{
    char nameOfZooMag[MAXSIZE];
    Animal* animals;
    int countOfAnimals = 0;
};
ZooMag initZooMag(ZooMag& zooMag)
{
    std:: cin.getline(zooMag.nameOfZooMag, MAXSIZE);
    zooMag.animals = new Animal[zooMag.countOfAnimals];
    for (size_t i = 0; i < ; i++) {
        initAnimal(zooMag.animals[zooMag.countOfAnimals]);
        zooMag.countOfAnimals++;
    }
    

}
Animal initAnimal(Animal& animal)
{
    char animalType[MAXSIZE];
    std::cin.getline(animalType, MAXSIZE);
    if (strcmp(animalType, "dog") == 0){
        animal.typeAnimal = dog;
    }
    else if (strcmp(animalType, "cat") == 0) {
        animal.typeAnimal = cat;
    }
    else if (strcmp(animalType, "rabbit")) {
        animal.typeAnimal = rabbit;
    }
    else if (strcmp(animalType, "cow")) {
        animal.typeAnimal = cow;
    }
    std::cin.getline(animal.name, MAXSIZE);
    std::cin >> animal.year;
    std::cin.ignore();
    char genderType[MAXSIZE];
    std::cin.getline(genderType, MAXSIZE);
    if (strcmp(genderType, "man") == 0) {
        animal.gender = man;
    }
    else if (strcmp(genderType, "women") == 0) {
        animal.gender = women;
    }
    return animal;
}
void writeAnimalInFile(std::ofstream& file, const Animal& animal)
{
    file.write((const char*)& animal, sizeof(animal));
}
void readAnimalFromFile(std::ifstream& file, Animal& animal)
{
    file.read((char*)&animal, sizeof(animal));
}
void print(const Animal& animal)
{
    switch (animal.typeAnimal)
    {
    case dog: std::cout << "dog" << std::endl; break;
    case cat: std::cout << "cat" << std::endl; break;
    case rabbit: std::cout << "rabbit" << std::endl; break;
    case cow: std::cout << "cow" << std::endl; break;
    }
    std::cout << animal.name << std::endl;
    std::cout << animal.year << std::endl;
    switch (animal.gender)
    {
    case man: std::cout << "man" << std::endl; break;
    case women: std::cout << "women" << std::endl; break;
    }
}
int main()
{
    Animal animal;
    initAnimal(animal);
    std::ofstream file("id.dat", std::ios::out | std::ios::binary);
    if (!file.is_open()) {
        std::cout << "File is not open";
        return -1;
    }
    writeAnimalInFile(file, animal);
    file.close();
    std::ifstream newFile("id.dat", std::ios::in | std::ios::binary);
    if (!newFile.is_open()) {
        std::cout << "File is not open";
        return -1;
    }
    Animal newAnimal;
    readAnimalFromFile(newFile, newAnimal);
    print(newAnimal);
    newFile.close();
}

    /*4.
    struct Student
    {
        unsigned int fn;
        unsigned int takenExam;
        unsigned int failedExam;
        double averageOfPassedExam;
    };
    Student initStudent(Student& student)
    {
        std::cin >> student.fn >> student.takenExam >> student.failedExam >> student.averageOfPassedExam;
        return student;
    }
    Student* initArrayWithStudent(Student* array, unsigned int size)
    {
        for (size_t i = 0; i < size; i++)
        {
            initStudent(array[i]);
        }
        return array;
    }
    void writeStudentInBinaryFail(std::ofstream& file, const Student& student)
    {
        file.write((const char*)& student,sizeof(student));
    }
    void writeArrayInBinaryFail(const char name[], Student* student, int size)
    {
        std::ofstream file(name, std::ios::out | std::ios::binary);
        if (!file.is_open()) {
            std::cout << "File is not open";
            return;
        }
        for (size_t i = 0; i < size; i++) {
            writeStudentInBinaryFail(file, student[i]);
        }
        file.close();
    }
    void readStudentFromBinaryFail(std::ifstream& file, Student& student)
    {
        file.read((char*)&student,sizeof(student));
    }
    void readArrayFromBinaryFail(const char name[], Student* student, int size)
    {
        std::ifstream newFile(name, std::ios::in | std::ios::binary);
        if (!newFile.is_open()) {
            std::cout << "File is not open";
            return;
        }
        for (size_t i = 0; i < size; i++) {
            readStudentFromBinaryFail(newFile, student[i]);
        }
        newFile.close();
    }
    void print(const Student& student)
    {
        std::cout << std::endl;
        std::cout << student.fn << std::endl;
        std::cout << student.takenExam << std::endl;
        std::cout << student.failedExam << std::endl;
        std::cout << student.averageOfPassedExam << std::endl;
        std::cout << std::endl;
    }
    int main()
    {
        size_t size;
        std::cin >> size;
        Student* arrayWithStudents = new Student[size];
        initArrayWithStudent(arrayWithStudents, size);
        for (size_t i = 0; i < size; i++) {
            print(arrayWithStudents[i]);
        }
        writeArrayInBinaryFail("id.dat", arrayWithStudents, size);
        delete[] arrayWithStudents;
        Student* newArrayWithStudents = new Student[size];
        readArrayFromBinaryFail("id.dat", newArrayWithStudents, size);
        for (size_t i = 0; i < size; i++) {
            print(newArrayWithStudents[i]);
        }
        delete[] newArrayWithStudents;
    }
    }*/

    
    
