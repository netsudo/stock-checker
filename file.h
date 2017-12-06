#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

class File {
	protected:
		const std::string filename; 
		std::vector<std::string> fileLines(const std::string filename);

	public:
		File(const std::string filename);

		void addLine(std::string content);

		void deleteLine(int lineNumber);

		void writeLines();

		void editLine(int lineNumber, std::string content);

};

#endif
