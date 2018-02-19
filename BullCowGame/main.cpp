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
void PrintGuess(FText &Guess);
FText GetGuess();
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
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl;

	return;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	std::cout << MaxTries << std::endl;

	// TODO change from FOR to WHILE loop
	for (int32 i = 0; i < MaxTries; i++) {
		FText Guess = GetGuess(); // make looop checking valid

		// submit valid guess to the game
		// print # of bulls and cows
		PrintGuess(Guess);
	}
}

FText GetGuess() {

	std::cout << "Try " << BCGame.GetCurrentTry() <<". Enter your guess: ";
	BCGame.increaseCurrentTry();

	// get a guess from the player
	FText Guess;
	std::getline(std::cin, Guess);

	return Guess;
}

void PrintGuess(FText &Guess)
{
	// repeat guess back to the player
	std::cout << "Your guess was: " << Guess << std::endl << std::endl;
}

bool AskToPlayAgain() {

	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}