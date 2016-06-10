
#include <iostream>

bool fibon_elem(int pos, int &elem);

int main(void)
{
	int pos;
	int elem;

	while (true) {
		std::cout << "please enter a postion : ";
		std::cin >> pos;

		if(fibon_elem(pos, elem))
			std::cout << "element # " << pos << " is " << elem << std::endl;
		else 
			std::cout << "sorry count not claulate element # " << pos << std::endl;
	}
	return 0;
}

bool fibon_elem(int pos, int &elem)
{
	if(pos <= 0 || pos >1024) {
		elem = 0;
		return false;
	}
	
	elem = 1;
	int n_2 = 1, n_1 = 1;
	int ix;

	for(ix = 3; ix <= pos; ix++){
		elem = n_2 + n_1;
		n_2 = n_1;
		n_1 = elem;
	}

	return true;
}
