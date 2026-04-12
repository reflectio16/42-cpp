#include "Point.hpp"

Fixed sign(Point const& p1, Point const& p2, Point const& p3) {

    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) 
        - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {

    Fixed d1 = sign(a, b, point);
    Fixed d2 = sign(b, c, point);
    Fixed d3 = sign(c, a, point);

    if (d1 == 0 || d2 == 0 || d3 == 0)
        return false;
    
    bool allNegative = (d1 < 0) && (d2 < 0) && (d3 < 0);
    bool allPositive = (d1 > 0) && (d2 > 0) && (d3 > 0);

    return allNegative || allPositive;
}