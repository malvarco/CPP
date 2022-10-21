/* Implementation of rock, paper, scissors by Kylie Ying
* Modified by manol for C++
*/


#include<iostream>
#include <string.h>
#include <sstream>

using std::string;
using std::cout;
using std::cin;
using std::system;
using std::cerr;
using std::exception;
using std::to_string;

bool getGameResult(const char, const char);
string getCompleteName(char);


int main() {
		
	try {

		char userChoice, PCchoice;
		char choices[3] = { 'r', 'p', 's' };
		int PC_random_guess;

		userChoice = ' ';

		time_t nTime;
		srand((unsigned)time(&nTime));

		system("cls"); // Clearscreen

		while (1)
		{
			cout << "What's your choice? 'r' for rock, 'p' for paper, 's' for scissors, 'x' end game? \n";
			cin >> userChoice;

			PC_random_guess = (rand() % 3);
			PCchoice = choices[PC_random_guess];

			if (userChoice == 'x') break;

			if ( userChoice == PCchoice)
			{
				cout << getCompleteName(userChoice) << " = " << getCompleteName(PCchoice) << "\n";
				cout << "It's a draw.\n";				
			} 
			else if (getGameResult(userChoice,PCchoice))
			{
				cout << getCompleteName(userChoice) << " > " << getCompleteName(PCchoice) << "\n";
				cout << "You win!\n";
			}
			else if (!getGameResult(userChoice, PCchoice))
			{
				cout << getCompleteName(userChoice) << " < " << getCompleteName(PCchoice) << "\n";
				cout << "You lose.\n";
			}
						
			system("pause");
		}		
						
		system("pause");	// Pause Wait for keypress...

	}

	catch (exception& e) {
		cerr << e.what() << "\n";
	}

	return 0;
}

bool getGameResult(char user, char pc)
{
	if (user == 'r' && pc == 's') return true;
	if (user == 's' && pc == 'p') return true;
	if (user == 'p' && pc == 'r') return true;

	return false;
}

string getCompleteName(char choice)
{
	if (choice == 'r') return "rock";
	if (choice == 'p') return "paper";
	if (choice == 's') return "scissors";
}