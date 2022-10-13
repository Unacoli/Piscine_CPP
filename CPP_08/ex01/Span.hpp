#ifndef SPAN_HPP
# define SPAN_HPP
# include <string>
# include <iostream>
# include <algorithm>
# include <set>
# include <limits.h>

class Span
{
    private:
        unsigned int    _n;
        std::set<int>   _set;
    public:
        Span(void);
        Span(unsigned int n);
        Span(Span const &src);
        virtual ~Span(void);
        Span& operator=(Span const &rhs);
        void    addNumber(int n);
        void    addNumber(int low, int high);
        unsigned int    shortestSpan(void) const;
        unsigned int    longestSpan(void) const;
        class SpanFullException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Span is full\n");
                }
        };
        class NotEnoughElems : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("No enough elements in set\n");
                }
        };
};

#endif