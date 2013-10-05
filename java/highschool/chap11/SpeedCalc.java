import java.util.Scanner;

class SpeedCalc
{
  public static void main (String[] args)
  {
    double time, speed, distance, g;
    g = 32.174;
    Scanner scan = new Scanner (System.in);
    
    System.out.print("Enter in a time in seconds: ");
    time = scan.nextDouble();
    
    distance = (1/2)*g*(time*time);
    speed = distance / time;
    
    System.out.print("The ball is traveling at " + speed + "f/s.");
  }
}