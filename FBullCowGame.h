/* The game logic (no view code or direct user interaction)
The game is a simple guess the word game based on Mastermind
Header file for the FBullCowGame class. Provides the 
framework for the variables and functions
*/

#pragma once
#include <string>

// unreal friendly interface
using FString = std::string;
using int32 = int;

// all values initialized to 0
struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus 
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
};

class FBullCowGame {
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);


// variables stay private
private:
	// see constructor for initialization
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	// helper methods
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};
