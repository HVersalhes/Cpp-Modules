#include "Point.hpp"

static Fixed crossProduct(Point const a, Point const b, Point const p) {
	return (p.getX() - b.getX()) * (a.getY() - b.getY()) - (a.getX() - b.getX()) * (p.getY() - b.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed d1 = crossProduct(a, b, point);
	Fixed d2 = crossProduct(b, c, point);
	Fixed d3 = crossProduct(c, a, point);

	bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	// If point is on an edge or vertex, at least one crossProduct is 0
	if (d1 == 0 || d2 == 0 || d3 == 0)
		return false;

	return !(hasNeg && hasPos);
}
