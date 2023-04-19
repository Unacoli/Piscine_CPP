#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
    return ;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
    *this = src;
    return ;
}

PmergeMe::~PmergeMe(void)
{
    return ;
}

PmergeMe& PmergeMe::operator=(PmergeMe const &rhs)
{
    if (this != &rhs)
    {
        this->_vec = rhs._vec;
        this->_deq = rhs._deq;
        this->_size = rhs._size;
    }
    return (*this);
}

void    PmergeMe::mergeMe(char **args, int len)
{
    int i = 1, tmp, j;
    this->_size = len;
    float tmp_vec, tmp_deq;

    std::cout << "Before: ";
    while (args[i])
    {
        j = 0;
        if (args[i][0] == '\0')
        {
            std::cout << "Error" << std::endl;
            return ;
        }
        while (args[i][j])
        {
            if (!isdigit(args[i][j]))
            {
                std::cout << "Error" << std::endl;
                return ;
            }
            j++;
        }
        std::stringstream ss(args[i]);
        ss >> tmp;
        if (tmp < 0)
        {
            std::cout << "Error" << std::endl;
            return ;
        }
        this->_vec.push_back(tmp);
        this->_deq.push_back(tmp);
        i++;
    }
    clock_t time = clock();
    merge_insert_sort(this->_vec);
    tmp_vec = (float)(clock() - time);

    time = clock();
    merge_insert_sort(this->_deq);
    tmp_deq = (float)(clock() - time);
    
    i = 1;
    while (args[i])
    {
        std::cout << args[i] << " ";
        ++i;
    }
    std::cout << tmp << std::endl;
    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); ++i)
    {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector " << tmp_vec / CLOCKS_PER_SEC << " secondes" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque " << tmp_deq / CLOCKS_PER_SEC << " secondes" << std::endl;    
}