/*Average grade calculator.
 * average.c
 * Jeffrey-David Kapp
 * Touched: Oct 3rd, 2013
 * Last modified: Oct 3rd, 2013
 */
 
#include <stdio.h>
#include <math.h>


int main()
{
	
	int x = 1, y = 1, z = 1, yy = 1;
	int numMark = 0;
	int temp = 0;
	char tempChar;
	char name[30];
	float mark[100];
	float markTotal = 0;
	float weight[100];
	float totalWeight = 0;
	float weightChange = 0;
	float average = 0;
	
	/*array initialisation*/
	while ( yy <= 100 ) {
		mark[yy] = 0;
		weight[yy] = 0;
		yy++;
	}
	
	yy = 1;
	
	/*master loop*/
	while ( x == 1 ) {
		
		printf("Please enter your name: \n");
		fgets( name,  30, stdin );
		printf("Hello, %s\n", name);
		
		y = 1;
		z = 1;
		
		while ( y == 1 ) {
		
			printf(" Enter a series of marks (m)\n List marks (l)\n Calculate average (a)\n");
			scanf(" %c", &tempChar);
			
			switch ( tempChar ){
				case 'm': printf("How many marks do you wish to enter?\n");
					scanf("%d", &temp);
					numMark = numMark + temp; 
					
					while ( z <= numMark ) {
						printf("Mark: \n");
						scanf("%f", &mark[z]);
						
						printf("Weight: \n");
						scanf("%f", &weight[z]);
						
						z++;
					} 
					break;
					
				case 'l': 
					while ( yy <= numMark ) { 
						printf("Listing marks.\n");
						printf("Mark %d \n", yy);
						printf("Mark: %.1f \n" , mark[yy]); 
						printf("Weight: %.1f\n", weight[yy]); 
						yy++;
					}
					yy = 1;
					break;
					
				case 'a': printf("Calculating and listing average.\n");
					
					while ( yy <= numMark ) {					/*adding the total assigned weight between grades*/
						totalWeight = totalWeight + weight[yy];	/*if the total weight is not equal to the number of entered marks*/
						yy++;									/*it will adjust weight values based on percentage of */
					}											/*numMark to totalWeight*/
					yy = 1;										

					
					if ( totalWeight != numMark ) {
						
						weightChange = totalWeight / numMark;
						
						while ( yy <= numMark ) {
								temp = weight[yy] * weightChange;
								weight[yy] = temp;
								yy++;
							}			
									
						yy = 1;
						
					}
					
					while ( yy <= numMark ) {
						markTotal = mark[yy] * weight[yy];
						yy++;
					}
					
					yy = 1;
						
					average = markTotal / numMark;
					
					printf("Your average is: %f%\n", average);
					
					y = 0;
					
					break;
					
				}
			}
			
		printf("Would you like to make another entry?(y/n)\n");
		scanf("	%c", &tempChar);
		
		switch ( tempChar ) {				/*decision for continuation or ending of loop*/
			case 'y': x = 1; break;
			case 'n': x = 0; break;
			default: printf("Defaulting to 'no'\n"); x = 0; break;
		}
	}
	
	printf("Thanks for using.\n");
	
	return (0);
}
					
					
					
					

						
			
			
