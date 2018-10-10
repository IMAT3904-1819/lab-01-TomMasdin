// Lab1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "time.h"
#include <iostream>
#include <ctype.h>
#include <ctime>

int selectDifficulty();
int generateRand(int maxRange, int minRange);
int higherLower(int randNumber, int guessNumber, bool playerCharacter);
int numberRange;

int main()
{

	int inputNumber = 0; // user input guess number
	int guessesLeft = 5; // lives remaining (starts at 5)
	int remainingGuesses;
	char characterTest;

	int randomisedNumber = 0; // Randomly generated number
	bool stillGuesssing = true; // Guess boolean
	bool playerCharacter = false; // If AI or Player
	srand(time(NULL));

	system("CLS");

	numberRange = selectDifficulty();
	randomisedNumber = generateRand(numberRange, 1);

	
	if (playerCharacter)
	{
		std::cout << "\n Guess a number between 1 and " << numberRange << "\n";
		while (stillGuesssing && (guessesLeft > 0))
		{
			if (!(std::cin >> inputNumber) || inputNumber < 0 || inputNumber > numberRange)
			{
				std::cout << " \n Invalid input please enter an integer between 1 and " << numberRange << "\n";
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
					higherLower(randomisedNumber, inputNumber, playerCharacter);
					guessesLeft--;
					std::cout << " \n Number of guesses remaining: " << guessesLeft << "\n";
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
	}
	else
	{
		std::cout << "\n Enter an interger between 1 and " << numberRange << "\n";
		if (!(std::cin >> inputNumber) || inputNumber < 0 || inputNumber > numberRange)
		{
			std::cout << " \n Invalid input please enter an integer between 1 and " << numberRange << "\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		while (stillGuesssing && (guessesLeft > 0))
		{

			if (randomisedNumber == inputNumber)
			{
				stillGuesssing = false;
				remainingGuesses = guessesLeft;
				guessesLeft = 0;
			}
			else
			{
				randomisedNumber = higherLower(randomisedNumber, inputNumber, playerCharacter);
				guessesLeft--;
				std::cout << "AI guessed: " << randomisedNumber << "\n";
				std::cout << " \n Number of guesses remaining: " << guessesLeft << "\n";
				
				
			}
		}

		//system("CLS");

		if (!stillGuesssing)
		{
			std::cout << " The AI " << remainingGuesses << " left!" << "\n";
		}
		else
		{
			std::cout << " The AI failed to guess " << inputNumber << "\n";
		}
		
	}


	system("pause");

    return 0;
}

int selectDifficulty()
{

	while (true)
	{
		int tempNumber;
		std::cout << " \n Select the range you have to guess : \n";
		std::cout << "1. Easy : 50 \n";
		std::cout << "2. Normal : 100 \n";
		std::cout << "3. Hard : 150 \n";
		if (!(std::cin >> tempNumber) || tempNumber < 0 || tempNumber > 3)
		{
			std::cout << " \n Invalid input please enter an integer between 1 and 3 \n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			return tempNumber * 50;
		}
	}
}

int generateRand(int maxRange, int minRange)
{
	return rand() % (maxRange - minRange + 1) + minRange; // +1 to make min 1 to numberRange
}

int higherLower(int randNumber, int guessNumber, bool playerCharacter)
{
	if (playerCharacter)
	{
		if (randNumber > guessNumber)
		{
			std::cout << "Guess Higher!" << std::endl;
			if (randNumber - guessNumber <= 10)
			{
				std::cout << "It's within 10 away!" << std::endl;
			}
		}
		else
		{
			std::cout << "Guess Lower!" << std::endl;
			if (guessNumber - randNumber <= 10)
			{
				std::cout << "It's within 10 away!" << std::endl;
			}
		}
	}
	else
	{
		if (randNumber > guessNumber)
		{
			if (guessNumber - randNumber <= 10)
			{
				return generateRand(randNumber + 10, randNumber);
			}
			return generateRand(numberRange, randNumber);
		}
		else
		{
			if (randNumber - guessNumber <= 10)
			{
				return generateRand(randNumber, randNumber - 10);
			}
			return generateRand(randNumber, 1);
		}
	}

	return 0;
}

