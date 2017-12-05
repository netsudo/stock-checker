#ifndef URL_H
#define URL_H

#include "file.h"

class URL: public File {
	public:
		static const std::string filename;

		bool validateSelection(int line);
};

#endif
