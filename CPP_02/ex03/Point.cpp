#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
    return ;
}

Point::~Point(void)
{
    return ;
}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y)
{
    return ;
}

Point::Point(float const x, float const y) : x(x), y(y)
{
    return ;
}

Point::Point(Point const &src) : x(src.getX()), y(src.getY())
{
    return ;
}

Point& Point::operator=(Point &rhs)
{
    return (rhs);
}

Fixed   Point::getX(void) const
{
    return (this->x);
}

Fixed   Point::getY(void) const
{
    return (this->y);
}