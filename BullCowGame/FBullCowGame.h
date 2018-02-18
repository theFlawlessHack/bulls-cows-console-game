#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(); // TODO: make a more rich return value
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string str); // TODO: make a more rich return value.

private:
	int MyCurrentTry;
	int MyMaxTries = 5;
	bool IsIsogram(std::string str);
};