#include "Span.hpp"

Span::Span(void) : _n(0)
{
    std::cout << "Span default constructor called" << std::endl;
    return ;
}

Span::Span(unsigned int n) : _n(n)
{
    std::cout << "Spam " << n << " constructor called" << std::endl;
    return ;
}

Span::Span(Span const &src)
{
    std::cout << "Span copy constructor called" << std::endl;
    _n = src._n;
    _set = src._set;
    return ;
}

Span::~Span(void)
{
    std::cout << "Span destructor called" << std::endl;
    return ;
}

Span& Span::operator=(Span const &rhs)
{
    if (this != &rhs)
    {
        this->_n = rhs._n;
        this->_set = rhs._set;
    }
    return (*this);
}

void    Span::addNumber(int n)
{
    if (_set.size() < _n)
        _set.insert(n);
    else
        throw (SpanFullException());
    return ;
}

void    Span::addNumber(int low, int high)
{
    int   i = low;
    while (i < high)
    {
        addNumber(i);
        i++;
    }
    return ;
}

unsigned int    Span::shortestSpan(void) const
{
    if (_set.size() <= 1)
        throw (NotEnoughElems());
    std::set<int>::iterator it = _set.begin();
    std::set<int>::iterator next = ++_set.begin();
    unsigned int min = UINT_MAX;
    size_t i = 0;
    while (i < _set.size() - 1)
    {
        unsigned int tmp = *next - *it;
        if (tmp < min)
            min = tmp;
        it++;
        next++;
        i++;
    }
    return (min);
}

unsigned int    Span::longestSpan(void) const
{
    if (_set.size() <= 1)
        throw (NotEnoughElems());
    std::set<int>::iterator min = std::min_element(_set.begin(), _set.end());
    std::set<int>::iterator max = std::max_element(_set.begin(), _set.end());
    return (*max - *min);
}