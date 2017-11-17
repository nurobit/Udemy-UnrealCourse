#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//	all values initialized to zero
struct FBullCowCount
{
	int32	Bulls = 0;
	int32	Cows = 0;
};

//	creating error values for the hidden word status
enum class EGuessStatus
{
	OK,
	Not_Isogram,
	Length_Mismatch,
	Case_Mismatch
};

//	Writing and using getter variables
//	  
class FBullCowGame {
public:
	FBullCowGame();		//	Constructor -- made by calling the class/struct within itself
	int32		GetMaxTries() const;
	int32		GetCurrentTry() const;	//	what I guessed
	int32		GetWordLength() const;
	char	*GetCurrentWord();	//	my extra guess that wasn't used
	bool	IsGameWon() const;

	void	Reset();	//	TODO -- make a more defined return value
	EGuessStatus	CheckGuess(FString);	//	TODO -- make a more defined return value

	//	counts bulls and cows, and increases turn number (myCurrentTry)
	FBullCowCount	SubmitGuess(FString);
	FString		ToLowercase(FString);
	FString		PrintGameSummary();


//	Ignore this for now >>
private:
	//	variables -- known as member variables
	//	variables initialized here -- defined inside of the Constructor (values are overridden at runtime)
	//	TODO -- add variable to KEEP score, not just DISPLAY the score - use this to determine if game is won
	int32	MyCurrentTry;
	int32	MyMaxTries;
	int32	bScore;
	FString	MyHiddenWord;
	bool	IsIsogram(FString);
	bool	IsIsogramFast(FString) const;
	bool	IsLowercase(FString) const;
};