import java.util.Scanner;

class Cheques
{
  public static void main(String[] args)
  {
    Scanner scan = new Scanner(System.in);
    double checking, savings;
    int numberOfChecks;
    final double serviceCharge = 0.15;
    
    System.out.print("How many chacks would you like to write: ");
    numberOfChecks = scan.nextInt();
    
    System.out.print("How much $$$ in your... ");
    
    System.out.print("Checking account?: ");
    checking = scan.nextDouble();
    
    System.out.print("Savings account?: ");
    savings = scan.nextDouble();
    
    if (checking >= 1000 && savings >= 1500)
      System.out.print("It will cost you nothing to use your cheques.");
    else
      System.out.print("It will cost you " + numberOfChecks*serviceCharge + " to use your cheques.");
  }
}
    