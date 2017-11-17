/*
//	Magic numbers?
//	Using a new concept called "constexp" or Constant Expression. Creates a constant value that cannot be changed once the program is compiled.
//	(Why not just use "const'?)
//
*/

#include <iostream>		// Standard, built-in libraries. Enclosed with chevrons, ie. "angle brackets" -- Double quotes are used to include additional project files.
#include <string>
#include "FBullCowGame.h"

void		stdCalls();
void		callIntro();
void		playGame(int &Chances);
std::string	getGuess();
int			checkGuess(std::string Guess);
std::string	getPlayerInput();
bool		playAgain();

//	the main brain
int			main()
{
	stdCalls();
	return (0);
}

void		stdCalls()
{
	//	All things using the namespace "std" to begin here. For consolidation reasons.
	using namespace std;				//	i realize my mistake (living with it intentionally, for now)
	int Chances = 5;

	callIntro();
	playGame(Chances);
	while (playAgain())
		playGame();
	return;
}

void		playGame(int &Chances)
{
	//	get guess
	while (Chances > 0)
	{
		//	take a gander
		std::cout << "You have " << Chances-- << " remaining.\n";
		if (checkGuess(getGuess()))
			return;
		//	reassure the human
		std::cout << "It doesn't matter what you guessed!\n\n";
	}
}

void		callIntro()
{
	//	INTRODUCE THEGSAYME!!!!!
	constexpr int	WORD_LENGTH = 9;

	std::cout << ">>>>> Welcome to The Game Tutorial: Bulls & Cows <<<<<\n\n";		//cout uses an "overloader" which is the "<<" double-chevron (angle bracket)
	std::cout << "TIUME TO PLAYE THEGAYME ~~ !!\n";
	std::cout << "Guess the letter of the word.\n\n";
	std::cout << "Isogram length is " << WORD_LENGTH << "\t\n\n";
}

std::string	getPlayerInput()
{
	std::string Input = "";
	while (Input == "")
		std::getline(std::cin, Input);
	return (Input);
}

std::string	getGuess()
{
	std::cout << "Test your luck ";
	std::string Guess = getPlayerInput();
	std::cout << "\nThe overlords are amused.\n" << "You guessed \"" << Guess << "\"\n\n";
	return (Guess);
}

int			checkGuess(std::string Guess)
{

	return (0);
}

bool		playAgain()
{
	std::string	response = "";

	std::cout << "The overlords demand more amusement.\t" << "Play again?\n";
	response = getPlayerInput();
	return ((response[0] == 'y' || response[0] == 'Y' || response[0] == '1') ? true : false);
}
