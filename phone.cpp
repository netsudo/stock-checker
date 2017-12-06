#include "phone.h"

Phone::Phone() : File("urls.cache") {}

bool Phone::validateSelection(unsigned int line) {
	if ( line < fileLines(filename).size() ) {
		return true;
	}

	return false;
}
