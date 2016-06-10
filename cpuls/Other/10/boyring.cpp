
#include <iostream>
#include "boyring.hpp"

using namespace std;

BoyRing::BoyRing(int n) {
	if(n < 2) throw exception();
	pBegin = new Boy[n];
	for(int i=1; i <= n; i++) {
		pBegin[i-1].next = &pBegin[i%n];
		pBegin[i-1].code = i;
	}

	pivot = pCurrent = &pBegin[n - 1];
}

void BoyRing::countBy(int m) {
	for(int i=0; i<=m; ++i) {
		pivot = pCurrent;
		pCurrent = pCurrent->next;
	}
}

int BoyRing::getNum() const {
	return pCurrent->code;
}

void BoyRing::disengage() {
	pivot ->next = pCurrent->next;
	pCurrent = pivot;
}

void BoyRing::printAll() const {
	int numinLine = 0;
	Boy *p = pCurrent;
	do {
		cout << " " << p->code;
		if ( !(++numinLine % 10)) cout << endl;
		p = p->next;
	}while (p != pCurrent);
	cout << endl;
}

BoyRing::~BoyRing() {
	delete[] pBegin;
}
