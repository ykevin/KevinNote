
#include <iostream>
#include <vector>
#include <cstdlib>

int main(void)
{
	const int seq_cnt = 6;
	std::vector<int> *seq_addr[seq_cnt] = {
		&fibonacci, &lucas, &pell,
		&triangular, &square, &pentagonal
	};

	//call on seq_addr
	/*
	vector<int> *current_vec = 0;
	for(int i = 0; i < seq_cnt, i++) {
		current_vec = seq_addr[i];
	}
	*/

	srand(seq_cnt);
	const int seq_index = rand() % seq_cnt;
	current_vec = seq_addr[seq_index];
	return 0;
}
