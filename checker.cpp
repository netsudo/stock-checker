#include <string.h>
#include <stdlib.h>
#include "parse.h"
#include "URL.h"
#include "phone.h"

void help() {
	std::cout << "Product Availability Checker v0.0\n\n"
			  << "Commands:\n"
			  << "-wu -- Displays the tracked URL's\n"
			  << "-wn -- Displays the phone numbers to notify\n"
			  << "-au [URL] -- Add a URL to watch\n"
			  << "-an [NUMBER] -- Add a number to notify\n"
			  << "-du [ENTRY #] -- Stop watching a URL\n"
			  << "-dn [ENTRY #] -- Stop notifying a number\n"
			  << "-eu [ENTRY #] -- Modify a watched URL\n"
			  << "-en [ENTRY #] -- Modify a phone number\n"
			  << std::endl;
}

int main ( int argc, char *argv[] ) {
	Parser parse; URL url; Phone phone;

	if ( argc == 1 ) {
		//This is where the checker will run
	}
	
	else if ( argc == 2 ) {
		if ( strcmp(argv[1], "-wu") == 0 ) {
			url.writeLines();
		}
		else if ( strcmp(argv[1], "-wn" ) == 0 ) {
			phone.writeLines();
		}
		else if ( strcmp(argv[1], "--help") == 0 ||
				  strcmp(argv[1], "-h") == 0 ) {
			help();
		}
		else { std::cout << "Invalid argument." << std::endl; }
	}

	else if ( argc == 3 ) {
		if ( strcmp(argv[1], "-au") == 0 ) {
			std::string str(argv[2]);
			parse.url = argv[2];

			if ( parse.validURL() ) {
				url.addLine( argv[2] );
			}
			else {
				std::cout << "Must enter a valid URL." << std::endl;
			}
		}

		else if ( strcmp(argv[1], "-an") == 0 ) {
			std::string str(argv[2]);

			if ( phone.validNumber(argv[2]) ) {
				phone.addLine( argv[2] );
			}
			else {
				std::cout << "Must enter a valid number." << std::endl;
			}
		}

		else if ( strcmp(argv[1], "-du") == 0 ) {

			unsigned int lineSelection = strtoul( argv[2], NULL, 0);
			if ( url.validateSelection( lineSelection ) ) {
				url.deleteLine( lineSelection );
			}
			else {
				std::cout << "Entry doesn't exist." << std::endl;
			}
		}

		else if ( strcmp(argv[1], "-dn") == 0 ) {

			unsigned int lineSelection = strtoul( argv[2], NULL, 0);
			if ( phone.validateSelection( lineSelection ) ) {
				phone.deleteLine( lineSelection );
			}
			else {
				std::cout << "Entry doesn't exist." << std::endl;
			}
		}

		else { std::cout << "Invalid argument." << std::endl; }
	}

	else if ( argc == 4 ) {
		if ( strcmp(argv[1], "-eu") == 0 ) {

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

		else if ( strcmp(argv[1], "-en") == 0 ) {

			std::string str(argv[3]);
			unsigned int lineSelection = strtoul( argv[2], NULL, 0);
			if ( phone.validateSelection( lineSelection ) && phone.validNumber( argv[3] ) ) {
				phone.editLine( lineSelection, argv[3] );
			}
			else {
				std::cout << "Entry doesn't exist or number is invalid." << std::endl;
			}
		}

		else { std::cout << "Invalid argument." << std::endl; }
	}

	else {
		std::cout << "Invalid arguments. Type --help for full command list." << std::endl;
	}


	return 0;
}
