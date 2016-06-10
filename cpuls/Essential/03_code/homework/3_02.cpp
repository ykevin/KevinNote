
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class LessThan {
	public:
	bool operator() (const string &s1, const string &s2) {
		return s1.size() < s2.size();
	}
};

template <typename elemType>
void dispaly_vector(const vector<elemType> &vec, ostream &os=cout, int len=8)
{
	typename vector<elemType>::const_iterator 
					iter = vec.begin(), 
					end_it = vec.end();
	int elem_cnt = 1;
	while(iter != end_it) {
		os << *iter++ << (!(elem_cnt++ % len) ? '\n' : ' ');
	}
	os << endl;
}

int main(void)
{
	ifstream in_file("input.txt");
	ofstream out_file("output.txt");

	if(!in_file || !out_file) {
		cerr << "unable open file!" << endl;
		return -1;
	}
	
	vector<string> text;
	string word;
	while(in_file >> word) {
		text.push_back(word);
	}

	sort(text.begin(), text.end(), LessThan());
	dispaly_vector(text, out_file);


	return 0;
}
