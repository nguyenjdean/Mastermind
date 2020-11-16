Mastermind (WIP) - C++ Project
Dean Nguyen

This is a C++ project of the 1970 game "Mastermind".
In the game, a player which is named the "Codebreaker" has to guess the code the "Codebreaker" created.
The code is a series of four "pegs" where each peg represents a color.
The Codebreaker has a certain amount of guesses to guess the code.
If the Codebreaker guesses the code correctly before the amount of guesses exceed, the Codemaker receive points equal to how many guesses the Codebreaker uses. 
If the Codebreaker can't guess the code before all the guesses are used, the Codemaker receive points equal to the max guesses plus one.
After that, roles are switched and then a new match starts with the Codemaker creating the code for the Codebreaker to guess.
After all matches are done, the players tally up their points. The person with the most points win.

In this C++ game, the user can choose between one or two players.
In two-player mode, it follows the original game structure with some help from the program.
In one-player mode, an AI creates the code for the user and the user plays with the amount of matches the user wants.
In the game, there's a text tutorial of how to play.
The user can choose how many matches the user wants to play.
The user can also choose the difficulty which represents how many guesses the Codebreaker can have per match.
The user can also choose whether the code can potentially have duplicate colors in the code. The user can also choose whether the code can have blanks.
The game plays normally in a command prompt with instructions. All points and numbers are calculated and can be shown by the program.
