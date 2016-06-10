
#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>

using namespace std;

template <typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter(InputIterator first, InputIterator last, OutputIterator at, const ElemType &val, Comp pred)
{
	while((first = find_if(first, last, bind2nd(pred, val))) != last) {
		cout << "found value: " << *first << endl;

		*at++ = *first++;
	}
	return at;
}

int main(void) 
{
	const int elem_size = 8;
	int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
	vector<int> ivec(ia, ia + elem_size);

	int ia2[elem_size];
	vector<int> ivec2(elem_size);

	cout << "filtering integer array for value less than 8" << endl;
	filter(ia, ia + elem_size, ia2, elem_size, less<int>());

	cout << "filtering integer array for value greater than 8" << endl;
	filter(ivec.begin(), ivec.end(), ivec2.begin(), 12, greater<int>());

	return 0;
}
