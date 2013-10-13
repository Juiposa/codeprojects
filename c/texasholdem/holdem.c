/**********************************************
holdem.c
A text based game of Texas Hold 'em
coded by Jeffrey-David Kapp
created on 7/10/2013
last modified on 12/10/2013
***********************************************/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int numberofplayers();

int dealing();

/*master variables; ones that will be excahnging between functions quite a bit*/
int card[4][13]; /*card status tracking*/
int cardSuit, cardNum; /*x y coors to be used in 2D array for former var*/ 
int dealer = 1; /*will determine who is dealer, and who posts the blinds*/
int playerStatus[8]; /*will be used to track status of the player's hand*/
int player[8]; 
int playerCash[8]; /*tracking of player's available cash*/
int tableBet; /*highest bet that must be matched on the table*/
int playerBet; /*the bet a player makes, whether it be mathcing or rasing*/
int numPlayers = 0; /*number of player who will be playing*/

int main()
{
	char confirm = 'y'; /*user input var, controls start or end of master loop*/
	char num[6], suit[9]; /*string vars to hold names of suits and royal cards*/
	char menu = 'n', menu2 = 'n'; /*menu selection variables*/
	int pot = 0; /*value of the pot*/
	int bigBlind = 0, smallBlind = 0; /*values user will input to set big and small blinds*/
	int x = 0, y = 0, z = 0, xx = 0, yy = 0, zz = 0; /*misc vars and loop vars*/
	
	
	while ( confirm == 'y' ) { /*master loop*/
	
		while ( yy <= 4 ) { /*initialisation of cards' status*/
			while ( zz <= 13 ) {
				card[yy][zz] = 0;
				zz++;
			}
			yy++;
		}
		
		printf("Welcome to Texas Hold 'em!\n");
		
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
		
		yy = 0;
	
		while ( yy == 0 ) { /*assignment of values of blinds*/
		
			printf("Big blind:\n");
			scanf(" %d", &bigBlind);
			
			printf("Small blind:\n");
			scanf(" %d", &smallBlind);
			
			if ( bigBlind <= smallBlind || bigBlind < 0 || smallBlind < 0 ) {
				printf("Invalid input\n");
				printf("Big blind MUST be larger than the small blind and both must be positive number.\n");
			} else {
				yy = 1;
			}
		}
		
		printf("Big blind is %d, small blind is %d.\n", bigBlind, smallBlind);
		
		printf("Preparations complete, game will start shortly.\n");
		sleep(3);
		
		while ( y == 0 ) { /*game loop, each pass through the loop is a hand*/
		
			xx = 0; /*Will be using these loop vars A LOT, so reintitialising every pass through the game loop*/
			yy = 0;
			zz = 0;

			pot = 0; /*emptying the pot*/
			
			printf("Cards are being dealt.\n");
			dealing(); /*will deal two card to each player*/
			printf("Player %d is the dealer for this hand.\n", dealer);
			printf("Player %d posts big blind, player %d posts small blind.\n", dealer + 1, dealer + 2);

			pot = smallBlind + bigBlind;

			playerCash[dealer + 1] = playerCash[dealer + 1] - smallBlind; /*subtracting small blind from players cash*/
			playerCash[dealer + 2] = playerCash[dealer + 2] - bigBlind; /*subtracting big blind from players cash*/

			for ( xx = 1; xx <= numPlayers; xx++ ) { /*initial round of betting before the flop*/

				printf("Player %d\n", xx);

				x = 0;

				cardListing(xx);

				printf("What action would you like to take?\n");

				while ( x == 0 ){
					printf("Check cards (q)\nCheck cash (w)\nCheck pot (e)\nCheck current bet (r)\nMake a bet (t)\n");

					scanf(" %c", &menu );

					switch ( menu ) { /*player action menu*/
						case 'q': cardListing(xx); break; /*lists card held by player*/
						case 'w': printf("Cash: %d\n", playerCash[xx]); break; /*lists player cash*/
						case 'e': printf("Pot: %d\n", pot); break; /*lists value of pot*/
						case 'r': printf("Current bet: %d\n", tableBet); break; /*current bet that must be matched*/
						case 't': printf("Enter a bet you wish to make.\n"); /*input of a bet player wishes to make*/
							scanf(" %d", &playerBet);
							if( playerBet >= tableBet ) { /*if the bet matches or raises the table bet*/
								printf("You are going to make a bet of %d. Confirm (y/n)", playerBet);

								scanf(" %c", &menu2);

								switch ( menu2 ) { /*evaluates player choice, and acts on bet as such*/
									case 'y': printf("Bet commited.\n"); pot += playerBet; x = 1; break;
									case 'n': printf("Bet redacted, returning to menu.\n"); break;
									default: printf("Invalid input, returning to menu.\n"); break;
								}
							} break;
						default: printf("Invalid selection.\n"); break;
					}
				}	
			}
		}
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


		
int dealing() /*function for dealing cards*/
{

	/*loop variables this function will need*/
	int a = 0, b = 0;
	/*placeholders for values determined by rand()*/
	int aa = 0, bb = 0, cc = 0;
	

	srand(time(NULL));

	for ( a = 0; a <= numPlayers; a++ ) { /*master, will terminate when all players have two cards*/

		for ( b = 0; b <= 2; b++ ) {

			aa = rand()%5; /*suit*/
			bb = rand()%14; /*card value*/
			cc = ( rand()%( numPlayers + 1 ) ) + dealer; /*player this card will be given to*/

			if ( playerStatus[cc] != 2 && card[aa][bb] == 0) { /*if player does not have two cards, and card is not dealt*/
				
				card[aa][bb] = cc; /* card is assigned to a player*/
			}
		}
	}
	return 0;
}

int cardListing(int xx) /*will list cards held by player*/
{

	int x = 1, y = 1, z = 0; 

	printf("You have: \n");

	for ( x = 1; x <= 4; x++ ) { /*runs through all the cards to check what player has them*/

		for ( y = 1; x <= 13; y++ ) {

			if ( card[x][y] == xx ) {
				switch ( x ) {
					case 1: strcpy(cardSuit, "Diamonds"); break;
					case 2: strcpy(cardSuit, "Clubs"); break;
					case 3: strcpy(cardSuit, "Hearts"); break;
					case 4: strcpy(cardSuit, "Spades"); break;
				}

				switch  ( y ) {
					case 11: strcpy(cardName, "Jack"); break;
					case 12: strcpy(cardName, "Queen"); break;
					case 13: strcpy(cardName, "King"); break;
					case 1: strcpy(cardName, "Ace"); break;
				}

				if ( cardNum >= 2 && cardNum <= 10 ) {
					printf("%d of %s\n", y, cardSuit);
				} else {
					printf("%s of %s\n", cardNum, cardSuit);
				}
			}
		}
	}

	return 0;
}