#include <iostream>
#include <fstream>
const int MAX_SIZE = 1024;
    /*1.
    void returnNumbers(const char* fileName)
    {
        std::ifstream myfile(fileName);
        if (!myfile.is_open()) {
            std::cout << "File is not open";
            return;
        }
        int sum, mult;
        myfile >> sum >> mult;
        std::cout << sum - mult << std::endl;
        myfile.close();
    }
    int main()
    {
        int a, b, c;
        std::cin >> a >> b >> c;

        std::ofstream myFile("Result.txt");
        if (!myFile.is_open()) {
            std::cout << "File is not open";
            return -1;
        }
        myFile << a + b + c << " " << a * b * c;

        myFile.close();
        returnNumbers("Result.txt");
    }*/
    /*2.
    size_t lengthOfFile(const char* fileName)
    {
        std::ifstream myFile(fileName);
        if (!myFile.is_open()) {
            std::cout << "File is not open";
            return 0;
        }
        myFile.seekg(0, std::ios::end);
        size_t count = myFile.tellg();
        return count;
    }
    int main()
    {
        std::cout << lengthOfFile("Result.txt");
    }*/

    /*4.
    struct Pair
    {
        int a, b;
    };
    struct Relation
    {
        Pair pairs[MAX_SIZE];
        size_t size;
    };
    void InitPair(Pair& pair)
    {
        std::cin >> pair.a >> pair.b;
    }
    void ReadPairFromFile(std::ifstream& myFile, Pair& pair)
    {
        myFile >> pair.a >> pair.b;
    }
    void writePairToFile(std::ofstream& myFile, const Pair& pair)
    {
        myFile << pair.a << " " << pair.b << " ";
    }
    bool AddPairToRelation(Relation& relation, const Pair& pair)
    {
        if (relation.size >= MAX_SIZE)
        {
            std::cout << "Max number of pairs riche \n";
            return false;
        }
        relation.pairs[relation.size++] = pair;
        return true;
    }
    void WriteRelationToFile(const char fileName[], const Relation& relation)
    {
        std::ofstream myFile("Result.txt");
        if (!myFile.is_open()) {
            std::cout << "File is not open";
            return;
        }
        myFile << relation.size << " ";
        for (size_t i = 0; i < relation.size; i++)
        {
            writePairToFile(myFile, relation.pairs[i]);
        }
        myFile.close();
    }
    bool ReadRelationFromFile(const char fileName[], Relation& relation)
    {
        std::ifstream myFile(fileName);
        if (!myFile.is_open()) {
            std::cout << "File is not open";
            return false;
        }
        myFile >> relation.size;
        for (size_t i = 0; i < relation.size; i++) {
            ReadPairFromFile(myFile, relation.pairs[i]);
        }
        myFile.close();
        return true;
    }
    void PrintPair(const Pair& pairs)
    {
        std::cout << pairs.a << " " << pairs.b << std::endl;
    }
    void PrintRelation(const Relation& relations)
    {
        for (size_t i = 0; i < relations.size; i++) {
            PrintPair(relations.pairs[i]);
        }
    }
    int main()
    {
        const int SizeOfRelation = 10;
        Relation relation;
        relation.size = SizeOfRelation;
        for (size_t i = 0; i < relation.size; i++) {
            InitPair(relation.pairs[i]);
        }
        PrintRelation(relation);
        WriteRelationToFile("Result.txt", relation);
        Relation readFromFileRelation;
        ReadRelationFromFile("Result.txt", readFromFileRelation);
        PrintRelation(readFromFileRelation);
    }*/
    /*6.
    bool PrintCode(const char fileName[])
    {
        std::ifstream myCode(fileName);
        if (!myCode.is_open()) {
            return false;
        }
        while (!myCode.eof()) {
            char buffer[MAX_SIZE];
            myCode.getline(buffer, MAX_SIZE);
            std::cout << buffer << std::endl;
        }
        myCode.close();
        return true;
    }
    int main()
    {
        PrintCode("OOP сем 2.cpp");
    }*/
    /*7.MY TEST
    const int MAX_USER_SIZE = 128;
    const int MAX_System_SIZE = 100;
    struct User
    {
        char name[MAX_USER_SIZE];
        char email[MAX_USER_SIZE];
        char password[MAX_USER_SIZE];
    };
    struct System
    {
        User users[MAX_System_SIZE];
        int num = 0;
    };
    void initUser(User& user)
    {
        std::cin.getline(user.name, MAX_USER_SIZE);
        std::cin.getline(user.email, MAX_USER_SIZE);
        std::cin.getline(user.password, MAX_USER_SIZE);
    }
    void WriteUserInFail(std::ofstream& file, const User& user)
    {
        file << user.name << std::endl;
        file << user.email << std::endl;
        file << user.password << std::endl;
    }
    void ReadUserFromFile(std::ifstream& file, User& user)
    {
        if (!file.is_open()) {
            std::cout << "File is not open";
            return;
        }
        file.getline(user.name, MAX_USER_SIZE);
        file.getline(user.email, MAX_USER_SIZE);
        file.getline(user.password, MAX_USER_SIZE);
    }
    void WriteSystemInFail(const char name[], const System& system)
    {
        std::ofstream file(name, std::ios::trunc | std::ios::out);
        if (!file.is_open()) {
            std::cout << "File is not open";
            return;
        }
        int i = system.num;
        WriteUserInFail(file, system.users[i]);
        file.close();
    }
    void ReadSystemFromFail(const char name[], System& system)
    {
        std::ifstream file(name, std::ios::in);
        if (!file.is_open()) {
            std::cout << "File is not open";
            return;
        }
        size_t newSize;
        file >> newSize;
        system.num = newSize;
        for (size_t i = 0; i < system.num; i++) {
            ReadUserFromFile(file, system.users[i]);
        }
    }
    void print(const User& user)
    {
        std::cout << user.name << std::endl << user.email << std::endl << user.password << std::endl;
    }
    void login(System& mysystem) {
        char email[MAX_USER_SIZE];
        char password[MAX_USER_SIZE];
        std::cout << "Enter email" << endl;
        std::cin >> email;
        std::cout << "Enter password" << endl;
        std::cin >> password;
        bool found = false;
    
        for (int i = 0; i < mysystem.num; i++) {
            if (strcmp(email, mysystem.users[i].email) == 0 && strcmp(password, mysystem.users[i].password) == 0) {
                found = true;
                std::cout << "Login successful" << endl;
                break;
            }
        }
    
        if (!found) {
            std::cout << "Incorrect email or password!" << endl;
        }
    }
    int main()
    {
        const size_t systemSize = 3;
        System system;
        system.num = systemSize;
        for (size_t i = 0; i < system.num; i++) {
            initUser(system.users[i]);
        }
        WriteSystemInFail("Result.txt", system);
        System system;
        ReadSystemFromFail("Result.txt", system);
        login(system);
        System newUser;
        ReadSystemFromFail("Result.txt", newUser);
        for (size_t i = 0; i < newUser.num; i++) {
            print(newUser.users[i]);
        }
    }
        */
    /*7.Real test
    const int MAX_USER_SIZE = 128;
    const int MAX_System_SIZE = 100;
    struct User
    {
        char name[MAX_USER_SIZE];
        char email[MAX_USER_SIZE];
        char password[MAX_USER_SIZE];
    };
    struct System
    {
        User users[MAX_System_SIZE];
        int num = 0;
    };
    void WriteSystemToFile(System& system)
    {
        std::ofstream myFile("Result.txt");
        if (!myFile.is_open()) {
            std::cout << "File is not open.";
            return;
        }
        int i = system.num;
        myFile << system.users[i].name << " " << system.users[i].email << " " << system.users[i].password << std::endl;
        system.num++;
        myFile.close();
    }
    void ReadFromFile(System& system)
    {
        std::ifstream myFile("Result.txt");
        if (!myFile.is_open()) {
            std::cout << "File is not open.";
            return;
        }
        int i = 0;
        while (myFile >> system.users[i].name >> system.users[i].email >> system.users[i].password) {
            i++;
            if (i > MAX_System_SIZE) {
                break;
            }
        }
        system.num = i;
        myFile.close();
    }
    void Registration(System& system)
    {
        if (system.num == MAX_System_SIZE) {
            std::cout << "Max cappacity is reached";
            return;
        }
        system.num++;
        std::cout << "Enter name: ";
        std::cin >> system.users[system.num].name;
        std::cout << "Enter email: ";
        std::cin >> system.users[system.num].email;
        std::cout << "Enter password: ";
        std::cin >> system.users[system.num].password;
        WriteSystemToFile(system);
        std::cout << "Registration successfull";
    }
    void Login(System& system)
    {
        char email[MAX_USER_SIZE];
        char pass[MAX_USER_SIZE];
        std::cout << "Enter email: ";
        std::cin >> email;
        std::cout << "Enter password: ";
        std::cin >> pass;
        bool found = false;

        for (size_t i = 0; i < system.num; i++) {
            if (strcmp(email, system.users[i].email) && strcmp(pass, system.users[i].password)){
                found = true;
                std::cout << "Login successful.";
                break;
            }
        }
        if (!found) {
            std::cout << "Incorect email or password.";
        }
    }

    int main()
    {
        std::cout << "Choose a command to continue. \n";
        std::cout << "1. Registration \n";
        std::cout << "2. Login \n";
        std::cout << "3. Exit \n";
        System system;
        ReadFromFile(system);
        int n;
        std::cin >> n;
        switch (n)
        {
            case 1: {
                Registration(system);
                break;
            }
            case 2: {
                Login(system);
                break;
            }
            case 3: {
                break;
            }
        }
    }*/



