
#pragma once
#include <iostream>
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount{

	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Lenght,
	Not_Lowercase,
};

class Fbullcowgame {
public:

	Fbullcowgame();
	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLenght() const;
	bool IsGameWon() const;
	void Reset(); 
	
	bool CheckWin() const;
	
	EWordStatus CheckGuess(FString) const;

	BullCowCount SubmitGuess(FString);

	bool IsLowercase(FString Word) const;

	bool IsIsogram(FString) const;

private:

	int32 MyCurrentTry;
	int32 MaxTry;
	FString MyHiddenWord;
	bool bGameIsWon;

};