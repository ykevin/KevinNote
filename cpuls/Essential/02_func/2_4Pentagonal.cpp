
#include <iostream>
#include <vector>

inline bool check_vaild(int pos)
{
	return (pos <= 0 || pos > 128) ? false : true ;
}


const std::vector<int> *pentagonal_series(int pos)
{
	int ix;
	static std::vector<int> _elems;
	if(check_vaild(pos) && (_elems.size() < pos))
		for(ix = _elems.size() + 1; ix <= pos; ++ix)
			_elems.push_back((ix*(3*ix - 1))/2);
	return &_elems;
}

bool pentagonal_elem(int pos, int &elem)
{
	if(!check_vaild(pos)) {
		std::cout << "sorry, inavild postion: " << pos << std::endl;
		elem = 0;
		return false;
	}

	const std::vector<int> *pent = pentagonal_series(pos);
	elem = (*pent)[pos-1];
	return true;
}


int main(void)
{
	int elem;
	if(pentagonal_elem(20, elem))
		std::cout << "pentagonal_elem 20 is : " << elem << std::endl;
	return 0;
}
