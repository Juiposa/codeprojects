#include <stdio.h>

int main()
{
	char confirm = 'y';
	int player[8]; /*player 0 will be the house*/
	int playerCash[8];
	int numPlayers = 0;
	int card[4][13];
	int cardx, cardy;
	int pot = 0;
	int bigBlind = 0, smallBlind = 0;
	int x = 0, y = 0, z = 0, xx, yy, zz;
	
	
	while ( x == 0 ) {
		
		printf("Welcome to Texas Holdem'!\n");
		
		numPlayers = numberofplayers();
		
		printf("You will be playing with %d players.\n", numPlayers);
		printf("Is this correct? (y/n)\n");
		scanf(" %c", &confirm);
		
		if ( confirm == 'n' ) { /*allows for reentry of number of players*/
			numPlayers = numberofplayers();
		} else {
			printf("Continuing\n");
		}	
		
		printf("What will be players' starting cash? Please enter a value of at least 50\n");
		scanf(" %d", &playerCash[1]);
		
		if( playerCash[1] < 50 ) { /*will check if cash is over 50, if yes, will assign value to other players cash*/
			printf("Value entered is under 50, defaulting to 50.\n");
			xx = 1;
			while ( xx <= numPlayers ) {
				playerCash[xx] = 50;
				xx++;
			}
		} else {
			xx = 2;
			while ( xx <= numPlayers ) {
				playerCash[xx] = playerCash[1];
				xx++;
			}
		}
		
		printf("Each player will have %d cash\n", playerCash[1]);
		
		printf("Please enter what the big and small blinds will be.\n");
		
		bigBlind = blinds( x );
		smallBlind = blinds( y );
		
		printf("Big blind is %d, small blind is %d.\n", bigBlind, smallBlind);
		
	}
}

int numberofplayers( int x ) /*function of number of players to be playing*/
{

	printf("How many people will be playing?\n");

	scanf(" %d", &x);

	if ( x > 8 || x < 2 ) { do { /*read printf*/
		printf("Invalid input. There cannot be more than 8 players and there must be at least 2.\n");
		printf("Make a valid input.\n");
		scanf(" %d", &x);
	} while ( x > 8 || x < 2 ); }
	
return x;
}

	
int blinds ( int x ) /*function; assigning values to the blinds*/
{
	int z = 0;
	
	while ( z == 0 ) {
	
		printf("Big blind:\n");
		scanf(" %d", &x);
		
		printf("Small blind:\n");
		scanf(" %d", &y);
		
		if ( x <= y || x < 0 || y < 0 ) {
			printf("Invalid input\n");
			printf("Big blind MUST be larger than the small blind and both must be positive number.\n");
		} else {
			z = 1;
		}
	}
	
	return x;
	/*return y;*/
}

		
