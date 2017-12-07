#include "phone.h"

Phone::Phone() : File("urls.cache") {}
const std::string Phone::acceptedCharacters = "0123456789";

bool Phone::validNumber(std::string number) {
	//Checking for 11 digit long number, North America specific
	if ( number.length() != 11 ) {
		return false;
	}

	for ( char & c : number ) {
		if ( !(acceptedCharacters.find(c) != std::string::npos) ) {
			return false;
		}
	}
	return true;
}

bool Phone::validateSelection(unsigned int line) {
	if ( line < fileLines(filename).size() ) {
		return true;
	}

	return false;
}
