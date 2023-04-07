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

void swapBalance(double& first, double& second)
{
    double temp = first;
    first = second;
    second = temp;
}
void swapNumber(unsigned& first, unsigned& second)
{
    double temp = first;
    first = second;
    second = temp;
}
void swapUsers(User& first, User& second)
{
    User temp = first;
    first = second;
    second = temp;
}

void selectionSortUsers(User* users, double* balance, const unsigned size)
{
    for (size_t i = 0; i < size; i++) {
        unsigned maxElementIndex = i;
        for (size_t j = i + 1; j < size; j++) {
            if (balance[maxElementIndex] < balance[j]) {
                maxElementIndex = j;
            }
        }
        if (maxElementIndex != i) {
            swapBalance(balance[i], balance[maxElementIndex]);
            swapUsers(users[i], users[maxElementIndex]);
        }
    }
}
void selectionSortTransBlock(double* balance, unsigned* count, const unsigned size)
{
    for (size_t i = 0; i < size; i++) {
        unsigned maxElementIndex = i;
        for (size_t j = i + 1; j < size; j++) {
            if (balance[maxElementIndex] < balance[j]) {
                maxElementIndex = j;
            }
        }
        if (maxElementIndex != i) {
            swapBalance(balance[i], balance[maxElementIndex]);
            swapNumber(count[i], count[maxElementIndex]);
        }

    }
}
unsigned* setNumbersOfBlock(unsigned* array, unsigned size)
{
    for (size_t i = 0; i < size; i++) {
        array[i] = i + 1;
    }
    return array;
}

unsigned getMaxId(const TransactionBlock* transBlock, unsigned size)
{
    unsigned maxId = 0;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < transBlock[i].validTransactions; j++) {
            if (maxId < transBlock[i].transactions[j].receiver) {
                maxId = transBlock[i].transactions[j].receiver;
            }
        }
    }
    return maxId;
}
unsigned getCountOfBlock(std::ifstream& file)
{
    unsigned currPoss = file.tellg();
    file.seekg(0, std::ios::end);
    unsigned size = file.tellg();
    file.seekg(currPoss, std::ios::beg);
    return (size / sizeof(TransactionBlock));
}

void writeArrayWithUsersToBinaryFile(std::ofstream& file, const User* users, const unsigned size)
{
    file.write((const char*)users, size * sizeof(User));
}

void readArrayWithUsersFromBinaryFile(std::ifstream& file, User* users, unsigned size)
{
    file.read((char*)users, size * sizeof(User));
}

void writeArrayWithTransBlockToBinaryFile(std::ofstream& file, const TransactionBlock* transBlock, const unsigned size)
{
    file.write((const char*)transBlock, size * sizeof(TransactionBlock));
}
void readArrayWithTransBlockFromBinaryFail(std::ifstream& file, TransactionBlock* transBlock, unsigned size)
{
    file.read((char*)transBlock, size * sizeof(TransactionBlock));
}

