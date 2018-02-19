#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(){
	Reset();
}

int FBullCowGame::GetCurrentTry() const {
	return MyCurrentTry;
}

int FBullCowGame::GetMaxTries() const {
	return MyMaxTries;
}


bool FBullCowGame::IsGameWon() const {
	return false;
}


void FBullCowGame::increaseCurrentTry() {
	MyCurrentTry += 1;
}


bool FBullCowGame::CheckGuessValidity(std::string str) {
	return false;
}

bool FBullCowGame::IsIsogram(std::string str) {
	return false;
}

void FBullCowGame::Reset(){
	MyCurrentTry = 1;
	MyMaxTries = 8;

	return;
}

