
#include <iostream>
#include <vector>


template <typename elemType>
void display_message(const std::string &msg, const std::vector<elemType> &vec)
{
	int ix;
	std::cout << msg;
	for(ix = 0; ix < vec.size(); ix++){
		elemType t = vec[ix];
		std::cout << t << ' ';
	}
}

bool is_size_ok(int size)
{
	const int max_size = 1024;
	std::vector<int> ivec;
	std::string msg;
   	msg = "invalid size! ";	
	if(size <=0 || size > max_size) {
		ivec.push_back(size);
		display_message(msg, ivec);
		return false;
	}
	return true;
}

const std::vector<int> *lucas_seq(int size)
{

}	

const std::vector<int> *pell_seq(int size)
{

}	
const std::vector<int> *triang_seq(int size)
{

}	

const std::vector<int> *square_seq(int size) 
{

}

const std::vector<int> *pen_seq(int size)
{

}	

const std::vector<int> *fibon_seq(int size) 
{
	const int max_size = 1024;
	static std::vector<int> elems;
	int ix;

	if(!is_size_ok(size))
		return 0;
	for(ix = elems.size(); ix < size; ++ix){
		if(ix == 0 || ix == 1)
			elems.push_back(1);
		else
			elems.push_back(elems[ix-1] + elems[ix-2]);
	}

	return &elems;
}

inline bool fibon_elem(int pos, int &elem, const std::vector<int>* (*seq_ptr)(int))
{
	const std::vector<int> *pseq = seq_ptr(pos);

	if(!pseq){
		elem = 0;
		return false;
	}

	elem = (*pseq)[pos-1];

	return true;
}

const std::vector<int>* (*seq_array[])(int) = {
	fibon_seq, lucas_seq, pell_seq,
	triang_seq, square_seq, pen_seq
};

enum ns_type {
	ns_fibon, ns_lucas, ns_pell,
	ns_triang, ns_square, ns_pent
};

int main(void)
{
	int pos;
	int elem;

	while (true) {
		std::cout << "please enter a postion : ";
		std::cin >> pos;

		if(fibon_elem(pos, elem, seq_array[ns_fibon]))
			std::cout << "element # " << pos << " is " << elem << std::endl;
		else 
			std::cout << "sorry count not claulate element # " << pos << std::endl;
	}
	return 0;
}

