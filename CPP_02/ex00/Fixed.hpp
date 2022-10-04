#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class   Fixed
{
    private:
        int _fixedPoint;
        static const int    _fractionBits;
    public:
        Fixed(void);
        Fixed(Fixed const &src);
        ~Fixed(void);
        Fixed& operator=(Fixed const &rhs);
        int getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif