/*
Created by Jessica Joseph

This is the console executable that makes use of the BullCow class.
This acts as the view in the MVC pattern, and is responsible for all user interaction.
For game logic see the FBullCowGame class.

This project follows the Unreal C++ Coding style.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
void PrintGameSummary();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game


int main() {
	bool bPlayAgain = false;

	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
		std::cout << std::endl;
	} while (bPlayAgain);
	return 0;
}

void PrintIntro() {
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "           }    {           ___" << std::endl;
	std::cout << "           (o o)           (o o)" << std::endl;
	std::cout << "  /---------\\ /             \\ /--------\\" << std::endl;
	std::cout << " / |  BULL  |O               O|  COW  | \\" << std::endl;
	std::cout << "*  |-,----- |                 | ------|  *" << std::endl;
	std::cout << "   ^        ^                 ^       ^" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl << std::endl;

	return;
}

// plays a single game to completion
void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		
		FText Guess = GetValidGuess(); 
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl << std::endl;
	}

	PrintGameSummary();

	return;
}

FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess;

	do {
		std::cout << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries()<< ". Enter your guess: ";

		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " lettter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n\n";
			break;
		default:
			break;
		}
	} while (Status != EGuessStatus::OK);
	return Guess;

}

void PrintGameSummary() {
	if (BCGame.IsGameWon() ) {
		std::cout << "#YASS. WINNER!! WELL DONE.";
	}
	else {
		std::cout << "Better luck next time.";
	}

	std::cout << std::endl;
}

bool AskToPlayAgain() {

	std::cout << "Do you want to play again with the same hidden word? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}