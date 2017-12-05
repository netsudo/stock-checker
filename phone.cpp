#include "phone.h"

const std::string Phone::filename = "numbers.cache";

bool Phone::validateSelection(unsigned int line) {
	if ( line < fileLines(filename).size() ) {
		return true;
	}

	return false;
}
