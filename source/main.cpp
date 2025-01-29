#include <iostream>
#include <string>

#include "wincon.h"		// Include the main library I wrote for doing things in the console (mainly with escape codes)
#include "strtools.h"	// Include the main library I wrote for managing and changing strings

using namespace std;

const string templates[1] = { // This is the main variable that will store all of the templates
	"{PR}#include {RD}<iostream>{DF}\n\n{CY}int {YW}main{PR}() {YW}{\n    {GR}std{WT}::cout << {RD}\"Hello, world!\"{WT};\n{YW}}{DF}"
};

int main() {
	// Initialize some of the variables needed to run
	string userInput = "NOTHING HERE YET!"; // The variable that will store the users input

	// Initialize the application for general use
	system("cls");
	SetConTitle("Code Templater Plus Plus");

	// The main application code
	cout << "Welcome to Code Templater Plus Plus!\nType \"help\" for a list of commands." << endl;

	while (true) {
		cout << "Code Templater: ";
		getline(cin, userInput); // Get the users input and save it to a variable
		userInput = toLowerCase(userInput); // Convert the users input to lower case so its able to work better

		if (userInput == "help") {
			cout << "Here is a list of commands you can use!" << endl;
			cout << "help            - Displays this list of commands" << endl;
			cout << "exit            - Exits out of the application" << endl;
		}
		else if (userInput == "exit") {
			PrintColorString("Thank you for using ", MAGENTA, false);
			PrintColorString("Code Templater Plus Plus", CYAN, false);
			PrintColorString("!", MAGENTA, true);
			cout << "Press \"enter/return\" to continue...";
			getline(cin, userInput);
			break;
		}
		else {
			PrintColorString("The command you entered is invalid!", RED, true);
		}
	}

	// End of application code
	return 0;
}
