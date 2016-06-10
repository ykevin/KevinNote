#include <iostream>
#include <vector>

int main(void)
{
	const int size = 20;
	int array[size];
	std::vector<int> vec;
	
	int x, y;
	int count = 0;

	std::cout << "Please input number: " << std::endl;
	while((std::cin >> x >> y) && (count < 20) ) {
		array[count] = x;
		vec.push_back(y);
		count++;
	}

	int sum_vec = 0, sum_arr = 0, ix;
	for(ix = 0; ix < vec.size(); ix++)
	   sum_vec += vec[ix];

	for(ix = 0; ix < count; ix++)
	   sum_arr += array[ix];

	
	int average_arr = sum_arr / count;
	int average_vec = sum_vec / count;

	std::cout << "sum array is: " << sum_arr << "   sum vector is: " << sum_vec
		      << "  average array is: " << average_arr << "  average vector is : "<< average_vec << std::endl;

	return 0;
}