unsigned countOfUsers(std::ifstream& file)
{
    unsigned currPoss = file.tellg();
    file.seekg(0, std::ios::end);
    unsigned size = file.tellg();
    file.seekg(currPoss, std::ios::beg);
    return (size / sizeof(User));
}
void mystrcpy(char* newArray, const char* array)
{
    unsigned size = 0;
    for (unsigned i = 0; array[i] != '\0'; i++) {
        newArray[i] = array[i];
        size = i;
    }
    newArray[++size] = '\0';
}
void coppyUser(User* users, const User& user, unsigned countOfUser)
{
    users[countOfUser].id = user.id;
    mystrcpy(users[countOfUser].name, user.name);
}
void coppyInformationWithUsers(const User* users, User* newUsers, const unsigned countOfUsers)
{
    for (unsigned i = 0; i < countOfUsers; i++) {
        newUsers[i].id = users[i].id;
        mystrcpy(newUsers[i].name, users[i].name);
    }
}
bool isValidName(const User& user)
{
    for (size_t i = 1; user.name[i] != '\0'; i++) {
        if ((user.name[i] >= 'a' && user.name[i] <= 'z') || (user.name[i] >= '0' && user.name[i] <= '9') ||
            (user.name[i] >= 'A' && user.name[i] <= 'Z')) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}
int checkUserExist(User& user, User* arrWithUser, unsigned sizeOfArrayWithUser)
{
    for (unsigned i = 0; i < sizeOfArrayWithUser; i++) {
        if (strcmp(user.name, arrWithUser[i].name) == 0) {
            return i;
        }
    }
    return -1;
}
User* addUsers(User* users, const unsigned size, const unsigned countOfUser)
{
    User* newArr = new User[size];
    coppyInformationWithUsers(users, newArr, countOfUser);
    delete[] users;
    users = newArr;
    return users;
}

void createUser(User& user, int id)
{
    user.id = id;
    std::cin.getline(user.name, 128);
}
void removeUser(User* users, unsigned index, unsigned countOfUser)
{
    if (index != countOfUser)
        swapUsers(users[index], users[countOfUser - 1]);
}

void coppyInformationFromTransArray(const Transaction* transaction, Transaction* newTransaction)
{
    for (size_t i = 0; i < 16; i++) {
        newTransaction[i].sender = transaction[i].sender;
        newTransaction[i].receiver = transaction[i].receiver;
        newTransaction[i].coins = transaction[i].coins;
        newTransaction[i].time = transaction[i].time;
    }
}
void coppyInformationInBlock(const TransactionBlock* transBlock, TransactionBlock* newTransBlock, const unsigned countOfTransBlock)
{
    for (unsigned i = 0; i < countOfTransBlock; i++) {
        newTransBlock[i].id = transBlock[i].id;
        newTransBlock[i].prevBlockId = transBlock[i].prevBlockId;
        newTransBlock[i].prevBlockHash = transBlock[i].prevBlockHash;
        newTransBlock[i].validTransactions = transBlock[i].validTransactions;
        coppyInformationFromTransArray(transBlock[i].transactions, newTransBlock[i].transactions);
    }
}
TransactionBlock* resize(TransactionBlock* transBlock, const unsigned size, const unsigned countOfTransaction)
{
    TransactionBlock* newArr = new TransactionBlock[size];
    coppyInformationInBlock(transBlock, newArr, countOfTransaction);
    delete[] transBlock;
    transBlock = newArr;
    return transBlock;
}

void oneTransaction(Transaction& transaction, const unsigned sender, const unsigned receiver, const unsigned coins)
{
    transaction.sender = sender;
    transaction.receiver = receiver;
    transaction.coins = coins;
    time_t timeInSec = time(0);
    transaction.time = timeInSec;
}
double getBalanceOfUser(const TransactionBlock* transBlock, const unsigned id, const size_t size) {
    double balance = 0;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < transBlock[i].validTransactions; j++) {
            if (transBlock[i].transactions[j].sender == id) {
                balance -= transBlock[i].transactions[j].coins;
            }
            if (transBlock[i].transactions[j].receiver == id) {
                balance += transBlock[i].transactions[j].coins;
            }

        }
    }
    return balance;
}
bool isValidId(const User* user, const unsigned countOfUser, const unsigned id)
{
    for (size_t i = 0; i < countOfUser; i++) {
        if (user[i].id == id) {
            return true;
        }
    }
    return false;
}

bool verifyTransactionBlock(const TransactionBlock* transBlock, const unsigned size)
{
    for (size_t i = 1; i < size; i++) {
        if (computeHash((const unsigned char*)&transBlock[i - 1], sizeof(TransactionBlock)) != transBlock[i].prevBlockHash) {
            return false;
        }
    }
    return true;
}

double* getBalanceOfUsers(double* balanceOfUsers, const TransactionBlock* transBlock, const User* users,
    const unsigned size, const unsigned sizeOfTransBlock)
{
    for (size_t i = 0; i < size; i++) {
        balanceOfUsers[i] = getBalanceOfUser(transBlock, users[i].id, sizeOfTransBlock);
    }
    return balanceOfUsers;
}

