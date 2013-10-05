import java.util.Scanner;

class inRangeAdder
{
  public static void main(String[] args)
  {
    
    Scanner scan = new Scanner(System.in);
    
    int high, low, adder = 1, sum = 0, totalNumbers = 0;
    
    System.out.print("Enter the low end of your range: ");
    low = scan.nextInt();
    
    System.out.print("Enter in the high end of your range: ");
    high = scan.nextInt();
    
    while(adder != 0)
    {
      System.out.println("Enter in your addition (or 0 to quit): ");
      adder = scan.nextInt();
        
        if(adder >= low && adder <= high)
        {
          sum = sum + adder;
          totalNumbers ++;
        }
        else
          System.out.println("Your number is out of your range.");
        
    }
    
    System.out.print("Your sum is " + sum + " out of " + totalNumbers + " number(s).");
  }
}
