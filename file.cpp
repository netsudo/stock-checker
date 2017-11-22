#include "file.h"

std::vector<std::string> fileLines(std::string filename) {
	std::vector<std::string> file;
	std::string temp;

	std::ifstream infile(filename);
	while ( !infile.eof() ) {
		std::getline(infile, temp);
		file.push_back(temp);
	}
	infile.close();

	return file;
}

void File::addLine(std::string filename, std::string content) {
	std::ofstream outfile;

	outfile.open(filename, std::ios_base::app);
	outfile << content;

	outfile.close();
}

void File::deleteLine(std::string filename, int lineNumber) {
	file = fileLines(filename);
	file.erase( file.begin() + lineNumber );
	
	std::ofstream out("temp.cache", std::ios::out | std::ios::trunc);

	for ( std::vector<std::string>::const_iterator i = file.begin(); i != file.end(); ++i) {
		if ( *i != "" ) {
			out << *i << std::endl;
		}
	}
	out.close();

	std::remove(filename);
	std::rename("temp.cache", filename);
		
}

void File::writeLines(std::string filename) {
	file = fileLines(filename);
	int j = 1;

	for ( std::vector<std::string>::const_iterator i = file.begin(); i != file.end(); ++i) {
		std::cout << j << ". " << *i << std::endl;

		j++
	}

}
