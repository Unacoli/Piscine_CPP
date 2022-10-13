#include <iostream>
#include <math.h>
#include "Array.hpp"
#define MAX_VAL 20

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
        std::cout << "numbers value: " << numbers[i] << " | mirror value: " << mirror[i] << std::endl;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        Array<char> carr(4);

        std::cout << "before assigned char array carr:\n" << carr << std::endl;
        carr[0] = 'a';
        carr[1] = 'b';
        carr[2] = 'c';
        carr[3] = 'd';
        std::cout << "after assigned char array carr:\n" << carr << std::endl;
        std::cout << "Size of numbers: " << numbers.size() << std::endl;
        std::cout << "Size of tmp: " << tmp.size() << std::endl;
        std::cout << "Size of carr: " << carr.size() << std::endl;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return (1);
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return (0);
}