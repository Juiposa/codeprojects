#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 100

int mainMenu();

void valueInput();

float ratioandunits_Determination();

void conversion( float ratio );

struct inputData { /*data inputted by user to be converted to another unit*/

	char wholeStr[MAXSIZE];
	float value;
	char unit[3];

};

struct outputData { /*variables where the converted values will be stored*/

	float value;
	char unit[3];

};

int main()
{

	int exitStatus = 0; /*exit condition, controlling how the program will terminate, if at all*/
	 
	int x = 0; /*master loop var*/

	while ( x == 0 ) { /*master loop, will never terminate*/

		exitStatus = mainMenu();

		switch ( exitStatus ) {

			case 0: break; /*user chose to restart in the function, will allow loop to continue to next iteration*/
			case 1: exit(); break; /*user chose to exit in function, will terminate the program*/

		}

	}

	return 0;

}

/*main menu of the program, will provide instruction to user and pass info to the other functions*/

int mainMenu()
{



}

void valueInput()
{

}

float ratioandunits_Determination()
{

}

void conversion( float ratio )
{

}











