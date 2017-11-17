#include "parse.h"

int main () {
	Parser parse;
	std::cout << parse.inStock() << std::endl;
	if ( parse.inStock() == true ) {
		std::cout << "available" << std::endl;
	}

	return 0;
}
