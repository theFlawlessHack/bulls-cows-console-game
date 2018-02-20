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
	} while (bPlayAgain);
	return 0;
}

void PrintIntro() {
	// introduce game
	std::cout << "\nWelcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl << std::endl;

	return;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking for guesses while the game is NOT won and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		
		FText Guess = GetValidGuess(); 
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl << std::endl;
	}

	PrintGameSummary();

	return;
}

// loop until a valid guess is given
FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess;

	do {
		std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";

		// get a guess from the player
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
			break;
		}
		std::cout << std::endl;
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