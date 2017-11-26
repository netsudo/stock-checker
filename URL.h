#ifndef URL_H
#define URL_H

#include "file.h"

class URL: protected File {
	private:
		const std::string filename;

	public:
		bool validateURL(std::string url);

		bool validateSelection(int line);
};

#endif
