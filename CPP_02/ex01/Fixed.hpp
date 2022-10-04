#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

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
        int getRawBits(void) const;
        void    setRawBits(int const raw);
        int toInt(void) const;
        float toFloat(void) const;
};

std::ostream& operator<<(std::ostream &outputStream, Fixed const &rhs);

#endif