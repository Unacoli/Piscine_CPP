#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "a: " << a << std::endl;
    std::cout << "Increment a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "Increment a: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "Decrement a: " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "Max between a and b: " << Fixed::max( a, b ) << std::endl;
    std::cout << "Min between a and b: " << Fixed::min( a, b ) << std::endl;
    return (0);
}