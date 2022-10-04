#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;
public:
    Point(void);
    ~Point(void);
    Point(Fixed const x, Fixed const y);
    Point(float const x, float const y);
    Point(Point const &src);
    Point& operator=(Point &rhs);
    void    setX(Fixed fixed);
    void    setY(Fixed fixed);
    Fixed   getX(void) const;
    Fixed   getY(void) const;
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif