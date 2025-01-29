#ifndef WINDOWS_CONSOLE_H
#define WINDOWS_CONSOLE_H

#include <iostream>
#include <string>
#include <unordered_map>

enum ConsoleColor {
	DEFAULT,
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE
};

std::unordered_map<std::string, std::string> colorCodeMap = {
	{"{PR}", "\033[35m"}, // Purple
	{"{RD}", "\033[31m"}, // Red
	{"{DF}", "\033[39m"}, // Default
	{"{CY}", "\033[36m"}, // Cyan
	{"{YW}", "\033[33m"}, // Yellow
	{"{GR}", "\033[32m"}, // Green
	{"{WT}", "\033[37m"}  // White
};

void SetConTitle(std::string text) {
	std::cout << "\033]0;" << text << "\007";
}

void SetForegroundColor(ConsoleColor color) {
	if (color == DEFAULT) {
		std::cout << "\033[39m";
	}
	else if (color == BLACK) {
		std::cout << "\033[30m";
	}
	else if (color == RED) {
		std::cout << "\033[31m";
	}
	else if (color == GREEN) {
		std::cout << "\033[32m";
	}
	else if (color == YELLOW) {
		std::cout << "\033[33m";
	}
	else if (color == BLUE) {
		std::cout << "\033[34m";
	}
	else if (color == MAGENTA) {
		std::cout << "\033[35m";
	}
	else if (color == CYAN) {
		std::cout << "\033[36m";
	}
	else if (color == WHITE) {
		std::cout << "\033[37m";
	}
}

void PrintColorString(std::string string, ConsoleColor color, bool addNewLine) {
	SetForegroundColor(color);
	std::cout << string;
	SetForegroundColor(DEFAULT);
	if (addNewLine) std::cout << std::endl;
}

std::string parseCtemToString(const std::string &input) {
	std::string result = input;

	for (const auto& pair : colorCodeMap) {
		size_t pos = 0;

		while ((pos = result.find(pair.first, pos)) != std::string::npos) {
			result.replace(pos, pair.first.length(), pair.second);
			pos += pair.second.length();
		}
	}

	return result;
}

#endif
