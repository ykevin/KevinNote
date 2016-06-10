
#ifndef _MYTIME_H_
#define _MYTIME_H_

class Time {
	public:
		Time();
		Time(int h, int m = 0);
		void AddMin(int m);
		void AddHr(int h);
		void Reset(int m = 0, int h = 0);
		Time operator+(const Time &t) const;
		Time operator-(const Time &t) const;
		Time operator*(double n) const;
		friend Time operator*(double m, const Time &t) { return t*m; }
		friend  std::ostream & operator<<(std::ostream &os, const Time & t);

	private:
		int hours;
		int minutes;
};

#endif //_MYTIME_H_
