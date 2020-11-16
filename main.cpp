/* Mastermind - Dean Nguyen
*  This is a C++ version of the game "Mastermind"
*  A two-player game where one player "Codemaker" chooses a series of four "pegs" for the other player "Codebreaker" to guess.
*  There are six different color pegs: Red, Orange, Yellow, Teal, Green, Purple
*  The game will ask the players how many games they will play (must be an even number).
*  The game will also ask how many guesses the Codebreaker should have (a choice of 6, 8, 10, or 12).
*  The Codemaster can have duplicates and/or blanks depending on player choice. */

// Libraries //
#include "tutorial.h"
#include "generateCode.h"
#include "game.h"
#include "uppercase.h"
using namespace std;

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

// Main //
int main() {
	// Variables //
	int iChoice = 0;			//integer for user's integer input
	char cChoice = ' ';			//character for user's character input
	bool isCodeValid = false;	//boolean to check code validity
	bool isGuessValid = false;  //boolean to check guess validity
	string code = "";			//string for code used in game
	string name = "";			//string for inputting names
	string guess = "";			//string for user's sequence guess

	//------------------------------------------------------------------------------------------------------------------------------------------------------------//

	// Intro //
	cout << "Welcome to Mastermind\n\n";
	cout << "Do you wish to see the tutorial? (Y/N): ";
	cin >> cChoice;
	cChoice = charUppercase(cChoice);

	/* Error Check #1
	*  Checking if user inputs a value other than Y or N */
	while ((cChoice != 'Y') && (cChoice != 'N')) {
		cout << "\nInvalid choice. Please try again: ";
		cin >> cChoice;
		cChoice = charUppercase(cChoice);
	}

	//------------------------------------------------------------------------------------------------------------------------------------------------------------//

	// Tutorial //
	if (cChoice == 'Y') {
		postTutorial();
	}

	//------------------------------------------------------------------------------------------------------------------------------------------------------------//

	// Setup //
	Game Mastermind; //Create game object

	// Player Count //
	cout << "\nChoose '1' for Single-Player\nChoose '2' for Two-Player\nChoice: ";
	cin >> iChoice;

	/* Error Check #2
	*  Checking if user inputs a value other than 1 or 2 */
	while ((iChoice != 1) && (iChoice != 2)) {
		cout << "\nInvalid choice. Please try again: ";
		cin >> iChoice;
	}

	Mastermind.setPlayerCount(iChoice);

	//------------------------------------------------------------------------------------------------------------------------------------------------------------//

	// Matches //
	cout << "\nHow many matches do you want to play? (Only even numbers): ";
	cin >> iChoice;

	/* Error Check #3
	*  Checking if user inputs an odd number */
	while (true) {
		if (iChoice % 2 == 0) { //if it's an even number
			if (iChoice != 0) { //if it's not 0
				break;
			}
		}
		cout << "\nInvalid choice. Please try again: ";
		cin >> iChoice;
	}

	Mastermind.setMatchMax(iChoice);

	//------------------------------------------------------------------------------------------------------------------------------------------------------------//

	// Difficulty //
	cout << "\nWhat difficulty do you choose?\n";
	cout << "Easy (1) - 12 Guesses\n";
	cout << "Medium (2) - 10 Guesses\n";
	cout << "Hard (3) - 8 Guesses\n";
	cout << "Choice: ";
	cin >> iChoice;

	/* Error Check #4
	*  Checking is user inputs a value other than 1/2/3 */
	while ((iChoice != 1) && (iChoice != 2) && (iChoice != 3)) {
		cout << "Invalid choice. Please try again: ";
		cin >> iChoice;
	}

	Mastermind.setDifficulty(iChoice);

	// Guesses //
	Mastermind.setGuessMax();

	//------------------------------------------------------------------------------------------------------------------------------------------------------------//

	// Duplicates/Blanks //
	cout << "\nDo you want the code to potentially have duplicates? (Y/N): ";
	cin >> cChoice;
	cChoice = charUppercase(cChoice);

	/* Error Check #5
	*  Checking if user inputs a value other than Y or N */
	while ((cChoice != 'Y') && (cChoice != 'N')) {
		cout << "\nInvalid choice. Please try again: ";
		cin >> cChoice;
		cChoice = charUppercase(cChoice);
	}

	Mastermind.setDuplication(cChoice);

	cout << "\nDo you want the code to potentially have blanks? (Y/N): ";
	cin >> cChoice;
	cChoice = charUppercase(cChoice);

	/* Error Check #6
	*  Checking if user inputs a value other than Y or N */
	while ((cChoice != 'Y') && (cChoice != 'N')) {
		cout << "\nInvalid choice. Please try again: ";
		cin >> cChoice;
		cChoice = charUppercase(cChoice);
	}

	Mastermind.setBlanks(cChoice);

	//------------------------------------------------------------------------------------------------------------------------------------------------------------//

	// Names //
	cout << "\nWhat is the Codebreaker's name?: ";
	cin >> name;

	Mastermind.setCodeBreaker(name);

	// Code Creation //
	if (Mastermind.playerCount == 1) {
		code = generateCode(Mastermind.allowDup, Mastermind.allowBlank);
		cout << "The code has been chosen by the program.\n";
		Mastermind.setCode(code);
	}
	else if (Mastermind.playerCount == 2) {
		cout << "What is the Codemaker's name?: ";
		cin >> name;
		Mastermind.setCodeMaker(name);
		cout << "\nIt is " << Mastermind.codeMaker << "'s turn to create the code.\n";
		cout << Mastermind.codeBreaker << ", please look away.\n\n";
		cout << "Please enter your code:\n";
		cout << "NOTE: Enter in a 4-letter code. The code should be a combination of these acceptable colors:\n";
		cout << "'R'ed, 'O'range, 'Y'ellow, 'T'eal, 'G'reen, and 'P'urple. 'B'lank (if acceptable)\n";
		cout << "Please use the first-letter of the colors only.\n";
		cin >> code;
		code = stringUppercase(code);

		/* Error Check #7
		*  Checking if user inputs a valid code */
		while (true) {
			isCodeValid = Mastermind.checkCode(code);
			if (isCodeValid == false) {
				cout << "\nInvalid code. Please try again: ";
				cin >> code;
				code = stringUppercase(code);
			}
			else {
				break;
			}
		}

		cout << "\nThe code is valid, and is now inputted.\n";
		Mastermind.setCode(code);
	}

	cout << "\nSetup is complete! The game has commenced.\n\n";

	//------------------------------------------------------------------------------------------------------------------------------------------------------------//

	// Game //
	do {
		cout << "Match " << Mastermind.matchCount << "/" << Mastermind.matchMax << "\n\n";
		cout << Mastermind.codeBreaker << ", guess the sequence.\n";
		cout << "NOTE: Enter in a 4-letter code. The code should be a combination of these acceptable colors:\n";
		cout << "'R'ed, 'O'range, 'Y'ellow, 'T'eal, 'G'reen, and 'P'urple. 'B'lank (if acceptable)\n";
		cout << "Please use the first-letter of the colors only.\n";
		do {
			isGuessValid = false;
			cout << "Guess " << Mastermind.guessCount << "/" << Mastermind.guessMax << ": ";
			cin >> guess;
			guess = stringUppercase(guess);

			/* Error Check #8
			*  Checking if user inputs a valid guess */
			while (true) {
				isGuessValid = Mastermind.checkGuess(guess);
				if (isGuessValid == false) {
					cout << "\nInvalid code. Please try again: ";
					cin >> guess;
					guess = stringUppercase(guess);
				}
				else {
					break;
				}
			}




		} while (Mastermind.guessCount > Mastermind.guessMax);
	} while (Mastermind.matchCount > Mastermind.matchMax);
}