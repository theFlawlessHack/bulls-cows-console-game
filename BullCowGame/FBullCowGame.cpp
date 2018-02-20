#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const { 
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,5}, {5,7}, {6,13}, {7,17} };
	return WordLengthToMaxTries[MyHiddenWord.length()]; 
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else if (!IsIsogram(Guess)) {
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) {
		return EGuessStatus::Not_Lowercase;
	} else {
		return EGuessStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
	MyCurrentTry++;

	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); 

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) { // MHWChar, MyHiddenWordChar
		for (int32 GChar = 0; GChar < WordLength; GChar++) { // GChar, GuessChar
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}

	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}


void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet"; // must be an isogram

	bGameIsWon = false;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;

	return;
}

// Helper functions
bool FBullCowGame::IsIsogram(FString Word) const {

	if (Word.length() <= 1) { return true; }
	
	TMap<char, bool> LetterSeen;

	for (auto Letter : Word) {
		Letter = tolower(Letter);

		if (LetterSeen[Letter]) {
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const {
	for (auto Letter : Word) {
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}
