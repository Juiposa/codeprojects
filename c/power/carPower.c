
#include <stdio.h>

int main()
{
  float torque, power, rpm, deno;
  int unit = -1;
  float pi = 3.141569;

  printf("Welcome to the power calculator!\n");
  printf("Would you like to work is metric(0) or imperial(1)?\n");
  
   
  while ( unit != 1 && unit != 0 ) {

    scanf("%d", &unit);

    if ( unit == 0 ) {
      printf("You've chosen to work in Metric.\n"); 
      printf("Enter your torque in N/m.\n");
      scanf("%f", &torque);
      deno = 60000;
      }

    if ( unit == 1 ) { 
      printf("You've chosen to work in Imperial.\n");
      printf("Enter your torque in lb/ft.\n");
      scanf("%f", &torque);
      deno = 33000;
      }

    if ( unit != 1 && unit != 0 ) {
      printf("Invalid choice. Please pick either 1 or 0.\n");
      scanf("%d", &unit);
      
      }

  }
  
  printf("Please enter the RPM that you achieve that level of torque.\n");
  scanf("%f", &rpm);

  power = torque * 2 * pi * rpm / deno;

  if ( unit == 0 ) {
    printf("Your car produces %fkw with %fN/m of torque at %fRPM.", power, torque, rpm);
    }
  if ( unit == 1 ) {
    printf("Your car produces %fhp with %flb/ft of torque at %fRPM.", power, torque, rpm);
    }
    
  return (0);
}




















