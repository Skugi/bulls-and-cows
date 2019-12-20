
#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "Fbullcowgame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetValidGuess();
void PlayGame();
bool AskToPlay();

Fbullcowgame BCGame;

int main()
{

	std::cout << BCGame.GetCurrentTry();
	
	bool bPlayAgain = false;
	do {

		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlay();
	} while (bPlayAgain);

	return 0;
	

}

void PlayGame() {

	BCGame.Reset();
	int32 MaxTries = 8;

	for (int32 i = 1; i <= MaxTries; i++) {
		FText Guess = GetValidGuess();

		BullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}


}

void PrintIntro() {

	constexpr int32 WORLD_LENGHT = 5;
	std::cout << "Bulls and Cows - The game\n";
	std::cout << "Guess the word that is " << BCGame.GetHiddenWordLenght();
	std::cout << " letters long\n";
	std::cout << std::endl;
	return;
}

FText GetValidGuess() {

	int32 MaxTry = BCGame.GetMaxTries();
	FText Guess = "";
	EWordStatus Status = EWordStatus::Invalid_Status;
	do
	{
		int32 MyCurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << MyCurrentTry << " . Enter your guess";
		
		std::getline(std::cin, Guess);
	
		Status = BCGame.CheckGuess(Guess);
		switch (Status)
		{
		case EWordStatus::Wrong_Lenght:
			std::cout << "Enter a " << BCGame.GetHiddenWordLenght() << " letter word.\n";
			break;
		case EWordStatus::Not_Isogram:
			std::cout << "Letters in word cannot reapet.\n";
			break;
		case EWordStatus::Not_Lowercase:
			std::cout << "Word shouldn't include any capital letter.\n";
			break;
		default:
			break;
		}
		
	} while (Status != EWordStatus::OK);
	return Guess;

}

bool AskToPlay() {
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);

	std::cout << "Is it y?:" << (Response[0] == 'y');
	std::cout << std::endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');
	
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Congratulations, You Win!\n";
	}
	else
	{
		std::cout << "Come back in ten years\n";
	}
};
