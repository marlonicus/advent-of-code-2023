#pragma once

#include <iostream>
#include <string>
#include <fstream>

class Day
{
protected:
	std::string line;
	std::ifstream file;

	bool getLine();
	void part1();
	void part2();

public:
	Day(const std::string& inputFile);
};

