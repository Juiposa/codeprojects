/*******************************************************************
enigma.c
Jeffrey-David Kapp

created 
25/11/2013

last modified
25/11/2013

Version: 0.1

Creating a text based emulator of a Nazi German Enigma Code machine.
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*string maxsize*/
#define MAXSIZE 100

/*rotor strings*/
#define ROTORI "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
#define ROTORII "AJDKSIRUXBLHWTMCQGZNPYFVOE"
#define ROTORIII "BDFHJLCPRTXVZNYEIWGAKMUSQO"
#define ROTORIV "ESOVPZJAYQUIRHXLNFTGKDCMWB"
#define ROTORV "VZBRGITYUPSDNHLXAWMJQOFECK"


int masterMenu( char userName[MAXSIZE] );




int main()
{
	/*******************
	variable declaration
	********************/

	char userName[MAXSIZE]; 

	/*exit menu vars*/
	char exitMenuStr[MAXSIZE];
	int exitMenuStatus = 0;

	/*loop var*/
	x = 0;

	while ( x = 0 ) { /*master loop*/


		printf("Welcome to a very crude rendition of an Enigma machine.\n");

		printf("To begin, what is is your name?");

		fgets( userName, MAXSIZE, stdin ); /*getting the user's name*/

		printf("Hello %s.\n", userName);

		exitMenuStatus = masterMenu( userName );

		switch ( exitMenuStatus ) {
			case 2: /*case wherein the user will have chosen to exit while in masterMenu*/
				exit();
				break;
			case 1: /*case where the user chooses to restart in masterMenu*/
				break; /*will simply trigger the next iteration of the master loop*/
			case 0: /*natural end of masterMenu is reached, outputs the standard exit menu*/

				printf("What would you like to do?\n");
				printf("Exit (x)\nRestart (r)\n");

				do { /*valid input loop*/

					fgets( exitMenuStr, MAXSIZE, stdin ); /*getting user input*/

					if ( exitMenuStr[0] != 'x' && exitMenuStr[0] != 'r' ) { /*checking that the user has given a valid input*/
						printf("Invalid input, please enter x or r.\n");
					}

					if ( strlen(exitMenuStr) != 2 ) { /*if user has inputted more than one character*/
						printf("Please enter only one character.\n");
					}

				} while ( exitMenuStr[0] != 'x' && exitMenuStr != 'r' && strlen(exitMenuStr) != 2 );

				switch ( exitMenuStr[0] ) {
					case 'r': 
						printf("Restarting.\n");
						break;
					case 'x':
						printf("Exiting.\n");
						break;

				}

				break;
		}
	}

	return 0;

}

int masterMenu( char userName[MAXSIZE] )
{

}