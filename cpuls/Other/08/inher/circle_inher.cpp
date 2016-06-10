
#include "point.hpp"
#include "circle_inher.hpp"

Circle::Circle(const Point& p, double r):Point(p), radius(r) {}
double Circle::getRadius() const { return radius; }
Point Circle::getPoint() const { return *static_cast<const Point*>(this); }
double Circle::getArea() const { return radius * radius* Point::PI; }
double Circle::getCircum() const { return 2 * radius * Point::PI; }
void Circle::moveTo (double a, double b) { x = a, y = b; }
void Circle::modifyRadius(double r) { radius = r; }
