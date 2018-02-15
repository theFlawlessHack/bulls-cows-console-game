#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

void PrintGuess(std::string &Guess);

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
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << endl;

	return;
}

void PlayGame() {

	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 0; i < NUMBER_OF_TURNS; i++) {
		string Guess = GetGuess();
		PrintGuess(Guess);
	}
}

string GetGuess() {

	cout << "Enter your guess: ";

	// get a guess from the player
	string Guess;
	getline(cin, Guess);

	return Guess;
}

void PrintGuess(std::string &Guess)
{
	// repeat guess back to the player
	cout << "Your guess was: " << Guess << endl << endl;
}

bool AskToPlayAgain() {

	cout << "Do you want to play again? (y/n) ";
	string Response = "";
	getline(cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}