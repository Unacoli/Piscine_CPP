#include "easyfind.hpp"
#include <list>
#include <vector>
#include <set>
#include <array>

void    displayInt(int i)
{
    std::cout << i << std::endl;
    return ;
}

/*
**  List: linked pointers
*/

void    listTest(void)
{
    std::list<int> lst;
    int i = 0;
    while (i < 6)
    {
        lst.push_back(i);
        i++;
    }
    std::for_each(lst.begin(), lst.end(), displayInt);
    std::cout << std::endl;
    std::cout << "Looking for 2 in list: " << easyfind(lst, 2) << std::endl;
    try
    {
        std::cout << "Looking for -12 in list: " << easyfind(lst, -12) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return ;
}

/*
**  Vector: dynamic array
**  Store data like a regular array
*/

void    vectorTest(void)
{
    std::vector<int> vector;
    int i = 0;
    while (i < 6)
    {
        vector.push_back(i);
        i++;
    }
    std::for_each(vector.begin(), vector.end(), displayInt);
    std::cout << std::endl;
    std::cout << "Looking for 2 in vector: " << easyfind(vector, 2) << std::endl;
    try
    {
        std::cout << "Looking for -12 in vector: " << easyfind(vector, -12) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return ;
}

/*
**  Set: store unique elements in a specific order
**  Equivalent to a stack, data are insert on the top
**  Each value must be unique
*/

void    setTest(void)
{
    std::set<int> set;
    int i = 0;
    while (i < 6)
    {
        set.insert(i);
        i++;
    }
    std::for_each(set.begin(), set.end(), displayInt);
    std::cout << std::endl;
    std::cout << "Looking for 2 in set: " << easyfind(set, 2) << std::endl;
    try
    {
        std::cout << "Looking for -12 in set: " << easyfind(set, -12) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return ;
}

int main(void)
{
    listTest();
    vectorTest();
    setTest();
    return (0);
}