unsigned sizeOfNum(long long secTime)
{
    unsigned size = 0;
    while (secTime != 0) {
        secTime /= 10;
        ++size;
    }
    return size;
}
long long reverseNum(long long number)
{
    long long newNum = 0;
    while (number != 0) {
        newNum = newNum * 10 + number % 10;
        number /= 10;
    }
    return newNum;
}
char* concat(char* array, const char* name, long long secTime)
{
    unsigned index = 0;
    for (size_t i = 0; name[i] != '\0'; i++) {
        array[index++] = name[i];
    }
    while (secTime != 0) {
        array[index++] = secTime % 10 + '0';
        secTime /= 10;
    }
    array[index++] = '.';
    array[index++] = 't';
    array[index++] = 'x';
    array[index++] = 't';
    array[index] = '\0';
    return array;
}
void saveUsersToFile(const User* users, const double* balance, const unsigned size)
{
    time_t secTime = time(0);
    char name[] = "Wealthiest user";
    int sizeOfName = strlen(name) + sizeOfNum(secTime) + 5;
    char* fileName = new char[sizeOfName];
    secTime = reverseNum(secTime);
    fileName = concat(fileName, name, secTime);
    std::ofstream file(fileName);
    for (unsigned i = 0; i < size; i++) {
        file << users[i].name << " " << balance[i] << "\n";
    }
    delete[] fileName;
}


double getBalanceOfOneTransBlock(const TransactionBlock& transBlock)
{
    double balance = 0;
    for (size_t i = 0; i < transBlock.validTransactions; i++) {
        balance += transBlock.transactions[i].coins;
    }
    return balance;
}
double* getBalanceOfTransBlocks(const TransactionBlock* transBlock, double* balanceOfBlock, const size_t size)
{
    for (size_t i = 0; i < size; i++) {
        balanceOfBlock[i] = getBalanceOfOneTransBlock(transBlock[i]);
    }
    return balanceOfBlock;
}
void saveTransBlockToFile(const double* balance, const unsigned* count, const unsigned size)
{
    time_t secTime = time(0);
    char name[] = "Biggest block";
    int sizeOfName = strlen(name) + sizeOfNum(secTime) + 5;
    char* fileName = new char[sizeOfName];
    secTime = reverseNum(secTime);
    fileName = concat(fileName, name, secTime);
    std::ofstream file(fileName);
    for (unsigned i = 0; i < size; i++) {
        file << balance[i] << " " << count[i] << "\n";
    }
    delete[] fileName;
}

