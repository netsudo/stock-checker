#include "phone.h"

Phone::Phone(const std::string filename = "numbers.cache") : File(filename) {}

bool Phone::validateSelection(unsigned int line) {
	if ( line < fileLines(filename).size() ) {
		return true;
	}

	return false;
}
