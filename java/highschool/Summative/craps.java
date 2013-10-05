import java.util.Scanner;
import java.util.Random;

class craps
{
  public static void main(String[] args)
  {
    
    Scanner scan = new Scanner(System.in);
    Random rand = new Random();

    
    int dieRoll = 0, point = 0, count = 0, totalCount = -1, score = 0, scoreTo = 0, startEnd = 0, contin = 0, equals = 2;
    int play = 9;
    String input, input2;
    // dieRoll is the rols value, point is the point, count is the count between points, totalCount is the totla count
    // score is total score, scoreTo is the max score the player wants to play to
    // startEnd is the game start/end decider
    
    System.out.print("Do you wish to play? (YES or NO)");
    input2 = scan.nextLine();
    
    
    if(input2.equals("YES"))
    {
      play = 1;
    }
    if(input2.equals("NO"))
    {
     startEnd = 1;
     play = 0;
    }     
    if(play == 1)
    {
    System.out.println("Enter 'roll' to roll, and 'exit' to exit.");
    System.out.println("What do you want to play until?");
    scoreTo = scan.nextInt();
    }
    
    
    while(startEnd == 0 && play == 1)
    // master loop
    {
     equals = 0;
      
     System.out.println("What do you wish to do?");
     input = scan.nextLine();
      
     if(input.equals("roll"))  
     {
       dieRoll = rand.nextInt(11) + 1;  
       System.out.println("You roll a " + dieRoll + ".");
       contin = 0;
       equals = 1;
     }
     
     if(input.equals("exit"))
     { 
       startEnd = 1;
       equals = 1;
     }
     
     if(equals == 0)
     {
       System.out.println("Sorry, that is not an option.");
       contin = 1;
     }  
     count = count + 1;
     totalCount = totalCount + 1;
    
     if(score == scoreTo)
     startEnd = 2;
 
     if(totalCount == 0 && contin == 0) 
     //handles first roll
        {
         if(dieRoll == 2 || dieRoll == 3 || dieRoll == 12) 
         // if die roll = 2, 3, 12, player loses
         {
          System.out.println("You lose!");
          System.out.println("Score is now " + score);
          score = score + 1;
         }
         if(dieRoll == 7 || dieRoll == 11) 
         //if die roll = 7, 11, player re rolls for point
         System.out.println("Reroll.");
         
         if(dieRoll != 2 && dieRoll != 3 && dieRoll != 12 && dieRoll != 7 && dieRoll != 11)
         // if none of the restricted numbers are rolled, point is assigned
         {
         point = dieRoll;
         System.out.println("Your new point is " + point);
         count = count + 1;
         }  
        }
      
      
      if(totalCount != 0 && contin == 0)
      {
        if(point == 0 && dieRoll != 7)
        //assigns new point if none exists
        {
        point = dieRoll;
        System.out.println("Your new point is " + point);
        dieRoll = 0;
        }
        
        if(dieRoll == 7)
        //if dieRoll = 7, player loses
        {
         System.out.println("You lose!");
         System.out.println("Score is now " + score);
         score = score - 1;
         point = 0;
         count = 0;
        }
         
        if(dieRoll == point && point != 0)
        //if dieroll matches point, and point isnt naught, player wins
        {
         System.out.println("You win! It took you " + count + " tries.");
         System.out.println("Score is now " + score);
         score = score + 1;
         point = 0;
         count = 0;
        }
      }
    } 
    
    
    
    
    if(startEnd == 1)
      System.out.println("You've ended the game! Quiting...");
    
    if(startEnd == 2)
      System.out.println("You've won! Congrats!");
  }
 }

