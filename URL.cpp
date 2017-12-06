#include "URL.h"

URL::URL(const std::string filename = "urls.cache") : File(filename) {}

bool URL::validateSelection(unsigned int line) {
	if ( line < fileLines(filename).size() ) {
		return true;
	}

	return false;
}
