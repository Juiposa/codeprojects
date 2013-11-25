#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXSIZE 100

int menu(); 

int jackpotInput();

int * numbersInput( int whichNumber );

int commonNumbersCalc( int winningNumbers[6], int playerNumbers[6] );

float winningsPercCalc( int commonNumbers );

float winningsCalc( int jackpot , float winningsPerc );

int main()
{

	char playerName[MAXSIZE]; /*player's name*/

	char exitMenu[2]; /*controls the menu that will terminate the program if the user so chooses*/
	int exitMenuStatus; /*return value from menu, will determine what is outputted to user for the exit menu*/

	int x = 0; /*master loop var*/

	while ( x == 0 ) { /*master loop*/

		printf("Welcome to the Lotto 6/49\n");

		printf("Please enter your name.\n");

		fgets( playerName, MAXSIZE, stdin );

		printf("Welcome %s.\n", playerName );

		exitMenuStatus = menu(); /*after this call, the program will navigate the functions, and only return for the end of the program.*/

		switch ( exitMenuStatus ) { /*will use returned value to output apporiate text to user*/
			case 0: /*case where user will operate through the program to its natural end*/
				printf("Would you like to replay?\n");
				printf("Replay (r)\nExit (x)\n");
				break;
			case 1: /*case where user chooses to exit in menu(), will default exitMenu to 'x'*/
				exitMenu[0] = 'x';
				break;
			case 2: /*case where user chooses to restart in menu(), will default exitMenu to 'r'*/
				exitMenu[0] = 'r';
				break;
		}

		while ( exitMenuStatus == 0 ) { /* will only evalute if menu returned naturally*/
			
			do { /*valid input loop*/

				fgets( exitMenu, 2, stdin );
				
				printf("%c\n", exitMenu[0] );

				if ( exitMenu[0] != 'r' && exitMenu[0] != 'x' ) {
					printf("Invalid input. Enter only 'r' or 'x'.\n");
				}

			} while( exitMenu[0] != 'r' && exitMenu[0] != 'x' ); /*will loop until exitMenu is one of these two values*/ 
		}

		switch (exitMenu[0]) {
			case 'x': /*exit option; will terminate the program*/
				printf("Thank you for playing.\n");
				exit(0);
				break;
			case 'r':  /*restart option; will perpetuate the loop*/
				printf("Restarting.\n");
				printf("Thank you for playing.\n");
				break;
		}
		
	}

	return 0;

}


int menu() 
{

	char menuSelctStr[MAXSIZE]; /*menu selection operator*//*using string to handle input of multiple characters at once to avoid multiple errors*/
	char menuSelctChar; /*will put value in here once a valid input is reahced*/
	int numbersStatus[2] = { 0, 0 }; /*will track if both the winning and player numbers have been inputted*/
	int * playerNumbers; /*the users lotto numbers*/
	int * winningNumbers; /*the winning lotto numbers*/
	int jackpot = 0; /*the jackpot pool, amount of money available as winnings*/
	int commonNumbers = 0; /*how many number match between each array*/
	float winningsPerc = 0.0; /*percentage of the jackpot the user has won*/ 
	float winnings = 0.0; /*users winnings*/

	int x = 0, y = 0; /*misc loop vars*/

	while ( x == 0 ) { /*master function loop*/

		printf("Please choose an option.\n");
		printf("Enter jackpot (q)\nEnter winning numbers (w)\nEnter your numbers (e)\n");
		printf("Calculate your winnings (r)\nExit (x)\nRestart (c)\n");

		do { /*valid input loop*/

			fgets( menuSelctStr, MAXSIZE, stdin );

			/*this if statement will check if the inputted value if valid, and put into menuSelctChar when it is*/
			/*yes it is ugly, and yes it is long, but it works*/
			if ( menuSelctStr[0] != 'q' && menuSelctStr[0] != 'w' && menuSelctStr[0] != 'e' && menuSelctStr[0] != 'r' && menuSelctStr[0] != 'x' && menuSelctStr[0] != 'c' ) {
				
				printf("Invalid input.\n");

			} else if ( !( strlen( menuSelctStr ) == 2 ) ) { /*will prompt user if more than one character has been inputted*/
				
				printf("Please only enter one character\n");
			
			} else {
			
				menuSelctChar = menuSelctStr[0]; /*puts the first and only character of a valid input into the control var*/
				y = 1; /*will terminate the loop*/
			
			}

		} while ( y == 0 ); 
		


		switch ( menuSelctChar ) { /*master menu control switch*/
			case 'q':
				jackpot = jackpotInput();
				break; /*calling for user to input the jackpot*/
			case 'w': /*for user to input the winnings numbers*/
				printf("Please enter the winning numbers.\n");
				winningNumbers = numbersInput( 1 ); /*sending 1 to tell function what static variable to store value in*/
				numbersStatus[0] = 1; /*indicating that the winnings numbers have been inputted*/
				break;
			case 'e': /*for user to input their numbers*/
				printf("Please enter your numbers.\n");
				playerNumbers = numbersInput( 0 ); /*sending 0 to tell function what static variable to store value in*/
				numbersStatus[1] = 1; /*indicating that the player's numbers have been inputted*/
				break;
			case 'r':
				if ( numbersStatus[1] == 1 && numbersStatus[0] == 1 && jackpot != 0 ) { /*will only execute if both sets of number have been inputted*/
				
					commonNumbers = commonNumbersCalc( winningNumbers, playerNumbers ); /*calcualtion of how many common numbers there are*/
					winningsPerc = winningsPercCalc( commonNumbers ); /*determination of how much in percentage the user has won*/
					winnings = winningsCalc( jackpot, winningsPerc ); /*final calculation of the winnings*/
					x = 1; /*termination of the masterloop*/

				} else {
					printf("Please enter both your number and the winnings numbers and the jackpot before proceeding.\n");
				}

				break; 
			case 'x': 
				return 1; 
				break; /*exit; returns value to main to have it fast track to termination*/
			case 'c': 
				return 2; 
				break; /*restart: returns value to main to have it fast track through restarting*/
			
		}
	}

	printf("You have won $%.2f.\n", winnings );

	return 0; /*natural end of the function*/

}


