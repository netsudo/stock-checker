#ifndef URL_H
#define URL_H

#include "file.h"

class URL: public File {
	public:
		URL();

		bool validateSelection(unsigned int line);
};

#endif
