#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
	if (argc != 4) {
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cerr << "Error: string to replace (s1) cannot be empty." << std::endl;
		return 1;
	}

	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open()) {
		std::cerr << "Error: could not open file '" << filename << "' for reading." << std::endl;
		return 1;
	}

	std::string outFilename = filename + ".replace";
	std::ofstream outFile(outFilename.c_str());
	if (!outFile.is_open()) {
		std::cerr << "Error: could not create output file '" << outFilename << "'." << std::endl;
		inFile.close();
		return 1;
	}

	std::string line;
	while (std::getline(inFile, line)) {
		std::string result;
		size_t pos = 0;
		size_t found;
		while ((found = line.find(s1, pos)) != std::string::npos) {
			result.append(line, pos, found - pos);
			result.append(s2);
			pos = found + s1.length();
		}
		result.append(line, pos, line.length() - pos);
		outFile << result;
		if (!inFile.eof())
			outFile << "\n";
	}

	inFile.close();
	outFile.close();
	return 0;
}
