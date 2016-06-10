
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class even_elem{
	public:
		bool operator()(int elem) {
			return elem % 2 ? false : true;
		}
};

int main(void)
{
	ofstream even_file("even.txt"),
			 odd_file("odd.txt");

	if(!even_file || !odd_file){
		cerr << "unable open file !" << endl;
		return -1;
	}

	vector<int> input;
	istream_iterator<int> in(cin), eos;

	copy(in, eos, back_inserter(input));

	vector<int>::iterator division = partition(input.begin(), input.end(), even_elem());
	
	ostream_iterator<int> even_iter(even_file, "\n"),
						odd_iter(odd_file, " ");
	
	copy(input.begin(), division, even_iter);
	copy(division, input.end(), odd_iter);

	return 0;
}
