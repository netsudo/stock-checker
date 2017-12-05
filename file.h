#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

class File {
	protected:
		std::vector<std::string> fileLines(const std::string filename);

	public:
		void addLine(const std::string filename, std::string content);

		void deleteLine(const std::string filename, int lineNumber);

		void writeLines(const std::string filename);

		void editLine(const std::string filename, std::string content, int lineNumber);

};

#endif
