#include "file.h"

void File::addLine(std::string filename, std::string content) {
	std::ofstream outfile;

	outfile.open(filename, std::ios_base::app);
	outfile << content;

	outfile.close();
}

void File::deleteLine(std::string filename, int lineNumber) {
	
}
