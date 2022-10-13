#include "whatever.hpp"

int main(void)
{
    int a = 2;
    int b = 434;
    std::string c = "owo";
    std::string d = "oooowoooo";
    float   f = 0.0f;
    float   e = -36.12f;
    char    g = 'g';
    char    h = 'h';
    double  i = 2.1;
    double  j = 4.2;

    std::cout << "a: " << a << "| b: " << b << std::endl;
    ::swap(a, b);
    std::cout << "a: " << a << "| b: " << b << std::endl;
    std::cout << "min(a, b): " << ::min(a, b) << std::endl;
    std::cout << "max(a, b): " << ::max(a, b) << std::endl;
    std::cout << std::endl;

    std::cout << "c: " << c << "| d: " << d << std::endl;
    ::swap(c, d);
    std::cout << "c: " << c << "| d: " << d << std::endl;
    std::cout << "min(c, d): " << ::min(c, d) << std::endl;
    std::cout << "max(c, d): " << ::max(c, d) << std::endl;
    std::cout << std::endl;

    std::cout << "f: " << f << "| e: " << e << std::endl;
    ::swap(e, f);
    std::cout << "f: " << f << "| e: " << e << std::endl;
    std::cout << "min(f, e): " << ::min(f, e) << std::endl;
    std::cout << "max(f, e): " << ::max(f, e) << std::endl;
    std::cout << std::endl;

    std::cout << "g: " << g << "| h: " << h << std::endl;
    ::swap(g, h);
    std::cout << "g: " << g << "| h: " << h << std::endl;
    std::cout << "min(g, h): " << ::min(g, h) << std::endl;
    std::cout << "max(g, h): " << ::max(g, h) << std::endl;
    std::cout << std::endl;

    std::cout << "i: " << i << "| j: " << j << std::endl;
    ::swap(i, j);
    std::cout << "i: " << i << "| j: " << j << std::endl;
    std::cout << "min(i, j): " << ::min(i, j) << std::endl;
    std::cout << "max(i, j): " << ::max(i, j) << std::endl;
    std::cout << std::endl;
    return (0);
}