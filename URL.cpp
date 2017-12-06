#include "URL.h"

URL::URL() : File("urls.cache") {}

bool URL::validateSelection(unsigned int line) {
	if ( line < fileLines(filename).size() ) {
		return true;
	}

	return false;
}
