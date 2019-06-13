/* This is the console executable, that makes use of the BullCow Class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#pragma once
#include <iostream>	//preprocessor directive (build->pastes)
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // instantiate a new game

// the entry point for our application: (Abstractions) << applied (Encapsulation)
int main() 
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0; // exit the application
}


void PrintIntro() 
{

	// introduce the game
	std::cout << "\nWelcome to Bulls and Cows, an exciting word game\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << "          {} {}    o   o    \n";
	std::cout << "          (0 0)    (0 0)       \n";
	std::cout << "      _____\\ /     \\ /_____     \n";
	std::cout << "    ~(       )     (        )~      \n";
	std::cout << "     (_______)     (________)    \n";
	std::cout << "     |_|_' |_|_   _|_|  _|_|  \n\n";
	return;
}

// plays a single game to completion
void PlayGame() 
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries(); 

	// loop through guesses while game is NOT won
	// and there are still tries remaining
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();

		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();
	return;
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Enter your Guess : ";
		getline(std::cin, Guess);

		//check status and give feedback
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)	{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word with no repeating letters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter an all lowercase word.\n\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK); // keep looping until we get no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "\nWould you like to play again with the same word (y/n)? \n";
	FText Answer = "";
	getline(std::cin, Answer);

	return (Answer[0] == 'y') || (Answer[0] == 'Y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "Congratulation YOU WIN!";
	}
	else
	{
		std::cout << "Better Luck Next Time";
	}
	return;
}

/*
int ChooseHiddenWord()
{
	std::cout << "\nPlease choose a number from 1-5 to select a hidden word. \n";
	FText Choice = 0;
	getline(std::cin, Choice);
	return std::stoi(Choice);
}
*/