void runProgram()
{
    unsigned idOnTransBlock = 0;
    unsigned countOfTransBlock = 0;
    std::ifstream inputTransBlockFile("blocks.dat", std::ios::binary | std::ios::in);
    if (inputTransBlockFile.is_open()) {
        countOfTransBlock = getCountOfBlock(inputTransBlockFile);
    }
    unsigned indexOfTransBlock = 4;
    if (countOfTransBlock > indexOfTransBlock) {
        indexOfTransBlock = countOfTransBlock;
    }
    TransactionBlock* transBlock = new TransactionBlock[indexOfTransBlock];
    readArrayWithTransBlockFromBinaryFail(inputTransBlockFile, transBlock, countOfTransBlock);
    inputTransBlockFile.close();
    if (countOfTransBlock != 0) {
        idOnTransBlock = transBlock[countOfTransBlock - 1].id;
    }

    unsigned id = getMaxId(transBlock, countOfTransBlock) + 1;
    unsigned countOfUser = 0;
    std::ifstream inputFile("users.dat", std::ios::binary | std::ios::in);
    if (inputFile.is_open()) {
        if (id != 1) {
            countOfUser = countOfUsers(inputFile);
        }
    }
    unsigned newIndex = 4;
    if (countOfUser > newIndex) {
        newIndex = countOfUser;
    }
    User* users = new User[newIndex];
    if (countOfUser != 0) {
        readArrayWithUsersFromBinaryFile(inputFile, users, countOfUser);
    }
    inputFile.close();

    char n = 0;
    while (n != '7') {
        std::cout << "Choose a command to continue: \n";
        std::cout << "1. Create user. \n";
        std::cout << "2. Remove user. \n";
        std::cout << "3. Send coins \n";
        std::cout << "4. Verify transactions \n";
        std::cout << "5. Wealthiest users \n";
        std::cout << "6. Biggest blocks \n";
        std::cout << "7. Exit. \n";
        std::cout << "Enter digit before command: ";

        std::cin >> n;
        std::cin.ignore();
        bool flag = false;
        if (countOfTransBlock == 0) {
            flag = true;
            ++countOfTransBlock;
            ++idOnTransBlock;
        }
        if (transBlock[countOfTransBlock - 1].validTransactions == 16 || flag) {
            if (countOfTransBlock == indexOfTransBlock) {
                indexOfTransBlock *= 2;
                transBlock = resize(transBlock, indexOfTransBlock, countOfTransBlock);
            }
            if (flag == false) {
                ++countOfTransBlock;
                ++idOnTransBlock;
            }
            if (idOnTransBlock == 1) {
                transBlock[countOfTransBlock - 1].id = idOnTransBlock;
                transBlock[countOfTransBlock - 1].prevBlockId = idOnTransBlock;
                transBlock[countOfTransBlock - 1].validTransactions = 0;
            }
            else {
                transBlock[countOfTransBlock - 1].id = idOnTransBlock;
                transBlock[countOfTransBlock - 1].prevBlockId = idOnTransBlock - 1;
                transBlock[countOfTransBlock - 1].prevBlockHash = computeHash((const unsigned char*)&(transBlock[countOfTransBlock - 2]), sizeof(TransactionBlock));
                transBlock[countOfTransBlock - 1].validTransactions = 0;
            }
        }


        switch (n)
        {
        case '1': {
            if (countOfUser == newIndex) {
                newIndex *= 2;
                users = addUsers(users, newIndex, countOfUser);
            }
            User user;
            std::cout << "Enter name of new user: ";
            createUser(user, id);
            int i = checkUserExist(user, users, countOfUser);
            if (i != -1) {
                std::cout << "User with this name exist. \n";
                break;
            }
            else if (!isValidName(user)) {
                std::cout << "Invalid name. Try again. First letter must be upper case, other must be beetween [a .. z], [0 .. 9] and [A .. Z].  \n";
                break;
            }
            coppyUser(users, user, countOfUser);
            unsigned oopCoins;
            std::cout << "Enter amount in lv: ";
            std::cin >> oopCoins;
            oopCoins *= 420;
            oneTransaction(transBlock[countOfTransBlock - 1].transactions[transBlock[countOfTransBlock - 1].validTransactions], 0, id, oopCoins);
            transBlock[countOfTransBlock - 1].validTransactions++;
            countOfUser++;
            id++;
            break;
        }
        case '2': {
            User user;
            std::cout << "Enter name of the user you want to remove: ";
            createUser(user, 0);
            unsigned i = checkUserExist(user, users, countOfUser);
            if (i == -1) {
                std::cout << "Does not exist user with this name. Try again. \n";
                break;
            }
            double balance = getBalanceOfUser(transBlock, users[i].id, idOnTransBlock);
            oneTransaction(transBlock[countOfTransBlock - 1].transactions[transBlock[countOfTransBlock - 1].validTransactions], users[i].id, 0, balance);
            removeUser(users, i, countOfUser);
            transBlock[countOfTransBlock - 1].validTransactions++;
            countOfUser--;
            break;
        }
        case '3': {
            unsigned senderId, receiverId;
            double balanceOfUser, transactionAmount;
            std::cout << "Enter sender id: ";
            std::cin >> senderId;
            if (!isValidId(users, countOfUser, senderId)) {
                std::cout << "We do not have sender with this id. \n";
                break;
            }
            std::cout << "Enter receiver id: ";
            std::cin >> receiverId;
            if (!isValidId(users, countOfUser, receiverId)) {
                std::cout << "We do not have receiver with this id. \n";
                break;
            }
            std::cout << "Enter transaction amount: ";
            std::cin >> transactionAmount;
            balanceOfUser = getBalanceOfUser(transBlock, senderId, idOnTransBlock);
            if (balanceOfUser < transactionAmount) {
                std::cout << "Amount of transaction is bigger than balance of sender.\n";
                break;
            }
            oneTransaction(transBlock[countOfTransBlock - 1].transactions[transBlock[countOfTransBlock - 1].validTransactions], senderId, receiverId, transactionAmount);
            transBlock[countOfTransBlock - 1].validTransactions++;
            break;
        }
        case '4': {
            if (!verifyTransactionBlock(transBlock, countOfTransBlock)) {
                std::cout << "Transaction block is not verified successfully. Some data is changed. All information will be deleted. ";
                std::ofstream file("users.dat");
                file.close();
                std::ofstream fileBlock("blocks.dat");
                fileBlock.close();
                return;
            }
            else {
                std::cout << "Transaction is verified successfully. \n";
            }
            break;
        }
        case '5': {
            double* balanceOfUsers = new double[countOfUser];
            balanceOfUsers = getBalanceOfUsers(balanceOfUsers, transBlock, users, countOfUser, idOnTransBlock);
            selectionSortUsers(users, balanceOfUsers, countOfUser);
            unsigned userToSaveInFile;
            std::cout << "Enter the number of users you want to save to the file: ";
            std::cin >> userToSaveInFile;
            if (userToSaveInFile > countOfUser) {
                std::cout << "We do not have enough users. We save all users which we have. \n";
                userToSaveInFile = countOfUser;
            }
            saveUsersToFile(users, balanceOfUsers, userToSaveInFile);
            delete[] balanceOfUsers;
            break;
        }
        case '6': {
            double* balanceOfTransBlocks = new double[countOfTransBlock];
            balanceOfTransBlocks = getBalanceOfTransBlocks(transBlock, balanceOfTransBlocks, countOfTransBlock);
            unsigned* numberOfBlock = new unsigned[countOfTransBlock];
            numberOfBlock = setNumbersOfBlock(numberOfBlock, countOfTransBlock);
            selectionSortTransBlock(balanceOfTransBlocks, numberOfBlock, countOfTransBlock);
            unsigned transBlockToSaveInFile;
            std::cout << "Enter the number of transaction block you want to save to the file: ";
            std::cin >> transBlockToSaveInFile;
            if (transBlockToSaveInFile > countOfTransBlock) {
                std::cout << "We do not have enough transaction block. We save all transacion block which we have. \n";
                transBlockToSaveInFile = countOfTransBlock;
            }
            saveTransBlockToFile(balanceOfTransBlocks, numberOfBlock, transBlockToSaveInFile);
            delete[] balanceOfTransBlocks;
            delete[] numberOfBlock;
            break;
        }
        case '7': {
            std::ofstream outputFile("users.dat", std::ios::out | std::ios::binary);
            if (!outputFile.is_open()) {
                std::cout << "File is not open";
                return;
            }
            writeArrayWithUsersToBinaryFile(outputFile, users, countOfUser);
            outputFile.close();

            std::ofstream outputTransBlockFile("blocks.dat", std::ios::out | std::ios::binary);
            if (!outputTransBlockFile.is_open()) {
                std::cout << "File is not open";
                return;
            }
            writeArrayWithTransBlockToBinaryFile(outputTransBlockFile, transBlock, countOfTransBlock);
            outputTransBlockFile.close();
            delete[] transBlock;
            delete[] users;
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
int main()
{
    runProgram();
}