#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>
# include <stdbool.h>

class   Fixed
{
    private:
        int _fixedPoint;
        static const int    _fractionBits;
    public:
        Fixed(void);
        Fixed(int const _int);
        Fixed(float const _float);
        Fixed(Fixed const &src);
        ~Fixed(void);
        Fixed& operator=(Fixed const &rhs);
        bool    operator>(Fixed const &rhs) const;
        bool    operator<(Fixed const &rhs) const;
        bool    operator>=(Fixed const &rhs) const;
        bool    operator<=(Fixed const &rhs) const;
        bool    operator==(Fixed const &rhs) const;
        bool    operator!=(Fixed const &rhs) const;
        Fixed   operator+(Fixed const &rhs) const;
        Fixed   operator-(Fixed const &rhs) const;
        Fixed   operator*(Fixed const &rhs) const;
        Fixed   operator/(Fixed const &rhs) const;
        Fixed&  operator++();
        Fixed   operator++(int);
        Fixed&  operator--();
        Fixed   operator--(int);
        int getRawBits(void) const;
        void    setRawBits(int const raw);
        int toInt(void) const;
        float toFloat(void) const;
        static Fixed    min(Fixed &n1, Fixed &n2);
        static Fixed    min(Fixed const &n1, Fixed const &n2);
        static Fixed    max(Fixed &n1, Fixed &n2);
        static Fixed    max(Fixed const &n1, Fixed const &n2);
};

std::ostream& operator<<(std::ostream &outputStream, Fixed const &rhs);

#endif