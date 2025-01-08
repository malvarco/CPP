#include<iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::to_string;

int main() {

    int max, guess, random_number;
    guess = 0;
    max = 10;	// Choose max number
    max--;		// Dec 1 so it's not 0
    random_number = arc4random() % max + 1;
    max++;		// Add 1 so number is the same again
    cout << "\033[2J\033[1;1H"; // Clearscreen

    while (guess != random_number)
    {
        cout << "Guess a random number between 1 and " + to_string(max) + ":\n";
        cin >> guess;

        if (guess < random_number)
            cout << "Sorry, guess again. Too low.\n";
        else if (guess > random_number)
            cout << "Sorry, guess again. Too high.\n";
    }
    cout << "Yes, congrats. You have guessed the number " + to_string(random_number) + " correctly!";

    getc(stdin);

    return 0;
}
