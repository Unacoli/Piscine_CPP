#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <iostream>

class   NotFoundException : public std::exception
{
    const char *what() const throw()
    {
        return ("Element not found");
    }
};

template<typename T>
int easyfind(T &t, int i)
{
    typename T::const_iterator it = std::find(t.begin(), t.end(), i);
    if (it == t.end())
        throw (NotFoundException());
    return (*it);
}

#endif