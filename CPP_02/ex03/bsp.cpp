#include "Fixed.hpp"
#include "Point.hpp"

Fixed   *get_f1(Point const a, Point const b, Point const c, Point const point)
{
    Fixed   Ax = a.getX();
    Fixed   Ay = a.getY();
    Fixed   Bx = b.getX();
    Fixed   By = b.getY();
    Fixed   Cx = c.getX();
    Fixed   Cy = c.getY();
    Fixed   Pointx = point.getX();
    Fixed   Pointy = point.getY();
    Fixed   num = (Ax * (Cy - Ay)) + (Pointy - Ay) * (Cx - Ax) - Pointx * (Cy - Ay);
    Fixed   denum = (By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay);
    Fixed   fixed = num /denum;
    Fixed   *f1 = new Fixed(fixed);
    return (f1);
}

Fixed   *get_f2(Fixed f1, Point const a, Point const b, Point const c, Point const point)
{
    Fixed   Ay = a.getY();
    Fixed   By = b.getY();
    Fixed   Cy = c.getY();
    Fixed   Pointy = point.getY();
    Fixed   num = Pointy - Ay - f1 * (By - Ay);
    Fixed   denum = Cy - Ay;
    Fixed   *f2 = new Fixed(num / denum);
    return (f2);
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed   *f1 = get_f1(a, b, c, point);
    Fixed   *f2 = get_f2(*f1, a, b, c, point);
    bool    ret = true;

    if (*f1 > 0 && *f2 > 0 && (*f1 + *f2) < 1)
        ret = true;
    else
        ret = false;
    delete (f1);
    delete (f2);
    return (ret);
}