#include "URL.h"

const std::string URL::filename = "urls.cache";

bool URL::validateSelection(unsigned int line) {
	if ( line < fileLines(filename).size() ) {
		return true;
	}

	return false;
}
