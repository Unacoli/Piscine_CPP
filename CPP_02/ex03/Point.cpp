#include "Point.hpp"

Point::Point(Fixed const x, Fixed const y) : x(0), y(0)
{
    return ;
}

Point::Point(float const n1, float const n2) : x(n1), y(n2)
{
    return ;
}

Point::Point(Point const &src)
{
    return ;
}

Point& Point::operator=(Point const &rhs)
{
    return (*this);
}

Point::~Point(void)
{
    return ;
}