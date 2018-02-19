#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(){
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

bool FBullCowGame::IsGameWon() const {
	return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString str) const {
	return EWordStatus::OK ; // TODO make actual error
}

// receives a VALID guess, incrementeas turn, returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	MyCurrentTry++;

	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) { // MHWChar, MyHiddenWordChar
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) { // GChar, GuessChar
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
		// compare against hidden word
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString str) {
	return false;
}

void FBullCowGame::Reset(){
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "ant";

	MyHiddenWord = HIDDEN_WORD;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;

	return;
}

