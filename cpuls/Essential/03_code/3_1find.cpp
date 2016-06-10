
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;


template <typename IteratorType, typename elemType>
IteratorType find(IteratorType first, IteratorType last, const elemType &value) 
{
	for(; first != last; ++first)
		if(value == *first)
			return first;
	return last;
}

int main(void)
{
	const int size = 8;
	int ia[size] = {1, 1, 2, 3, 4, 8, 12,  19};
	vector<int> ivec(ia, ia + 8);
	list<int> ilist (ia, ia +8);

	vector<int>::iterator it;
	it = find(ivec.begin(), ivec.end(), 12);
	if(it != ivec.end())
		cout << "find num !" << endl;
	else
		cout << "no find !" << endl;

	list<int>::iterator iter;
	iter = find(ilist.begin(), ilist.end(), 11);
	if(iter != ilist.end())
		cout << "find num !" << endl;
	else
		cout << "no find !" << endl;
	return 0;
}
