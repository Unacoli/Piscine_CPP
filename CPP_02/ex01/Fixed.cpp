#include "Fixed.hpp"

const int Fixed::_fractionBits = 8;

Fixed::Fixed(void) : _fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(int const _int) : _fixedPoint(roundf(_int * (1 << Fixed::_fractionBits)))
{
    std::cout << "Int constructor called" << std::endl;
    return ;
}

Fixed::Fixed(float const _float) : _fixedPoint(roundf(_float * (1 << Fixed::_fractionBits)))
{
    std::cout << "Float constructor called" << std::endl;
    return ;
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    _fixedPoint = src.getRawBits();
    return ;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed& Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Copy assignement operator called" << std::endl;
    this->_fixedPoint = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPoint);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPoint = raw;
    return ;
}

int Fixed::toInt(void) const
{
    return ((int)_fixedPoint / (int)(1 << Fixed::_fractionBits));
}

float   Fixed::toFloat(void) const
{
    return ((float)_fixedPoint / (float)(1 << Fixed::_fractionBits));
}

std::ostream& operator<<(std::ostream &outputStream, Fixed const &rhs)
{
    outputStream << rhs.toFloat();
    return (outputStream);
}