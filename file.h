#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

class File {
	protected:
		std::vector<std::string> fileLines(std::string filename);

	public:
		void addLine(std::string filename, std::string content);

		void deleteLine(std::string filename, int lineNumber);

		void writeLines(std::string filename);

		void editLine(std::string filename, std::string content,int lineNumber);

};

#endif
