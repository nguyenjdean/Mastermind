/* Tutorial
*  Output tutorial */

// Libraries //
#include "tutorial.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

// Function //
void postTutorial() {
	cout << "\nMastermind is a puzzle game in which the Codebreaker tries to guess the code their opponent comes up with.\n";
	cout << "The Codemaker selects a code where four 'pegs' are chosen in a sequence. The pegs have six different colors:\n";
	cout << "Red, Orange, Yellow, Teal, Green, Purple. The Codemaker can choose duplicates or blanks, but only with the allowance of the Codebreaker.\n";
	cout << "The Codebreaker has limited amount of guesses to find out the sequence. When the Codebreaker places a guess, the program will state how many pegs are:\n";
	cout << "'The right color and in the right space' AND 'The right color but not in the right space'. These hints can help the Codebreaker guess the right sequence.\n";
	cout << "When the Codebreaker guesses it correctly, the game stops. The Codemaker gets the # of points equal to how many guesses the Codebreaker uses.\n";
	cout << "If the Codebreaker didn't guess the sequence correctly before guesses are used, the Codemaker gets the # of points equal to how many max guesses there are plus a bonus point.\n";
	cout << "Whoever has the most points before all matches finished is the winner.\n";
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//