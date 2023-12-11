#include "Day01.h"
#include <cctype>
#include <cstring>


Day01::Day01() : Day("01.txt") {
	part2();
}

void Day01::part1() {
	std::cout << "Day01::part1()" << std::endl;

	int total = 0;
	char ch = 0;
	int i = 0;
	int x = -1;
	int y = -1;

	while (getLine()) {
		do {
			ch = line[i++];

			// If it's not a digit
			if (ch < '0' || ch > '9') {
				continue;
			}

			// If it's the first digit, set for both places
			if (x == -1) {
				x = (ch - '0');
				y = (ch - '0');
			}
			// Otherwise update second place with latest digit found
			else {
				y = (ch - '0');
			}
		} while (ch != '\0');

		// Add new total if we found something on that line
		if (x > -1) {
			total += x * 10 + y;
		}

		i = 0;
		x = -1;
		y = -1;
	}

	std::cout << total << std::endl;
}

void Day01::part2() {
	std::cout << "Day01::part2()" << std::endl;

	int total = 0;
	char ch = 0;
	int i = 0;
	int x = -1;
	int y = -1;

	const int WORDS_SIZE = 10;

	std::string numbers[WORDS_SIZE] = {
		"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
	};

	// Contains the lengths of words
	int wordSizes[WORDS_SIZE] = {};

	// Stores which character index we are up to on a word match
	int matchIndexes[WORDS_SIZE] = {};

	// Pre-store word lengths
	for (int k = 0; k < WORDS_SIZE; k++) {
		wordSizes[k] = numbers[k].size();
	}

	while (getLine()) {
		do {
			// Get current character
			ch = line[i++];

			// If it's not a digit, run a word check
			if (ch < '0' || ch > '9') {

				ch = std::tolower(static_cast<unsigned char>(ch));

				// Loop through each word
				for (int j = 0; j < WORDS_SIZE; j++) {

					int matchIndex = matchIndexes[j];
					char checkCh = numbers[j][matchIndex];

					// We're matching the index
					if (ch == checkCh) {
						matchIndexes[j] += 1;
							
						// Check if we completed the word
						if (matchIndexes[j] >= wordSizes[j]) {
							// If we did, store it
							if (x == -1) {
								x = j;
								y = j;
							}
							else {
								y = j;
							}

							// Reset our match index tracker for this word
							matchIndexes[j] = 0;
							continue;
						}

						continue;
					}
					// We aren't matching, check if we match the start char of the word
					else if (ch == numbers[j][0]) {
						matchIndexes[j] = 1;
						continue;
					} 
					// No match at all, reset the index
					else {
						matchIndexes[j] = 0;
						continue;
					}
				}

				continue;
			}

			// Non-alpha character, reset the searches back to 0
			memset(matchIndexes, 0, WORDS_SIZE * sizeof(int)); 

			// If it's the first digit, set for both places
			if (x == -1) {
				x = (ch - '0');
				y = (ch - '0');
			}
			// Otherwise update second place with latest digit found
			else {
				y = (ch - '0');
			}
		} while (ch != '\0');

		// Add new total if we found something on that line
		if (x > -1) {
			total += x * 10 + y;
		}

		i = 0;
		x = -1;
		y = -1;
		memset(matchIndexes, 0, WORDS_SIZE * sizeof(int)); // Set all bytes of the array to 0
	}

	std::cout << total << std::endl;
}