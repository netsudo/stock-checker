#include <string.h>
#include <stdlib.h>
#include "parse.h"
#include "URL.h"
#include "phone.h"

int main ( int argc, char *argv[] ) {
	Parser parse; URL url;

	if ( strcmp(argv[1], "-a") == 0 ) {

		std::string str(argv[2]);
		parse.url = argv[2];

		if ( parse.validURL() ) {
			url.addLine( argv[2] );
		}
		else {
			std::cout << "Must enter a valid URL." << std::endl;
		}
	}

	else if ( strcmp(argv[1], "-d") == 0 ) {

		unsigned int lineSelection = strtoul( argv[2], NULL, 0);
		if ( url.validateSelection( lineSelection ) ) {
			url.deleteLine( lineSelection );
		}
		else {
			std::cout << "Entry doesn't exist." << std::endl;
		}
	}

	else if ( strcmp(argv[1], "-w") == 0 ) {
		url.writeLines();
	}

	else if ( strcmp(argv[1], "-e") == 0 ) {

		std::string str(argv[3]);
		parse.url = argv[3];

		unsigned int lineSelection = strtoul( argv[2], NULL, 0);
		if ( url.validateSelection( lineSelection ) && parse.validURL() ) {
			url.editLine( lineSelection, argv[3] );
		}
		else {
			std::cout << "Entry doesn't exist or URL is invalid." << std::endl;
		}
	}

	else {
		std::cout << "invalid" << std::endl;
	}


	return 0;
}
