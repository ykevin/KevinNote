#include <iostream>

int main(void)
{
	std::string name;
	
	std ::cout << "Please input name or 'quit': " << std::endl;
	while (std::cin >> name) {
		if(name == "quit")
			break;

		if(name.size() <= 2 ) {
			std::cout << "invaild name, please input again!" <<std::endl;
			continue;
		} else
			std::cout << "name is : " << name <<std::endl;
	}

	std::cout << "input name quit !" << std::endl;
}
