#include <iostream>
#include "Point.hpp"

int main() {
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	Point inside(2.0f, 2.0f);
	Point outside(12.0f, 12.0f);
	Point onEdge(5.0f, 0.0f);
	Point onVertex(0.0f, 0.0f);

	std::cout << "Triangle vertices: A(0,0), B(10,0), C(0,10)\n" << std::endl;

	std::cout << "Point inside (2, 2): " 
	          << (bsp(a, b, c, inside) ? "TRUE (Inside)" : "FALSE") << std::endl;

	std::cout << "Point outside (12, 12): " 
	          << (bsp(a, b, c, outside) ? "TRUE" : "FALSE (Outside)") << std::endl;

	std::cout << "Point on edge (5, 0): " 
	          << (bsp(a, b, c, onEdge) ? "TRUE" : "FALSE (On edge)") << std::endl;

	std::cout << "Point on vertex (0, 0): " 
	          << (bsp(a, b, c, onVertex) ? "TRUE" : "FALSE (On vertex)") << std::endl;

	return 0;
}
