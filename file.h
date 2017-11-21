#ifndef FILE_H
#define FILE_H

#include <fstream>

class File {
	private:
		std::string filename;
		int lineNumber;

		void addLine();

		void deleteLine();

		void writeLines();

		void editLine();
};

#endif
