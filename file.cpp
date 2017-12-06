#include "file.h"

File::File(const std::string file) : filename(file) {}

std::vector<std::string> File::fileLines(std::string filename) {
	std::vector<std::string> file;
	std::string temp;

	std::ifstream infile(filename.c_str());
	while ( std::getline(infile, temp) ) {
		file.push_back(temp);
	}
	infile.close();

	return file;
}

void File::addLine(std::string content) {
	std::ofstream outfile;

	outfile.open(filename, std::ios_base::app);
	outfile << "\n" << content;

	outfile.close();
}

void File::deleteLine(int lineNumber) {
	std::vector<std::string> file = fileLines(filename);
	file.erase( file.begin() + lineNumber );
	
	std::ofstream out("temp.cache", std::ios::out | std::ios::trunc);

	for ( std::vector<std::string>::const_iterator i = file.begin(); i != file.end(); ++i) {
		if ( *i != "" ) {
			out << *i << std::endl;
		}
	}
	out.close();

	std::remove(filename.c_str());
	std::rename("temp.cache", filename.c_str());
		
}

void File::writeLines() {
	std::vector<std::string> file = fileLines(filename);
	int j = 1;

	for ( std::vector<std::string>::const_iterator i = file.begin(); i != file.end(); ++i) {
		std::cout << j << ". " << *i << std::endl;

		j++;
	}

}

void File::editLine(int lineNumber, std::string content) {
	std::vector<std::string> file = fileLines(filename);
	
	std::ofstream out("temp.cache", std::ios::out | std::ios::trunc);

	file.at(lineNumber) = content;
	for ( std::vector<std::string>::const_iterator i = file.begin(); i != file.end(); ++i) {
		if ( *i != "" ) {
			out << *i << std::endl;
		}
	}
	out.close();

	std::remove(filename.c_str());
	std::rename("temp.cache", filename.c_str());
		
}
