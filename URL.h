#ifndef URL_H
#define URL_H

#include "file.h"

class URL: public File {
	public:
		URL(const std::string filename);

		bool validateSelection(unsigned int line);
};

#endif
