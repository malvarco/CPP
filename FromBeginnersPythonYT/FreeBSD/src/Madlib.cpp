// YTPythonProjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Project 01: Madlibs

#include <iostream>
// #include <conio.h>

using std::string;
using std::cout;
using std::cin;

int main()
{
    /* Concatenation basics
    using std::string;
    string youtuber = "";
    std::cout << "Suscribe to\n" + youtuber;
    */

    string adj1, adj2, adj3, adj4;
    string noun1, noun2, noun3, noun4, noun5, noun6;
    string noun_plural;
    string body_part, body_part2;
    string verb;
    string verb_past, verb_past2;
    string spell1, spell2;

    // char famous_person[100] = {0};

    // cin >> adj >> verb1 >> verb2;

    cout << "Adjective: "; cin >> adj1;
    cout << "Adjective: "; cin >> adj2;
    cout << "Adjective: "; cin >> adj3;
    cout << "Adjective: "; cin >> adj4;
    cout << "Noun: "; cin >> noun1;
    cout << "Noun: "; cin >> noun2;
    cout << "Noun: "; cin >> noun3;
    cout << "Noun: "; cin >> noun4;
    cout << "Noun: "; cin >> noun5;
    cout << "Noun: "; cin >> noun6;
    cout << "Noun plural: "; cin >> noun_plural;
    cout << "Body part: "; cin >> body_part;
    cout << "Body part: "; cin >> body_part2;
    cout << "Verb: "; cin >> verb;
    cout << "Verb (past tense): "; cin >> verb_past;
    cout << "Verb (past tense): "; cin >> verb_past2;
    cout << "Spell: "; cin >> spell1;
    cout << "Spell: "; cin >> spell2;

    // cout << "Famous person: "; cin >> famous_person; // Error cin won't accept spaces
    // Use cin.get() instead. cin.ignore() to clean keyboard buffer is needed.
    // cout << "Famous person: "; cin.ignore(); cin.getline(famous_person, 100);
    /* Original example
    string madlib = "Computer programming is so " + adj;
    madlib += "! It makes me so excited all the time because ";
    madlib += "I love to " + verb1 + ". Stay hydrated and ";
    madlib += verb2 + " like you are " + famous_person;
    */
    cout << "\033[2J\033[1;1H";
    string madlib;
    madlib = "A " + adj1 + " glow burst suddenly across the enchanted sky ";
    madlib += "above them as an edge of dazzling sun appeared over the sill ";
    madlib += "of the nearest " + noun1 + ". The light hit both of ";
    madlib += "their " + body_part + " at the same time, so that Voldemort's ";
    madlib += "was suddenly a flaming" + noun2 + ". Harry heard the high voice ";
    madlib += "shriek as he too " + verb_past + " his best hope to the heavens, ";
    madlib += "pointing Draco's" + noun3 + ":\n " + spell1 + "!\n";
    madlib +=  spell2 + "!\n";
    madlib += "The bang was like a cannon blast, and the " + adj2;
    madlib += " flames that erupted between them, at the dead center of ";
    madlib += "the circle they had been treading, marked the point where ";
    madlib += "the " + noun_plural + " collided.Harry saw Voldemort's ";
    madlib += adj3 + " jet meet his own spell, saw the Elder Wand ";
    madlib += "fly high, dark against the sunrise, spinning across the ";
    madlib += "enchanted ceiling like the head of Nagini, spinning through ";
    madlib += "the air toward the master it would not " + verb;
    madlib += " who had come to take full possession of it at last. ";
    madlib += "And Harry, with the unerring skill of a Seeker, ";
    madlib += "caught the " + noun4 + "in his free hand as Voldemort ";
    madlib += "fell backward, arms splayed, the slit pupils of the ";
    madlib += adj4 + body_part2 + " rolling upward. Tom Riddle hit the ";
    madlib += "floor with a mundane finality, his body feeble and shrunken, ";
    madlib += "the white hands empty, the snakelike face vacantand unknowing. ";
    madlib += "Voldemort was dead, " + verb_past2 + " by his own rebounding";
    madlib += noun5 + ", and Harry stood with two wands in his hands, ";
    madlib += "staring down at his enemy's " + noun6 + ".";

    cout  << madlib;
    // _getch();
    getc(stdin);
}
