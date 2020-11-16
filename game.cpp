/* Game
*  Setup Game Class */

// Libraries //
#include "game.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* Constructor
*  Initial class object */
Game::Game() {
	playerCount = 0;
	breakerPts = 0;
	makerPts = 0;
	matchMax = 0;
	guessMax = 0;
	difficulty = 0;
	matchCount = 1;
	guessCount = 1;
	allowDup = false;
	allowBlank = false;
	code = "";
	codeBreaker = "";
	codeMaker = "";
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* setPlayerCount
*  Sets PlayerCount */
void Game::setPlayerCount(int pCount) {
	playerCount = pCount;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* setMatchMax
*  Sets MatchMax */
void Game::setMatchMax(int mMatch) {
	matchMax = mMatch;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* setDifficulty
*  Sets Difficulty */
void Game::setDifficulty(int diff) {
	difficulty = diff;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* setGuessMax
*  Sets GuessMax */
void Game::setGuessMax() {
	switch (difficulty) {
		case 1:
			guessMax = 12;
			break;
		case 2:
			guessMax = 10;
			break;
		case 3:
			guessMax = 8;
			break;
		default:
			cout << "WARNING - Guess Max is not set.\n";
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* setDuplication
*  Sets AllowDup */
void Game::setDuplication(char dup) {
	if (dup == 'Y') {
		allowDup = true;
	}
	else {
		allowDup = false;
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* setBlanks
*  Sets AllowBlank */
void Game::setBlanks(char blank) {
	if (blank == 'Y') {
		allowBlank = true;
	}
	else {
		allowBlank = false;
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* setCodeBreaker
*  Sets CodeBreaker */
void Game::setCodeBreaker(string name) {
	codeBreaker = name;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* setCodeMaker
*  Sets CodeMaker */
void Game::setCodeMaker(string name) {
	codeMaker = name;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* setCode
*  Sets CodeM */
void Game::setCode(string code) {
	code = code;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* checkCode
*  Checks code's validity */
bool Game::checkCode(string code) {
	const char colors[] = { 'R', 'O', 'Y', 'T', 'G', 'P', 'B' }; //aray of valid colors
	int maxColors = 6;
	int validCheck = 0;
	if (allowBlank == true) maxColors++; //if blank is allowed, accept 'B' in array
	if (code.length() == 4) {
		for (string::size_type i = 0; i < code.length(); ++i) { //for every char in the string
			if (allowDup == false) {
				for (string::size_type j = i + 1; j < code.length(); ++j) { //checks original char with other char
					if (code[i] == code[j]) return false;
				}
			}
			for (int k = 0; k < maxColors; k++) {
				if (code[i] == colors[k]) validCheck++; //increment when a match is spotted
			}
		}
		if (validCheck == 4) return true;
		else return false;
	}
	else {
		return false;
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* checkGuess
*  Checks guess's validity */
bool Game::checkGuess(string guess) {
	const char colors[] = { 'R', 'O', 'Y', 'T', 'G', 'P', 'B' }; //aray of valid colors
	int maxColors = 6;
	int validCheck = 0;
	if (allowBlank == true) maxColors++;
	if (code.length() == 4) {
		for (string::size_type i = 0; i < code.length(); ++i) {
			for (int j = 0; j < maxColors; j++) {
				if (code[i] == colors[j]) validCheck++; //increment when a match is spotted
			}
		}
		if (validCheck == 4) return true;
		else return false;
	}
	else {
		return false;
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* resetGame
*  Resets counter for next game */
void Game::resetGame() {
	matchCount = 1;
	guessCount = 1;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//
/* checkGuessCorrect
*  Checks if guess is correct. If not, show hints */
void Game::checkGuessCorrect(string guess) {
	int correct = 0;
	int partialcorrect = 0;
	bool peg1 = false;
	bool peg2 = false;
	bool peg3 = false;
	bool peg4 = false;
	for (string::size_type i = 0; i < 4; i++) {
		if (guess[i] == code[i]) {
			correct++;
			switch (i) {
				case 0:
					peg1 = true;
				case 1:
					peg2 = true;
				case 2:
					peg3 = true;
				case 3:
					peg4 = true;
				default:
					cout << "Warning - Error unexpected\n";
			}
		}
	}
	if ((peg1 == false) || (peg2 == false) || (peg3 == false) || (peg4 == false)) {

	}

}