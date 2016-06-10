
#include "circle_compos.hpp"
#include <iostream>

using namespace std;

int main() {
	Point a(2.3, 5.6);
	Circle c(a, 7);
	c.moveTo(1, 2);
	c.modifyRadius(3);
	cout << "the radius is " << c.getRadius() << endl;
	cout << "the point is " << c.getPoint() << endl;
	cout << "the area is " << c.getArea() << endl;
	cout << "the circumference is " << c.getCircum() << endl;
}
