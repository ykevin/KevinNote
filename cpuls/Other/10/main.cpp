
#include "jose.hpp"
#include <iostream>


using namespace std;

int main () {
	cout << "please input BoyNum/interNum/startPos:\n";
	int n, m, s;
	cin >>n>>m>>s;
	Jose(n,m).getWinner();
	Jose(n,m,s).getWinner();
}
