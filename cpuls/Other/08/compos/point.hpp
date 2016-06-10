
#ifndef HEADER_POINT
#define HEADER_POINT

#include <iostream>

using namespace std;

class Point {
	protected:
		double x, y;
	public :
		static double PI;
	public:
		Point(double a=0, double b=0);
		double xOffset() const;
		double yOffset() const;
		double angle() const;
		double radius() const;
		Point operator+(const Point& d)const;
		Point& operator+=(const Point& d);
		void moveTo(double a, double b);
		friend inline ostream& operator << (ostream& o, const Point& d){
			return o<<'(' << d.x <<',' << d.y << ')' << endl;
		}
};

#endif //HEADER_POINT
