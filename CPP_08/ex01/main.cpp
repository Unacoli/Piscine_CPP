#include "Span.hpp"

int main(void)
{
    {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    }
    {
        Span sp = Span(2);
        try
        {
            sp.shortestSpan();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        sp.addNumber(0);
        try
        {
            sp.longestSpan();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            sp.addNumber(1);
            sp.addNumber(1);
            sp.addNumber(1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        Span sp = Span(10000);
        sp.addNumber(-5000, 5000);
        std::cout << "shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "longest: " << sp.longestSpan() << std::endl;
    }
    return (0);
}