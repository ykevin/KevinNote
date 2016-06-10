#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	ifstream in_file("input_file.txt");
	ofstream out_file("output_file.txt");
	if(!in_file || !out_file){
		cerr << "unable open file !" << endl;
		return -1;
	}

	istream_iterator <string> is(in_file);
	istream_iterator <string> eof;

	vector<string> text;
	copy(is, eof, back_inserter(text));

	sort(text.begin(), text.end());

	ostream_iterator <string> os(out_file, " ");
	copy(text.begin(), text.end(), os);
	return 0;
}
