/* stringUppercase
*  Make things upper-case */

// Libraries //
#include "uppercase.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* stringUppercase
*  Makes all strings upper-case */
string stringUppercase(string str) {
	char c;
	string s, origin;
	locale loc;
	origin = str;
	for (string::size_type i = 0; i < str.length(); ++i) { //goes through each char in the string
		c = str[i];
		if (islower(c, loc)) c = toupper(c, loc); //if that char is lower, change to upper
		s = c;
		origin.replace(i, 1, s);
	}
	return origin;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//

/* charUppercase
*  Makes all characters upper-case */
char charUppercase(char ch) {
	locale loc;
	char c;
	if (islower(ch, loc)) c = toupper(ch, loc); //if char is lower, change to upper
	return c;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//