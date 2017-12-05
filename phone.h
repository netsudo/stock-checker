#ifndef PHONE_H
#define PHONE_H

#include "file.h"

class Phone: public File {
	public:
		static const std::string filename;

		bool validateSelection(unsigned int line);
};

#endif
