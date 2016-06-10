
#include "point.hpp"
#include "circle_compos.hpp"

Circle::Circle(const Point& p, double r):point(p), radius(r) {}
double Circle::getRadius() const { return radius; }
Point Circle::getPoint() const { return point; }
double Circle::getArea() const { return radius * radius* Point::PI; }
double Circle::getCircum() const { return 2 * radius * Point::PI; }
void Circle::moveTo (double a, double b) { point.moveTo(a, b); }
void Circle::modifyRadius(double r) { radius = r; }
