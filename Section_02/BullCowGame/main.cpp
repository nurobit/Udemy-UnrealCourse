/*	
//	This is the console executable.
//	MVC pattern. Responsible for all user interaction. Game logic.
//	Magic numbers? 
//	Using a new concept called "constexp" or Constant Expression. Creates a constant value that cannot be changed once the program is compiled.
//	(Why not just use "const'?)
//	
*/

#include <iostream>		// Standard, built-in libraries. Enclosed with chevrons, ie. "angle brackets" -- Double quotes are used to include additional project files.
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void	stdCalls();
void	callIntro();
void	playGame();
void	GetValidGuess();
FText	getPlayerInput();
bool	playAgain();

FBullCowGame BCGame;	//	Instantiate a new game

//	the main brain
int		main()
{
	stdCalls();
	return (0);
}


void	stdCalls()
{
	callIntro();
	playGame();
	while (playAgain())
		playGame();
	return;
}

void	callIntro()
{
	//	INTRODUCE THEGAMMMEE!!!!!
	std::cout << ">>>>> Welcome to The Game Tutorial: Bulls & Cows <<<<<\n\n";		//cout uses an "overloader" which is the "<<" double-chevron (angle bracket)
	std::cout << " Bulls:\tMeans you have guessed the correct letter in the correct position.\n";
	std::cout << "  Cows:\tMeans you have guessed the correct letter in the wrong position.\n";
	std::cout << "TIUME TO PLAYE THEGAAMMEE ~~ !!\n";
	std::cout << "Guess the letter of the word.\n\n";
}

void	playGame()
{
	BCGame.Reset();
	int32	Chances;
	
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries())
	{
		Chances = BCGame.GetMaxTries() - (BCGame.GetCurrentTry() - 1);
		std::cout << "You have " << Chances << " remaining.\n";



		//	take a gander
		GetValidGuess();
	}
	std::cout << BCGame.PrintGameSummary();
}

//	loop until user gives a valid guess
void	GetValidGuess()
{
	std::cout << "------Attempt #" << BCGame.GetCurrentTry() << " of possible " << BCGame.GetMaxTries() << "------\nEn4ter your guess: ";
	FText	Guess;	//	TODO make input validator -->	input is Validated using the "CheckGuess" property of the game instance (BCGame)
	FBullCowCount BCCount;
	EGuessStatus Status = EGuessStatus::Length_Mismatch;

	while (Status != EGuessStatus::OK)
	{
		Status = BCGame.CheckGuess(Guess = BCGame.ToLowercase(getPlayerInput()));
		//	error check
		switch (Status)
		{
		case EGuessStatus::OK:
			//	Submit valid guess to the game
			BCCount = BCGame.SubmitGuess(Guess);
			std::cout << "Bulls: " << BCCount.Bulls << " | Cows: " << BCCount.Cows << "\n++++++\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "------\nPlease enter an isogram.\n------\n";
			break;
		case EGuessStatus::Length_Mismatch:
			std::cout << "------\nPlease enter a " << BCGame.GetWordLength() << " letter word.\n------\n";
			break;
		case EGuessStatus::Case_Mismatch:
			std::cout << "Please enter text in all lowercase.\n\n";
			break;
		default:
			std::cout << "------\nPlease enter a " << BCGame.GetWordLength() << " letter word.\n------\n";
			break;
			
		}
	}
	return;
	//	print player input
	//	std::cout << "\nThe overlords are amused.\n" << "You guessed \"" << Guess << "\"\n\n";
}


bool	playAgain()
{
	FText	response;

	std::cout << "The overlords demand more amusement.\t" << "Play again?\n";
	response = getPlayerInput();
	return (response[0] == 'y' || response[0] == 'Y' || response[0] == '1');
}

FText	getPlayerInput()
{
	FText Input = "";
	while (Input.length() == 0)
		std::getline(std::cin, Input);
	return (Input);
}
