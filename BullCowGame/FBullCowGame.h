/*
Created by Jessica Joseph

This is the header class of the BullsCowsGame.
The Bulls Cows Game is a word game where users guess the X letter isogram.
*/

#include <string>
#include <map>

#define TMap std::map

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	
	FBullCowGame();

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const; 
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	void Reset();

	FBullCowCount SubmitValidGuess(FString Guess);

private:
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};