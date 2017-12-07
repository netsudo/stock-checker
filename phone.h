#ifndef PHONE_H
#define PHONE_H

#include "file.h"
#include <string.h>

class Phone: public File {
	private:
		static const std::string acceptedCharacters;

	public:
		Phone();

		bool validateSelection(unsigned int line);

		bool validNumber(std::string number);
};

#endif
