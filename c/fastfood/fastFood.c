#include <stdio.h>
#include <math.h>

int main()
{
	/*char selct;*/
	char subSelct;
	char mainSelct;
    char loopVar = 'y';
	int itemNum;
	int numItems = 0;
	int fulfill;
	float custom = 0;
	float hst = 0.13;
	float subTotal = 0;
	float taxTotal = 0;
	float total = 0;
	
	printf("Cost calculation\n");
	
	while ( loopVar == 'y' ) {
		
		fulfill = 1;
		
		while ( fulfill == 1 ) {
			
			printf("Menu selection. 'i' for item, 'm' for additional menu options\n");
			scanf(" %c", &mainSelct);
			
			switch ( mainSelct ) {
				case 'i': printf("Select a item:\n"); /*Adding the cost of an item*/
					scanf("%d", &itemNum );
					
					switch ( itemNum ) {
						case 1: subTotal = subTotal + 4.99; numItems++; break;
						case 2: subTotal = subTotal + 5.99; numItems++; break;
						case 3: subTotal = subTotal + 8.99; numItems++; break;
						case 4: subTotal = subTotal + 9.99; numItems++; break;
						case 5: subTotal = subTotal + 1.99; numItems++; break;
						case 6: subTotal = subTotal + 3.55; numItems++; break;
						case 7: subTotal = subTotal + 2.99; numItems++; break;
						case 8: subTotal = subTotal + 1.50; numItems++; break;
						case 9: scanf("%f", &custom); subTotal = subTotal + custom; numItems++; break;
						default: printf("Not a selection\n"); break;
					}	
					break;
				case 'm': printf("Select a menu option.\n"); /*Menu navigation*/
				    fgetc(stdin);
					scanf( "%c", &subSelct );
					switch ( subSelct ) {
						
						case 'x': fulfill = 0; break; /*Moves to total calculation*/
						case 's': printf("Subtract an item.\n"); scanf("%d", &itemNum); /*subtracts the price of an item*/
							switch ( itemNum ) {
								case 1: subTotal = subTotal - 4.99; numItems--; break;
								case 2: subTotal = subTotal - 5.99; numItems--; break;
								case 3: subTotal = subTotal - 8.99; numItems--; break;
								case 4: subTotal = subTotal - 9.99; numItems--; break;
								case 5: subTotal = subTotal - 1.99; numItems--; break;
								case 6: subTotal = subTotal - 3.55; numItems--; break;
								case 7: subTotal = subTotal - 2.99; numItems--; break;
								case 8: subTotal = subTotal - 1.50; numItems--; break;
								case 9: scanf("%f", &custom); subTotal = subTotal - custom; numItems--; break;
								default: printf("Not a selection\n"); break;
							}
							break;
							
						case 't': printf("Current total: $%.2f\n", subTotal); break; /*prints current subtotal*/
					 	default: printf("Invalid selection.\n"); break;
					}
					break;			
				default: printf("Invalid selection.\n"); break;

			 }
		
		}
	
		taxTotal = subTotal * hst;
		
		total = subTotal + taxTotal;
		
		
		printf("Number of items: %d\n", numItems);
		printf("Sub Total: $%.2f\n", subTotal);
		printf("Tax: $%.2f\n", taxTotal);
		printf("Total cost: $%.2f\n", total);
			
	    printf("\n");
	    
	    printf("New order? (y/n)\n");
	    fgetc(stdin);	
		scanf("%c", &loopVar);
	}

	return (0);

}


