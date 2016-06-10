
#ifndef HEADER_CIRCLE_COMPOS
#define HEADER_CIRCLE_COMPOS

#include "point.hpp"

class Circle {
	Point point;
	double radius;
	public :
		Circle(const Point& p=Point(), double r=0);
		double getRadius() const;
		Point getPoint() const;
		double getArea() const;
		double getCircum() const;
		void moveTo(double a, double b);
		void modifyRadius(double r);
};

#endif //HEADER_CIRCLE_COMPOS
