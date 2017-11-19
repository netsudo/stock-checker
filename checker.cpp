#include "parse.h"

int main () {
	Parser parse;
	parse.url = "http://shop.jimmydiresta.com/pushstick/";
	if ( parse.inStock() == true ) {
		std::cout << "available" << std::endl;
	}
	else {
		std::cout << "Out of stock." << std::endl;
	}

	return 0;
}
