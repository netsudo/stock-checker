#include <string.h>
#include "parse.h"
#include "URL.h"

int main ( int argc, char *argv[] ) {
	Parser parse; URL url;

	if ( strcmp(argv[1], "-a") == 0 ) {
		std::string str(argv[2]);
		parse.url = argv[2];

		if ( parse.validURL() ) {
			url.addLine( url.filename, argv[2] );
		}
		else {
			std::cout << "Must enter a valid URL." << std::endl;
		}
	}

	else {
		std::cout << "invalid" << std::endl;
	}


	return 0;
}
