// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "time.h"
#include <iostream>
#include <ctype.h>

int selectDifficulty();
int generateRand(int numberRange);
void higherLower(int randNumber, int guessNumber, bool playerCharacter);

int main()
{

	int inputNumber = 0; // user input guess number
	int guessesLeft = 5; // lives remaining (starts at 5)
	int remainingGuesses;
	int numberRange;
	char characterTest;

	int randomisedNumber = 0; // Randomly generated number
	bool stillGuesssing = true; // Guess boolean
	bool playerCharacter = true;

	system("CLS");

	numberRange = selectDifficulty();
	
	randomisedNumber = generateRand(numberRange);

	std::cout << "\n Guess a number between 1 and " << numberRange << "\n";
	while (stillGuesssing && (guessesLeft > 0) || inputNumber < 0 || inputNumber > numberRange)
	{
		if(!(std::cin >> inputNumber))
		{
			std::cout << " Invalid input please enter an integer between 1 and " << numberRange << "\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			if (inputNumber == randomisedNumber)
			{
				stillGuesssing = false;
				remainingGuesses = guessesLeft;
				guessesLeft = 0;
			}
			else
			{
				guessesLeft--;
				std::cout << " Number of guesses remaining: " << guessesLeft << "\n";
			}
		}
		
	}

	system("CLS");

	if (!stillGuesssing)
	{
		std::cout << " You won with " << remainingGuesses << " left!" << "\n";
	}
	else
	{
		std::cout << " You failed, the number was " << randomisedNumber << "\n";
	}


	system("pause");

    return 0;
}

int selectDifficulty()
{

	while (true)
	{
		int tempNumber;
		std::cout << "Select the range you have to guess : \n";
		std::cout << "1. Easy : 50 \n";
		std::cout << "2. Normal : 100 \n";
		std::cout << "3. Hard : 150 \n";
		if (!(std::cin >> tempNumber) || tempNumber < 0 || tempNumber > 3)
		{
			std::cout << " Invalid input please enter an integer between 1 and 3 \n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			return tempNumber * 50;
		}
	}
}

int generateRand(int numberRange)
{
	srand(time(NULL));
	
	return rand() % numberRange + 1; // +1 to make min 1 to numberRange
}

void higherLower(int randNumber, int guessNumber, bool playerCharacter)
{

}

