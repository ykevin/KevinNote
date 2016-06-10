
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

int main(void)
{
	std::ofstream outfile("test.txt", std::ios_base::app);
	std::string usr_name;
	std::vector< std::string > text;

	if(!outfile) {
		std::cerr << "Oops! unable to save session data!" << std::endl;
		return -1;
	}

	std::cout << "please input your name : " << std::endl;
	while(std::cin >> usr_name) 
		outfile << usr_name << std::endl; ;
	

	std::ifstream infile("test.txt");
	if(!infile) {
		std::cerr << "Oops! unable to open sessions data!" << std::endl;
		return -2;
	}

	while(infile >> usr_name) {
		text.push_back(usr_name);
	}	

	int i;
	for(i = 0; i < text.size(); i++)
		std::cout << "name: " << text[i] << std::endl;

	std::cout << "sort" << std::endl;
	sort(text.begin(), text.end());
	for(i = 0; i < text.size(); i++)
		std::cout << "name: " << text[i] << std::endl;


	return 0;
}
