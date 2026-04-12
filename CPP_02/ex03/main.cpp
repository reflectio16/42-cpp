#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    Point inside(5.0f, 5.0f);
    Point outside(20.0f, 20.0f);
    Point onEdge(5.0f, 0.0f);
    Point onVertex(0.0f, 0.0f);

    std::cout << "Triangle: A(0,0) B(10,0) C(5,10)" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Point (5,5) inside? " << (bsp(a, b, c, inside) ? "YES" : "NO") << std::endl;
    std::cout << "Point (20,20) inside? " << (bsp(a, b, c, outside) ? "YES" : "NO") << std::endl;
    std::cout << "Point (5,0) on edge? " << (bsp(a, b, c, onEdge) ? "YES" : "NO") << std::endl;
    std::cout << "Point (0,0) on vertex? " << (bsp(a, b, c, onVertex) ? "YES" : "NO") << std::endl;
    
    return 0;
}