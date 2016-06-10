
#include "point.hpp"
#include <cmath>

using namespace std;

double Point::PI = 3.1415926;

Point::Point(double a, double b):x(a), y(b){}
double Point::xOffset() const { return x; }
double Point::yOffset() const { return y; }
double Point::angle() const { return (180/PI)*atan2(y, x); }
void Point::moveTo(double a, double b) {x = a, y = b;}
Point Point::operator+(const Point& d) const { return Point(x + d.x, y + d.y); }
Point& Point::operator+=(const Point& d) {
	x += d.x; y += d.y;
	return *this;
}
