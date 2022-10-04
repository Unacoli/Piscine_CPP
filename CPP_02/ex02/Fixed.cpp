#include "Fixed.hpp"

const int Fixed::_fractionBits = 8;

Fixed::Fixed(void) : _fixedPoint(0)
{
    return ;
}

Fixed::Fixed(int const _int) : _fixedPoint(roundf(_int * (1 << Fixed::_fractionBits)))
{
    return ;
}

Fixed::Fixed(float const _float) : _fixedPoint(roundf(_float * (1 << Fixed::_fractionBits)))
{
    return ;
}

Fixed::Fixed(Fixed const &src)
{
    _fixedPoint = src.getRawBits();
    return ;
}

Fixed::~Fixed(void)
{
    return ;
}

Fixed& Fixed::operator=(Fixed const &rhs)
{
    this->_fixedPoint = rhs.getRawBits();
    return (*this);
}

bool    Fixed::operator>(Fixed const &rhs) const
{
    return (this->_fixedPoint > rhs._fixedPoint);
}

bool    Fixed::operator<(Fixed const &rhs) const
{
    return (this->_fixedPoint < rhs._fixedPoint);
}

bool    Fixed::operator>=(Fixed const &rhs) const
{
    return (this->_fixedPoint >= rhs._fixedPoint);
}

bool    Fixed::operator<=(Fixed const &rhs) const
{
    return (this->_fixedPoint <= rhs._fixedPoint);
}

bool    Fixed::operator==(Fixed const &rhs) const
{
    return (this->_fixedPoint == rhs._fixedPoint);
}

bool    Fixed::operator!=(Fixed const &rhs) const
{
    return (this->_fixedPoint != rhs._fixedPoint);
}

Fixed   Fixed::operator+(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed   Fixed::operator-(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed   Fixed::operator*(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed   Fixed::operator/(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator++(void)
{
    (this->_fixedPoint) += 1;
    return (*this);
}

Fixed   Fixed::operator++(int n)
{
    Fixed   tmp(*this);

    if (n >= 0)
    {
        while (n-- >= 0)
            ++(*this);
    }
    else
    {
        while (n-- >= 0)
            --(*this);
    }
    return (tmp);
}

Fixed& Fixed::operator--(void)
{
    (this->_fixedPoint) -= 1;
    return (*this);
}

Fixed   Fixed::operator--(int n)
{
    Fixed   tmp(*this);

    if (n >= 0)
    {
        while (n-- >= 0)
            --(*this);
    }
    else
    {
        while (n-- >= 0)
            ++(*this);
    }
    return (tmp);
}

int Fixed::getRawBits(void) const
{
    return (this->_fixedPoint);
}

void    Fixed::setRawBits(int const raw)
{
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

Fixed   Fixed::min(Fixed &n1, Fixed &n2)
{
    return (n1 < n2 ? n1 : n2);
}

Fixed   Fixed::min(Fixed const &n1, Fixed const &n2)
{
    return (n1 < n2 ? n1 : n2);
}

Fixed   Fixed::max(Fixed &n1, Fixed &n2)
{
    return (n1 > n2 ? n1 : n2);
}

Fixed   Fixed::max(Fixed const &n1, Fixed const &n2)
{
    return (n1 > n2 ? n1 : n2);
}

std::ostream& operator<<(std::ostream &outputStream, Fixed const &rhs)
{
    outputStream << rhs.toFloat();
    return (outputStream);
}