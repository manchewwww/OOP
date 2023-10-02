#include <iostream>
#include <string>
#include "EndSet.hpp"
#include "IntervalSet.hpp"
#include "SetByCriteria.hpp"
#include "SequenceSet.hpp"
#include "UnionSet.hpp"
#include "Program.hpp"

bool func(int element) {
    return (element % 2 == 0);
}
int main()
{
    try
    {
        int arr[3] = { 1,2,3 };
        EndSet<int> endSet(arr, 3);
        std::cout << endSet[3] << std::endl;
        std::cout << endSet[4] << std::endl;

        IntervalSet<int> intSet(1, 4);
        std::cout << intSet[1] << std::endl;
        std::cout << intSet[5] << std::endl;

        SetByCriteria<int, bool(*)(int)> setByCriteria(func);
        std::cout << setByCriteria[2] << std::endl;
        std::cout << setByCriteria[1] << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }
}