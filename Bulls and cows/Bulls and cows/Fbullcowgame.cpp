
#pragma once
#include "pch.h"
#include "Fbullcowgame.h"
#include <string>
#include <iostream>
#include <map>
#define TMap std::map

using int32 = int;
Fbullcowgame::Fbullcowgame()
{
	Reset();
}


int32 Fbullcowgame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3,4},{4,7},{5,10}, {6,15}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}
bool Fbullcowgame::IsGameWon()const { return bGameIsWon; }

int32 Fbullcowgame::GetCurrentTry()const
{
	return MyCurrentTry ;
}

int32 Fbullcowgame::GetHiddenWordLenght() const
{
	return MyHiddenWord.length();
}




void Fbullcowgame::Reset()
{
	const FString HIDDEN_WORD = "donkey";//must be an isogram
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;

	return;


	//constexpr int32 MAX_TRIES = 8;

	//MaxTry = MAX_TRIES;

	//const FString HIDEN_WORD = "donkey";
	//MyHiddenWord = HIDEN_WORD;

	//return;
}

bool Fbullcowgame::CheckWin()const
{
	return false;
}


EWordStatus Fbullcowgame::CheckGuess(FString Guess) const
{
	if (!IsIsogram(Guess)) {
		return EWordStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) {
		return EWordStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLenght()) {
		return EWordStatus::Wrong_Lenght;
	}
	else 
	{
		return EWordStatus::OK;
	}
	
}

BullCowCount Fbullcowgame::SubmitGuess(FString Guess)
{

	MyCurrentTry++;

	BullCowCount BullCowCount;

	int32 HiddenWordLenght = MyHiddenWord.length();

	for (int32 MyChar = 0; MyChar < HiddenWordLenght; MyChar++) {
		for (int32 GuessChar = 0; GuessChar < HiddenWordLenght; GuessChar++) {
			if (Guess[GuessChar] == MyHiddenWord[MyChar]) {
				if (MyChar == GuessChar) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == HiddenWordLenght)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}

	return BullCowCount;
}





bool Fbullcowgame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}

	}

	return true;
}
bool Fbullcowgame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}




