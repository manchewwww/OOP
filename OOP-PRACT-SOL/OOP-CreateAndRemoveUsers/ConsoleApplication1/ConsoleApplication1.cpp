#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

unsigned computeHash(const unsigned char* memory, int length) {
    unsigned hash = 0xbeaf;
    for (int c = 0; c < length; c++) {
        hash += memory[c];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
}
struct User {
    unsigned id;
    char name[128];
};
struct Transaction {
    unsigned sender;
    unsigned receiver;
    double coins;
    long long time;
};
struct TransactionBlock {
    unsigned id;
    unsigned prevBlockId;
    unsigned prevBlockHash;
    int validTransactions;
    Transaction transactions[16];
};
void writeUserToBinaryFile(std::ofstream& file, const User& user)
{
    file.write((const char*)&user, sizeof(user));
}
void writeArrayWithUsersToBinaryFile(std::ofstream& file, const User* users, const size_t size)
{
    for (size_t i = 0; i < size; i++) {
        writeUserToBinaryFile(file, users[i]);
    }
}
void readUserFromBinaryFile(std::ifstream& file, User& user)
{
    file.read((char*)&user, sizeof(user));
}
void readArrayWithUsersFromBinaryFile(std::ifstream& file, User* users, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        readUserFromBinaryFile(file, users[i]);
    }
}
int countOfUsers(std::ifstream& file)
{
    size_t currPoss = file.tellg();
    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    file.seekg(currPoss, std::ios::beg);
    size -= sizeof(int);
    return (size / sizeof(User));
}
bool checkUserExist(User& user, User* arrWithUser, size_t sizeOfArrayWithUser)
{
    for (size_t i = 0; i < sizeOfArrayWithUser; i++) {
        if (strcmp(user.name, arrWithUser[i].name) == 0) {
            return false;
        }
    }
    return true;
}
int getId(std::ifstream& file, int id)
{
    file.read((char*)&id, sizeof(id));
    return id;
}
void createUser(User& user, int size)
{
    user.id = size;
    std::cin.getline(user.name, 128);
}
void print(User* users, int size)
{
    for (size_t i = 0; i < size; i++) {
        std::cout << users[i].id << " " << users[i].name << std::endl;
    }
}

bool containsUserForRemove(const User& user, const User* arrWithUser, const size_t sizeOfArrayWithUser)
{
    for (size_t i = 0; i < sizeOfArrayWithUser; i++) {
        if (strcmp(user.name, arrWithUser[i].name) == 0) {
            return true;
        }
    }
    return false;
}
void mystrcpy(char* newArray, const char* array)
{
    size_t size = 0;
    for (size_t i = 0; array[i] != '\0'; i++) {
        newArray[i] = array[i];
        size = i;
    }
    newArray[++size] = '\0';
}
void removeUser(User user, User* newArrWithUsers, int newSize, const User* arrWithUser, const int sizeOfArrayWithUser)
{
    size_t index = 0;
    for (size_t i = 0; i < sizeOfArrayWithUser; i++) {
        if (strcmp(user.name, arrWithUser[i].name) == 0) {
            continue;
        }
        newArrWithUsers[index].id = arrWithUser[i].id;
        mystrcpy(newArrWithUsers[index].name, arrWithUser[i].name);
        index++;
    }


}


int main()
{
    std::ofstream f("users.dat", std::ios::trunc | std::ios::binary);
    User u = { 0,"Admin" };
    f.write((const char*)&u.id, sizeof(int));
    f.write((const char*)&u, sizeof(User));
    f.close();

    int n = 0;
    while (n != 3) {
        std::cout << "Choose a command to continue: \n";
        std::cout << "1. Create user. \n";
        std::cout << "2. Remove user. \n";
        std::cout << "3. Exit. \n";
        std::cout << "Enter digit before command: ";
        std::cin >> n;
        std::cin.ignore();
        switch (n)
        {
        case 1: {
            std::ifstream inputFile("users.dat", std::ios::binary | std::ios::in);
            if (!inputFile.is_open()) {
                std::cout << "File is not open.";
                return -1;
            }
            int id = 0;
            id = getId(inputFile, id);
            size_t countOfUser = 1;
            if (id != 0) {
                countOfUser = countOfUsers(inputFile);
            }
            User* users = new User[countOfUser];
            readArrayWithUsersFromBinaryFile(inputFile, users, countOfUser);
            inputFile.close();

            User user;
            std::cout << "Enter name of user: ";
            createUser(user, ++id);
            if (!checkUserExist(user, users, countOfUser)) {
                std::cout << "User with this name exist.";
                break;
            }
            std::ofstream outputFile("users.dat", std::ios::binary | std::ios::out);
            if (!outputFile.is_open()) {
                std::cout << "File is not open.";
                return -1;
            }
            outputFile.write((const char*)&id, sizeof(int));
            writeArrayWithUsersToBinaryFile(outputFile, users, countOfUser);
            writeUserToBinaryFile(outputFile, user);
            delete[] users;
            outputFile.close();
            {
                std::ifstream file("users.dat");
                if (!file.is_open()) {
                    std::cout << "fileisnotopen;";
                    return -1;
                }
                int id = 0;
                file.read((char*)&id, sizeof(id));
                int size = countOfUsers(file);
                User* users = new User[size];
                readArrayWithUsersFromBinaryFile(file, users, size);
                std::cout << id << std::endl;
                print(users, size);
                delete[] users;
                file.close();
                break;
            }
        }
        case 2: {
            std::ifstream inputFile("users.dat", std::ios::binary | std::ios::in);
            int id = 0;
            inputFile.read((char*)&id, sizeof(int));
            int sizeOfArrayWithUser = countOfUsers(inputFile);
            User* arrWithUser = new User[sizeOfArrayWithUser];
            readArrayWithUsersFromBinaryFile(inputFile, arrWithUser, sizeOfArrayWithUser);
            inputFile.close();
            User user;
            std::cout << "Enter name of the user you want to remove: ";
            createUser(user, 0);
            if (!containsUserForRemove(user, arrWithUser, sizeOfArrayWithUser) || strcmp(user.name, "Admin") == 0) {
                std::cout << "Does not exist user with tris name.";
                break;
            }
            std::ofstream outputFile("users.dat", std::ios::binary | std::ios::out | std::ios::trunc);
            if (!outputFile.is_open()) {
                std::cout << "File is not open";
                return -1;
            }
            int newSize = sizeOfArrayWithUser - 1;
            User* newArrWithUsers = new User[newSize];
            removeUser(user, newArrWithUsers, newSize, arrWithUser, sizeOfArrayWithUser);
            outputFile.write((const char*)&id, sizeof(int));
            writeArrayWithUsersToBinaryFile(outputFile, newArrWithUsers, newSize);
            outputFile.close();
            delete[] arrWithUser;
            delete[] newArrWithUsers;
            {
                std::ifstream file("users.dat");
                if (!file.is_open()) {
                    std::cout << "fileisnotopen;";
                    return -1;
                }
                int id = 0;
                file.read((char*)&id, sizeof(id));
                int size = countOfUsers(file);
                User* users = new User[size];
                readArrayWithUsersFromBinaryFile(file, users, size);
                print(users, size);
                delete[] users;
                file.close();
                break;
            }
            break;
        }
        case 3: {
            //writeArrayWithUsersToBinaryFail(outputFile, users, countOfUser);
            std::cout << "Exiting ...";
            break;
        }
        default:
            std::cout << "Invalid input. Try again. \nEnter digit before command:";
            continue;
            break;
        }
    }
}