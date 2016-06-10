
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


void display(vector<int> vec);
void swap(int &val1, int &val2);
void bubble_sort(vector<int> &vec);

void display(vector<int> vec) 
{
	int ix;
	for(ix = 0; ix < vec.size(); ix++)
		cout << vec[ix] << ' ';
	std::cout<< std::endl;
}

void swap(int &val1, int &val2)
{
	int temp = val1;
	val1 = val2;
	val2 = temp;
}

void bubble_sort(vector<int> &vec, ofstream *ofil=0) 
{
	int ix, jx;
	for(ix = 0; ix < vec.size(); ix++)
		for(jx = ix+1; jx < vec.size(); jx++)
			if(vec[ix] > vec[jx]) {
				(*ofil) << "about to call swap!" << " ix: "
					<< ix << " jx: " << jx << '\t'
					<< "swapping: " << vec[ix] << "with " << vec[jx]  << endl;
				swap(vec[ix], vec[jx]);
			}
}

int main(void)
{
	int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
	std::vector<int> vec (ia, ia+8);
	std::cout << "vector before sort: ";
	display(vec);

	//ofstream ofil("debug.txt");
	ofstream ofil;
	bubble_sort(vec, &ofil);
	std::cout<< "vector after sort : ";
	display(vec);
	return 0;
}
