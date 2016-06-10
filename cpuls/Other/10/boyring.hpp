
#ifndef HEADER_BOYRING
#define HEADER_BOYRING

struct Boy {
	int code;
	Boy *next;
};

class BoyRing {
	Boy *pBegin, *pivot, *pCurrent;
	public :
		BoyRing(int n);
		void countBy(int m);
		int getNum() const;
		void disengage();
		void printAll() const;
		~BoyRing();
};

#endif //HEADER_BOYRING
