
#include <iostream>
#include <vector>


inline bool calu_pentagonal(int size, std::vector<int> &ivec)
{
	int ix;
	for(ix = ivec.size() + 1 ; ix <= size; ++ix)
		ivec.push_back((ix*(3*ix -1))/2);
}

bool pentagonal_elem(int num, std::vector<int> &ivec)
{
	if(num > 128 || num < 0)
		return false;
	
	if(ivec.size() < num)
		calu_pentagonal(num, ivec);

	return true;	
}

void display_num(const std::vector<int> &ivec, int pos)
{
	int ix;
	for(ix = 0; ix < pos; ++ix)
		std::cout << "the num : " << ix << " pentagonal_elem is : " << ivec[ix] << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::vector<int> ivec;
	int num;
	while(true) {
		std::cout << "please input num: ";
		std::cin>>num;
		if(pentagonal_elem(num, ivec)){
			std::cout << "this is num :" << num << std::endl;
			display_num(ivec, num);
		} else
			std::cout << "invaild num !" << std::endl;

	}
	return 0;
}
