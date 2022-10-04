#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include <cmath>
# include "Fixed.hpp"
# include <stdbool.h>

class Point
{
private:
    Fixed const x;
    Fixed const y;
public:
    Point(Fixed const x, Fixed const y);
    Point(float const n1, float const n2);
    Point(Point const &src);
    Point& operator=(Point const &rhs);
    ~Point(void);
};

#endif