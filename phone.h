#ifndef PHONE_H
#define PHONE_H

#include "file.h"

class Phone: public File {
	public:
		Phone();

		bool validateSelection(unsigned int line);
};

#endif
