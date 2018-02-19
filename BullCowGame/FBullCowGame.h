#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	
	FBullCowGame();

	bool IsGameWon() const;
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;

	void increaseCurrentTry();
	bool CheckGuessValidity(FString str); // TODO: make a more rich return value.
	void Reset(); // TODO: make a more rich return value
	// bulls and cows counting method

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	bool IsIsogram(FString str);
};