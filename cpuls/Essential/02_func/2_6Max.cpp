
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename elemType>
inline elemType max(elemType t1, elemType t2)
{
	return t1 > t2 ? t1 : t2;
}

template <typename vecType>
inline vecType max(const std::vector<vecType> &vec)
{
	return *max_element(vec.begin(), vec.end());
}

template <typename arrType>
inline arrType max(const arrType *parray, int size)
{
	return *max_element(parray, parray + size);
}

int main(void)
{
	std::string sarray[] = {"we", "were", "her", "my", "of", "tan"};
	std::vector<std::string> svec(sarray, sarray + 6);

	int iarray[] = {10, 20, 15, 11, 30, 40};
	std::vector<int> ivec(iarray, iarray + 6);

	float farray[] = {1.23, 2.56, 9.99, 5.2, 12.5, 4.56};
	std::vector<float> fvec(farray, farray + 6);

	int imax = max(max(ivec), max(iarray, 6));
//	float fmax = max(max(fvec), max(farray, 6));
	//std::string smax = max(max(svec), max(sarray, 6));

	std::cout << "imax ivec is : " << imax << std::endl;
//	std::cout << "fmax fvec is : " << fmax << std::endl;
	//std::cout << "smax svec is : " << smax << std::endl;
	return 0;
}
