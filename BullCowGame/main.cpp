#include <iostream>
#include <string>
#include "FBullCowGame.h"



void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl;

	return;
}

void PlayGame() {
	int MaxTries = BCGame.GetMaxTries();

	std::cout << MaxTries << std::endl;

	for (int i = 0; i < MaxTries; i++) {
		std::string Guess = GetGuess();
		PrintGuess(Guess);
	}
}

std::string GetGuess() {

	std::cout << "Enter your guess: ";

	// get a guess from the player
	std::string Guess;
	std::getline(std::cin, Guess);

	return Guess;
}

void PrintGuess(std::string &Guess)
{
	// repeat guess back to the player
	std::cout << "Your guess was: " << Guess << std::endl << std::endl;
}

bool AskToPlayAgain() {

	std::cout << "Do you want to play again? (y/n) ";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}