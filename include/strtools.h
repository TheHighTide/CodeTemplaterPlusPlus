#ifndef STRING_TOOLS_H
#define STRING_TOOLS_H

#include <cctype>
#include <string>

std::string toLowerCase(const std::string& input) {
	std::string result = input;

	for (char& c : result) {
		c = std::tolower(c);
	}

	return result;
}

#endif
