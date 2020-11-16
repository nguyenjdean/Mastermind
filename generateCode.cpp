/* generateCode
*  Generate Sequence of Pegs */

// Libraries //
#include "generateCode.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

// Function //
string generateCode(bool dup, bool blank) {
	// Variables //
	int peg1, peg2, peg3, peg4;									//integers for each random number associated with a peg
	int colorCount = 6;											//integer of how many colors to choose from: 1 = Red, 2 = Orange, 3 = Yellow, 4 = Teal, 5 = Green, 6 = Purple, 7 = Blank
	string code = "";											//string for initial code
	string color[7] = { "R", "O", "Y", "T", "G", "P", "B" };	//array of color strings

	//------------------------------------------------------------------------------------------------------------------------------------------------------------//

	// Initialize Random Seed //
	random_device rd; //create random seed
	mt19937 gen(rd()); //initialize mersenne twister pseudo-RNG

	//------------------------------------------------------------------------------------------------------------------------------------------------------------//

	// Blank //
	if (blank == true) colorCount++; //if it allows blanks, it increases colorCount by 1 to include value '7'

	//------------------------------------------------------------------------------------------------------------------------------------------------------------//

	// Generate //
	uniform_int_distribution<> dis(1, colorCount); //generate random numbers from 1 to colorCount
	while (true) {
		peg1 = dis(gen); //generate number
		peg2 = dis(gen);
		peg3 = dis(gen);
		peg4 = dis(gen);
		if ((peg1 == peg2) || (peg1 == peg3) || (peg1 == peg4) || (peg2 == peg3) || (peg2 == peg4) || (peg3 == peg4)) { //if there are any duplicates
			if (dup == true) { //if duplication is allowed
				break; //accept code
			} //will redo code generation if there are duplicates, but no duplicates are allowed
		}
		else { //accept code if there's no duplication no matter what
			break;
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------------------------------------//

	// Create Code //
	code.insert(0, color[peg1 - 1]); //inserts string based on value of each peg
	code.insert(1, color[peg2 - 1]);
	code.insert(2, color[peg3 - 1]);
	code.insert(3, color[peg4 - 1]);

	//------------------------------------------------------------------------------------------------------------------------------------------------------------//

	return(code);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//