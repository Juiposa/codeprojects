import java.util.Scanner;

class SumOfSquares
{
  public static void main(String[] args)
  {
    
    Scanner scan = new Scanner(System.in);
    
    int sumSquare = 0, sumCube = 0, n;
    
    System.out.print("Enter a number: ");
    n = scan.nextInt();
    
    sumSquare = n * ( n + 1 ) * ( 2 * n + 1 ) / 6; 
    sumCube = (n * n * ( ( n + 1 ) * ( n + 1 ) ) )  / 4;
      
    System.out.println("The sum of squares is: " + sumSquare);
    System.out.println("The sum of cubes is: " + sumCube);
  }
}