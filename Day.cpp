#include "Day.h"

Day::Day(const std::string& inputFile) {
	file.open("data/" + inputFile);

	if (!file.is_open()) {
		std::string err = "Failed to open file: " + inputFile;
		std::cerr << err << std::endl;
		return;
	}
}

bool Day::getLine() {
	if (std::getline(file, line))
		return true;

	return false;
}

void Day::part1() {
	std::cout << "part1() not implemented";
}

void Day::part2() {
	std::cout << "part2() not implemented";
}