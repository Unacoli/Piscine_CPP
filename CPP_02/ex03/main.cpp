#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    Point   P1;
    Point   P2(Fixed(93.12f), Fixed(110.42f));
    Point   P3(Fixed(2.9f), Fixed(0.5f));

    Point   TriangleA(0, 0);
    Point   TriangleB(6.42, 4.32);
    Point   TriangleC(1.06, -5.30);

    std::cout << "P1 on vertex, return BSP value : " << bsp(TriangleA, TriangleB, TriangleC, P1) << std::endl;
    std::cout << "P2 outside, return BSP value : " << bsp(TriangleA, TriangleB, TriangleC, P2) << std::endl;
    std::cout << "P3 inside, return BSP value : " << bsp(TriangleA, TriangleB, TriangleC, P3) << std::endl;
    return (0);
}