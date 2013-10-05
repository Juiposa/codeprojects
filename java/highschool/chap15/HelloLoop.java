import java.util.Scanner;

class HelloLoop
{
  public static void main ( String[] args)
  {
    
    Scanner scan = new Scanner (System.in);
    
    String inputString;
    int times;
    
    System.out.println("Enter your word: ");
    inputString = scan.nextLine();
    
    times = inputString.length();
    
    while(times > 0)
    {
    System.out.println(inputString);
    times --;
    }
  }
}