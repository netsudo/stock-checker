#include <string.h>
#include <stdlib.h>
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

	else if ( strcmp(argv[1], "-d") == 0 ) {

		unsigned int lineSelection = strtoul( argv[2], NULL, 0);
		if ( url.validateSelection( lineSelection ) ) {
			url.deleteLine(url.filename, lineSelection);
		}
		else {
			std::cout << "Entry doesn't exist." << std::endl;
		}
	}

	else {
		std::cout << "invalid" << std::endl;
	}


	return 0;
}
