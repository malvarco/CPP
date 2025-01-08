#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::exception;
using std::cerr;
using std::ifstream;
using std::getline;
using std::vector;
using std::strlen;
using std::toupper;
using std::to_string;

/*
 * It will iterate through all the lines in file wordlist and
 * put them in given vector
 */

bool getFileContent(string, vector<string>&);

int main() {

    try {

        time_t nTime;
        srand((unsigned)time(&nTime));

        int wordlistSize, randomNumber, lives, missingLetters;
        string chosenWord, hiddenWord, usedLetters;
        char userGuess;
        vector<string> vectWordlist;
        bool success = false, validGuess;

        // Get the contents of file in a vector
        bool result = getFileContent("wordlist", vectWordlist);
        if (result)
        {

            wordlistSize = vectWordlist.size();

            userGuess = ' ';
            lives = 7;

            usedLetters = "";

            randomNumber = arc4random() % wordlistSize;
            chosenWord = vectWordlist.at(randomNumber);

            cout << "\033[2J\033[1;1H"; // Clearscreen

            // Replace letters with --- using string function replace() instead of awkward for loops.
            hiddenWord = chosenWord;
            hiddenWord.replace(0,hiddenWord.length(),hiddenWord.length(),'-');

            missingLetters = strlen(chosenWord.c_str());

            cout << hiddenWord << "\n";

            while (1)
            {
                cout << "Guess a letter: \n";
                validGuess = false;
                while (validGuess == false) {
                    cin >> userGuess;
                    userGuess = toupper(userGuess);
                    if (usedLetters == "") validGuess = true;
                    for (auto& c : usedLetters) {
                        validGuess = true;
                        if (userGuess == c)
                        {
                            cout << "You've already used that letter. Try again.\n";
                            validGuess = false;
                            break;
                        }
                    }
                }
                usedLetters += userGuess;
                cout << "Used Letters: " << usedLetters << "\n";

                bool hit = false;
                for (auto& c : chosenWord) {
                    if (userGuess == c) {
                        hiddenWord[&c - &chosenWord[0]] = userGuess;
                        missingLetters--;
                        hit = true;
                    }
                }
                if (hit == false) lives--;

                if (userGuess == 'X') break;

                cout << "\033[2J\033[1;1H"; // Clearscreen

                cout << hiddenWord << "\n";
                cout << "You have " << lives << " lives left.\n";

                if (lives <= 0)
                {
                    break;
                }

                if (missingLetters <= 0)
                {
                    success = true;
                    break;
                }
            }

            if (success == true)
            {
                cout << "\nGreat! Wonderful!!!\n";
            }
            else {
                cout << "\nSorry, you are hanged!\n";
                cout << "The right word was " << chosenWord << "\n";
            }
        }
    }

    catch (exception& e) {
        cerr << e.what() << "\n";
    }

    getc(stdin);
    return 0;
}

bool getFileContent(string fileName, vector<string>& vecOfStrs)
{
    // Open the File
    ifstream in(fileName.c_str());
    // Check if object is valid
    if (!in)
    {
        cerr << "Cannot open the File : " << fileName << "\n";
        return false;
    }
    string str;
    // Read the next line from File untill it reaches the end.
    while (getline(in, str))
    {
        for (auto& c : str) {
            c = toupper(c);
        }

        // Line contains string of length > 0 then save it in vector
        if (str.size() > 0)
            vecOfStrs.push_back(str);
    }
    //Close The File
    in.close();
    return true;
}
