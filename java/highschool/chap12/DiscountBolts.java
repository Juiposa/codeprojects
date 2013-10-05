 
import java.util.Scanner;
  
class DiscountBolts
  
 
{
  public static void main (String[] args)
  {
    Scanner scan = new Scanner (System.in);
    double bolts, nuts, washers, cost;
    final int boltPrice = 5, nutPrice = 3, washerPrice = 1;
    
    System.out.print("Enter in the number of... ");
    
    System.out.print("Bolts: ");
    bolts = scan.nextDouble();
    
    System.out.print("Nuts: ");
    nuts = scan.nextDouble();
    
    System.out.print("and Washers: ");
    washers = scan.nextDouble();
    
    if (bolts/nuts > 1)
      System.out.print("Check order: Not enough bolts! ");
    if (bolts/nuts < 1)
      System.out.print("Check order: Not enough nuts! ");
     
    if (bolts/washers != 2)
      System.out.print("Check order: Not enough washers! ");
      
    cost = (bolts*boltPrice) + (nuts*nutPrice) + (washers*washerPrice);  
    System.out.print("Total cost: " + cost);
  }
}
    