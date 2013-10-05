import java.util.Scanner;

class Thirty
{
  public static void main (String[] args)
  {
    
    Scanner scan = new Scanner(System.in);
    
    String first, second;
    int firstLen, secondLen,totalLen;
    
    
    System.out.println("Enter in your first word: ");
    first = scan.nextLine();
    
    System.out.println("Enter in your second word: ");
    second = scan.nextLine();
    
    firstLen = first.length();
    secondLen = second.length();
    
    totalLen = 30 - firstLen - secondLen;
    if (totalLen > 0) 
    {
    System.out.print(first);
    while(totalLen > 0)
    {
     System.out.print(".");
     totalLen --;
    }
    System.out.print(second);
    }
     else
      System.out.println("Sorry, your word is too long.");    
    
  }
}
    
    