/*********** Movement Test ***********/ 
/**** Created by Logan Vandenberg ****/
/******** On October 3rd, 2013 *******/
/** To test out a movement mechanic **/

#include <stdio.h>
#include <stdlib.h>

void initialize();
void display();
void displayPlayer();


void moveUp();
void moveDown();
void moveLeft();
void moveRight();


int main()
{
	/*Global Variable Declaration*/
	char column1[16];
	char column2[16];
	char column3[16];
	char column4[16];
	char column5[16];
	char column6[16];
	char column7[16];
	char column8[16];
	char column9[16];
	char column10[16];
	char column11[16];
	char column12[16];
	char column13[16];
	char column14[16];
	char column15[16];
	char column16[16];
	
	char wall;
	char space;
	char player;
	int playerPosX;
	int playerPosY;
	char input;
	
	/*Global Variable Initialization*/
	
	input = 'h';
	wall = '@';
	space = '_';
	player = '$';
	playerPosX = 7;
	playerPosY = 7;
	
	void initialize()
	{
		
		int x;
		int y;
		int a;
		int b;
		
		
		x = 0;
		y = 16;
		a = x + 1;
		b = y - 1;
		
		
		/* filling the entire space with "@" */
		while (x < y)
		{
			column1[x] = wall;
			column2[x] = wall;
			column3[x] = wall;
			column4[x] = wall;
			column5[x] = wall;
			column6[x] = wall;
			column7[x] = wall;
			column8[x] = wall;
			column9[x] = wall;
			column10[x] = wall;
			column11[x] = wall;
			column12[x] = wall;
			column13[x] = wall;
			column14[x] = wall;
			column15[x] = wall;
			column16[x] = wall;
			
			x++;
		}
		
		/* filling the movement space with "_" */
		while (a < b)
		{
			
			column2[a] = space;
			column3[a] = space;
			column4[a] = space;
			column5[a] = space;
			column6[a] = space;
			column7[a] = space;
			column8[a] = space;
			column9[a] = space;
			column10[a] = space;
			column11[a] = space;
			column12[a] = space;
			column13[a] = space;
			column14[a] = space;
			column15[a] = space;
			
			a++;
		}
		
	}

	void display()
	{
	
		int x;
		x = 0;
		while(x < 16)
		{
			printf("%c", column1[x]);
			printf("%c", column2[x]);
			printf("%c", column3[x]);
			printf("%c", column4[x]);
			printf("%c", column5[x]);
			printf("%c", column6[x]);
			printf("%c", column7[x]);
			printf("%c", column8[x]);
			printf("%c", column9[x]);
			printf("%c", column10[x]);
			printf("%c", column11[x]);
			printf("%c", column12[x]);
			printf("%c", column13[x]);
			printf("%c", column14[x]);
			printf("%c", column15[x]);
			printf("%c", column16[x]);
			printf("\n");
			
			x++;
		}
		
	}

	/*Movement Functions*/
	void moveUp()
	{
		if (playerPosY == 2)
		{
			/*no movemnet if at top of screen*/
			
			playerPosY = 2;
		}
		else
		{
			playerPosY--;
		}
	}
	void moveDown()
	{
		if (playerPosY ==15)
		{
			/*no movemnet if at bottom of screen*/
			
			playerPosY = 15;
		}
		else
		{
			playerPosY++;
		}
	}
	void moveLeft()
	{
		if (playerPosX == 2)
		{
			/*no movemnet if at left of screen*/
			
			playerPosX = 2;
		}
		else
		{
			playerPosX--;
		}
	}
	void moveRight()
	{
		if (playerPosX ==15)
		{
			/*no movemnet if at right of screen*/
			
			playerPosX = 15;
		}
		else
		{
			playerPosX++;
		}
	}

	void displayPlayer()
	{
		initialize();
		switch(playerPosX)
		{
			case 2: column2[playerPosY - 1] = player;
				break;
			case 3: column3[playerPosY - 1] = player;
				break;
			case 4: column4[playerPosY - 1] = player;
				break;
			case 5: column5[playerPosY - 1] = player;
				break;
			case 6: column6[playerPosY - 1] = player;
				break;
			case 7: column7[playerPosY - 1] = player;
				break;
			case 8: column8[playerPosY - 1] = player;
				break;
			case 9: column9[playerPosY - 1] = player;
				break;
			case 10: column10[playerPosY - 1] = player;
				break;
			case 11: column11[playerPosY - 1] = player;
				break;
			case 12: column12[playerPosY - 1] = player;
				break;
			case 13: column13[playerPosY - 1] = player;
				break;
			case 14: column14[playerPosY - 1] = player;
				break;
			case 15: column15[playerPosY - 1] = player;
				break;
			
		}
	}
	
	
	initialize();
	displayPlayer();
	display();
	
	while (input != 'o')
	{
		input = getchar();
		system("clear");
		switch (input)
		{
			case 'w': moveUp();
				break;
			case 's': moveDown();
				break;
			case 'a': moveLeft();
				break;
			case 'd': moveRight();
				break;
			default: printf("Use 'w','a','s','d' to move, and 'o' to exit \n");
		}
		
		displayPlayer();
		display();
		
	}	
	
	
	
	return(0);
}
