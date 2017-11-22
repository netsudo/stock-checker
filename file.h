#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <vector>
#include <string>

class File {
	private:
		std::vector<std::string> fileLines();

		void addLine(std::string filename, std::string content);

		void deleteLine(std::string filename, int lineNumber);

		void writeLines(std::string filename);

		void editLine(std::string filename, std::string content,int lineNumber);

};

#endif
