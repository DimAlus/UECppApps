#include "main.h"


int main() {
	std::string str = "string";
	std::cout << str <<
		";  len: " << str.length() <<
		";  first: '" << str[0] <<
		"';  last: '" << str[str.length() - 1] << "';";
	return 0;
}