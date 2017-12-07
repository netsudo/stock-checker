#include "phone.h"

Phone::Phone() : File("urls.cache") {}
const std::string Phone::acceptedCharacters = "0123456789";

bool Phone::validNumber(std::string number) {
	for ( auto i = 0; i < number.length(); i++ ) {
		if ( !(acceptedCharacters.find(number[i]) != std::string::npos) ) {
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
