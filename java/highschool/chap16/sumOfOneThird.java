import java.util.Scanner;

class sumOfOneThird
{
  public static void main(String[] args)
  {
    
    Scanner scan = new Scanner(System.in);
    
    double n, x = 1, sum = 0;
    
    System.out.print("Enter a number: ");
    n = scan.nextInt();
    
    while( x <= n)
    {
      sum = sum + (1/x);
      x = x + 1;
    }
    System.out.print("The sum is: " + sum);
    
  }
}