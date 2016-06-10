
#include <iostream>

using namespace std;

class Bed {
	protected :
		int weight;
	public :
		Bed() : weight() {}
		void sleep () const { cout << "SleePing ...\n"; }
		void setWeight(int i) { weight = i; }
};

class Sofa {
	protected :
		int weight;
	public :
		Sofa(): weight(0) {}
		void watchTv() const { cout << "Watching Tv.\n"; }
		void setWeight( int i) { weight = i; }
};

class SleeperSofa : public Bed, public Sofa {
	public :
		SleeperSofa() {}
		void foldOut() const { cout << "Fold out the sofa.\n"; }
};

int main() {
	SleeperSofa ss;
	ss.watchTv();
	ss.foldOut();
	ss.sleep();
	ss.Sofa::setWeight(20);
}
