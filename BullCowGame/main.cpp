/*
Created by Jessica Joseph

This is the console executable that makes use of the BullCow class.
This acts as the view in the MVC pattern, and is responsible for all user interaction.
For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game


int main() {
	bool bPlayAgain = false;

	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}

void PrintIntro() {
	// introduce game
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl << std::endl;

	return;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// TODO change from FOR to WHILE loop
	for (int32 i = 0; i < MaxTries; i++) {
		FText Guess = GetValidGuess(); // make looop checking valid

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl << std::endl;
	}
}

// loop until a valid guess is given
FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid_Status;

	do {
		std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";

		// get a guess from the player
		FText Guess;
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " lettter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
}


bool AskToPlayAgain() {

	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}