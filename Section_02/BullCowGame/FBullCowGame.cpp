#include "FBullCowGame.h"
#include <map>
#define	TMap std::map

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { 
	return 50 * MyHiddenWord.length() / 36; 
}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetWordLength() const {	return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return (bScore == MyHiddenWord.length()); }
FString FBullCowGame::ToLowercase(FString s)
{
	int32 i = 0;
	while (i < s.length())
	{
		s[i] = ('A' <= s[i] && s[i] <= 'Z') ? s[i] + 32 : s[i];
		i++;
	}
	return s;
}


void FBullCowGame::Reset()
{
	const	FString		HIDDEN_WORD = "planet";
	constexpr	int32		MAX_TRIES = 8;

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bScore = 0;

	return;
}

EGuessStatus FBullCowGame::CheckGuess(FString Guess)
{
	//	TODO -- create a second test which will check to see if user input matches the isogram word
	//	FOR NOW -- create an initial test which performs simple validation checks before accepting user input
	//	pseudo
	//	if guess isn't isogram
	//	return	error
	//	if guess isn't lowercase
	//	return	error
	//	if guess isn't proper length
	//	return	error
	//	else
	//	return OK

	//	write	conditions and return errors
	if (!IsIsogram(Guess))
		return EGuessStatus::Not_Isogram;
	else
		if (!IsLowercase(Guess))
			return EGuessStatus::Case_Mismatch;
		else
			if (Guess.length() != GetWordLength())
				return EGuessStatus::Length_Mismatch;
			else
				return EGuessStatus::OK;
}

//	receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//	make sure user input can be used
	//	TODO -- will assume as true until actual test is created
	//	TODO -- will test if input is alphanumeric - make use of useful data as needed
	int32 i,j, MGLength = Guess.length();

	//	setup a return variable
	FBullCowCount BCScore;

	i = j = 0;
	//	loop through each letter in the guess
	//	The player should not be able to earn more Cows or Bulls than the number of characters entered
	while (i < GetWordLength() && i < MGLength){
		if (MyHiddenWord[i] == Guess[i])	//	nth character MUST MATCH
			BCScore.Bulls++;
		else
			while (j < GetWordLength()) {
				if (Guess[i] == MyHiddenWord[j]) {
					BCScore.Cows++;
					break;
				}
				j++;
			}
		j = 0;	//	allows us to catch ANY cows preceding the index of i
		i++;
	}
	//	increment the turn number
	bScore = BCScore.Bulls;
	MyCurrentTry++;
	return BCScore;
}

FString FBullCowGame::PrintGameSummary()
{
	if (IsGameWon())
		return "Congratulations!!!! - You WON!!!\t\n";
	else
		return "Too BAD! - Try again for your soul!\t\n";
}

bool FBullCowGame::IsIsogram(FString s)
{
	int32 i, j = i = 0;
	char tmp;

	//	sort
	while (i < s.length())
	{
		while (j++ < s.length())
		{
			if (s[i] >= s[j])
			{
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
		}
		j = ++i;
	}
	i = j = 0;
	//	compare
	while (i < s.length())
	{
		if (s[i] == s[i + 1])
		{
			return false;
		}
		i++;
	}
	return true;
}

bool FBullCowGame::IsIsogramFast(FString s) const
{
	if (s.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;	//	setup map
	for (char Letter : s)	// for all letters of word "s"	//	range based for loop, standard container (of bytes)
	{
		Letter = ('A' <= Letter && Letter <= 'Z') ? Letter + 32 : Letter;
		if (LetterSeen[Letter])
			return false;
		else {
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
		if (!islower(Letter))
			return false;
	return true;
}

char *FBullCowGame::GetCurrentWord()
{
	return nullptr;
}