/*function will take users input for the jackpot's value and check for validity*/
int jackpotInput() 
{
	int jackpot = 0; /*function specific variable for the pool*/
	char jackpotStr[MAXSIZE]; /*for checking for invalid input*/
	char validityChar; /*used to check for valid input*/

	int x = 0, y = 0; /*misc loop vars*/

	while ( x == 0 ) { /*master loop, will loop until input is valid*/

		fgets( jackpotStr, MAXSIZE, stdin ); /*grabbing users input*/

		validityChar = jackpotStr[y]; /*assigning the first value of jackpotStr to the char*/

		/*if validityChar is a digit and not a null terminator or return key, and y hasn't exceeded MAXSIZE*/
		while ( y < MAXSIZE && isdigit(validityChar) && validityChar != '\n' && validityChar != '\0' ) { 

			y++;

			validityChar = jackpotStr[y];

		}

		if ( y + 1 < strlen( jackpotStr ) ) { /*if there are fewer digits in the string than the strings length*/

			printf("Invalid input. Jackpot must be a positive integer.\n");

		} else { /*terminate loop if everything is good*/
			x = 1;
		}

	}

	jackpot = atoi( jackpotStr );

	return jackpot;

}

/*will accept user input for either winning or their numbers*/
int * numbersInput( int whichNumber )
{
	int numbers[6];
	
	/*value of the numbers will stay local to this function and a pointer to these values will be passed back*/
	static int playerNumbers[6];
	static int winningNumbers[6];

	char numberStr[MAXSIZE]; /*to be used to avoid multiple error messages*/
	int x = 0, y = 0, z = 0; /*loop vars*/

	for ( x = 0; x <= 5; x++ ) { /*loop 6 time to accept 6 inputs*/

		y = 0;

		printf("Number %d\n", x + 1 );

		while ( y == 0 ) {

			fgets( numberStr, MAXSIZE, stdin );

			if ( !( atoi( numberStr ) >= 1 && atoi( numberStr ) <= 49 ) ) { /*if the inputted value is between 1 and 49*/
				printf("Invalid input. Please enter a number between 1 and 49.\n");
			} else {
				numbers[x] = atoi( numberStr ); /*assigning value of string to array place if valid*/
				y = 1; /*loop termination*/
			}
		}
	}
	if ( whichNumber == 1 ) { /*value from main telling the function what variable to return to the pointer*/

		for ( z = 0; z <= 5; z++ ) { /*assigning value of numbers to playernumbers*/

			playerNumbers[z] = numbers[z];

		}
		
		return playerNumbers;

	} else if ( whichNumber == 0 ) {

		for ( z = 0; z <= 5; z++ ) { /*ditto*/

			winningNumbers[z] = numbers[z];

		}

		return winningNumbers;

	}

	return 0;
}

int commonNumbersCalc( int winningNumbers[6], int playerNumbers[6] )
{

	int commonNumbers = 0; /*numbers shared between the two arrays*/
	int x = 0; /*loop var*/

	for ( x = 0; x <= 5; x++ ) { /*will compare the two arrays to check for equivalent values*/

		if ( winningNumbers[x] == playerNumbers [x] ) {
			commonNumbers++;
		}

	}

	return commonNumbers;

}

float winningsPercCalc( int commonNumbers )
{

	float winningsPerc = 0.0;

	switch ( commonNumbers ) {
		case 0:
		case 1: /*none or one common number results in no winnings*/
			winningsPerc = 0.0;
			break;
		case 2: 
			winningsPerc = 3.0; /*3 as in the integer, numbers above 1 will be treated as cash prizes as opposed to percentages*/
			break;
		case 3:
			winningsPerc = 10.0; /*10 dollar prize*/
			break;
		case 4:
			winningsPerc = 0.095; /*9.5% prize*/
			break;
		case 5:
			winningsPerc = 0.05; /*5% prize*/
			break;
		case 6:
			winningsPerc = 0.795; /*79.5% prize*/
			break;
	}

	return winningsPerc;

}

float winningsCalc( int jackpot, float winningsPerc )
{
	
	float winnings = 0; /*winnings as determined by common numbers and the size of the jackpot*/

	if ( winningsPerc <= 1 && winningsPerc > 0 ) { /*will calculate winnings only if it is not a cash prize or no prize*/

		winnings = (float)jackpot * winningsPerc; /*jackpot total times the percentage the user gets*/
	
	} else {
	
		winnings = winningsPerc; /*will assign a cash prize or no prize value to the winnings*/
	
	}

	return winnings;

}