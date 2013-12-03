/*******************************************************************
enigma.c
Jeffrey-David Kapp

created 
25/11/2013

last modified
26/11/2013

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
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ROTORI "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
#define ROTORII "AJDKSIRUXBLHWTMCQGZNPYFVOE"
#define ROTORIII "BDFHJLCPRTXVZNYEIWGAKMUSQO"
#define ROTORIV "ESOVPZJAYQUIRHXLNFTGKDCMWB"
#define ROTORV "VZBRGITYUPSDNHLXAWMJQOFECK"


int masterMenu( char userName[MAXSIZE] );

char * stringGet();

char * encoding( char inputString[MAXSIZE] );

char charExchangeRotor( char char_ );

char charExchangeReflector( char char_ );

char charExchangeSwitchBoard( char char_ );

int * rotorPositionSet();

typedef struct rotorSettings { /*the rotors setting, postions and what slots the user chooses to put them in*/
	int postion[3], slot[3];
	char name[MAXSIZE];
}rtrset;

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

				} while ( exitMenuStr[0] != 'x' && exitMenuStr != 'r' && strlen(exitMenuStr) != 2 ); /*if the inputted value is not one of the two valid inputs and more than one character has been inputted*/

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

/*master control function, holds master menu and program will mainly work from this function*/
int masterMenu( char userName[MAXSIZE] )
{
	
	/*****************
	function variables
	*****************/

	/*menu control related variables*/
	char menuControlStr[MAXSIZE];
	int menuStatus;

	/*input and returned strings*/
	char inputString[MAXSIZE]; /*string to be returned from stringGet fucntion*/
	char encodedString[MAXSIZE]; /*string that will returned after each char has been encoded*/

	/*rotor and switch board settings*/
	/*arrays returned from their respective function*/
	int * rotorPositions;
	int * switchboardSettings;

	/*loop vars and misc operators*/
	int x = 0, y = 0, z = 0;



}

/*will get the string the user will wish to encode*/
char * stringGet()
{
	/*****************
	function variables
	*****************/

	/*user inputted string*/
	static char inputString[MAXSIZE];

	/*loop vars and misc operators*/
	int x = 0, y = 0, z = 0;



}

/*function that will trigger the encoding/decoding process*/
char * encoding( char inputString[MAXSIZE], int * rotorPositions )
{

	/*****************
	function variables
	*****************/

	/*string to be built from coding functions and returned*/
	char encodedString[MAXSIZE];

	/*char to be passed to exchaning functions*/
	char char_;
	char tempChar;


	/*loop vars and misc operators*/
	int x = 0, y = 0, z = 0;


}

/*exchanging individual characters through the three rotors*/
char charExchangeRotor( char char_, int direction, int * rotorPositions )
{
	/*****************
	function variables
	*****************/

	/*rotor settings*/
	rotorPostion[3]; /*will hold what postion the user 
	whichRotor[3];
	
}

/*exchanging the character through the rotor placed as the reflector*/
char charExchangeReflector( char char_ )
{

}

/*exchaning the character through the switch board based on how the users sets it*/
char charExchangeSwitchBoard( char char_ )
{

}

/*setting the rotor to be placed in the slot and the position to set it to*/
int * rotorPositionSet()
{

}

/*setting the 13 positions of the switchboard*/
int * switchBoardSet()
{

}