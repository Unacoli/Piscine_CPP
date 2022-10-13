#ifndef ITER_HPP
# define ITER_HPP
# include <cstdlib>
# include <iostream>

template<typename T>
void    iter(T* arr, size_t size, void(&func)(const T& elem))
{
    size_t i = 0;
    while (i < size)
    {
        func(arr[i]);
        i++;
    }
}

template<typename T>
void    print(T const &t)
{
    std::cout << t << " ";
}

template<typename T>
void    printTest(T t, int len, std::string type)
{
    std::cout << type << std::endl;
    iter(t, len, print);
    std::cout << std::endl;
}

#endif