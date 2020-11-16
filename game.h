#pragma once

// Libraries //
#include <iostream>
#include <string>
using namespace std;

// Class //
class Game {
	public:
		// Variables //
		int playerCount;
		int breakerPts;
		int makerPts;
		int matchMax;
		int guessMax;
		int difficulty;
		int guessCount;
		int matchCount;
		bool allowDup;
		bool allowBlank;
		string code;
		string codeBreaker;
		string codeMaker;

		// Functions //
		Game();
		void setPlayerCount(int pCount);
		void setMatchMax(int mMax);
		void setDifficulty(int diff);
		void setGuessMax();
		void setDuplication(char dup);
		void setBlanks(char blank);
		void setCodeBreaker(string name);
		void setCodeMaker(string name);
		void setCode(string code);
		bool checkCode(string code);
		bool checkGuess(string guess);
		void resetGame();
		void checkGuessCorrect(string guess);
};