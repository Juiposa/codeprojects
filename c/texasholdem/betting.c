

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