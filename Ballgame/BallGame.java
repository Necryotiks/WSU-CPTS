/******************************************************************************
 *  Compilation:  javac BallGame.java
 *  Execution:    java BallGame n
 *  Dependencies: BasicBall.java StdDraw.java
 *
 *  Creates a BasicBall and animates it
 *
 *  Part of the animation code is adapted from Computer Science:   An Interdisciplinary Approach Book
 *  
 *  Run the skeleton code with arguments : 1  basic  0.08
 *******************************************************************************/
//I worked with Zaid
import java.awt.Color;
import java.awt.Font;
import java.util.*;

public class BallGame { 

    public static void main(String[] args) {
  
    	// number of bouncing balls
    	int numBalls = Integer.parseInt(args[0]);
    	//ball types
    	String ballTypes[] = new String[numBalls];
    	//sizes of balls
        double ballSizes[] = new double[numBalls];
        
        ArrayList <BasicBall> ballList = new ArrayList <BasicBall>();

        int index = 1;


    	
    	//retrieve ball types
        for (int i=0; i<numBalls; i++) 
        {
            if (index >= args.length)
            {
                ballTypes[i]="basic";
            }

            ballTypes[i] = args[index];
            index += 2;
    	}
        //retrieve ball sizes
        index =2;
        for (int i=0; i<numBalls; i++) 
        {
            if (index >= args.length)
            {
                ballSizes[i]=0.08;
            }
            ballSizes[i] = Double.parseDouble(args[index]);
            index += 2;
    	}
     
    	//TO DO: create a Player object and initialize the player game stats.  
    	Player p1=new Player();
    	
    	//number of active balls
    	int numBallsinGame = 0;
        StdDraw.enableDoubleBuffering();

        StdDraw.setCanvasSize(800, 800);
        // set boundary to box with coordinates between -1 and +1
        StdDraw.setXscale(-1.0, +1.0);
        StdDraw.setYscale(-1.0, +1.0);

        // create colored balls 
        //TO DO: Create "numBalls" balls (of types given in "ballTypes" with sizes given in "ballSizes") and store them in an Arraylist
        //BasicBall ball = new BasicBall(ballSizes[0],Color.RED);

        for (int i = 0; i < numBalls; i++)
        {
            if ("basic".equals(ballTypes[i]) || "Basic".equals(ballTypes[i]))
            {
            ballList.add(new BasicBall(ballSizes[i], Color.RED));
            numBallsinGame++;
            }
            else if("bounce".equals(ballTypes[i]) || "Bounce".equals(ballTypes[i]))
            {
                ballList.add(new BounceBall(ballSizes[i], Color.GREEN));
                numBallsinGame++;
            }
            else if ("shrink".equals(ballTypes[i]) || "Shrink".equals(ballTypes[i]))
            {
                ballList.add(new ShrinkBall(ballSizes[i], Color.BLUE));
                numBallsinGame++;
            }
            else 
            {
                ballList.add(new SplitBall(ballSizes[i], Color.YELLOW));
                numBallsinGame++;
            }
        }
           
   		//TO DO: initialize the numBallsinGame
        
        // do the animation loop
        StdDraw.enableDoubleBuffering();
        while (numBallsinGame > 0) {

        for (int i = 0; i < numBalls; i++)
        {
            BasicBall ball = ballList.get(i);
            ball.move();
        }

            //Check if the mouse is clicked
            if (StdDraw.isMousePressed()) {
                double x = StdDraw.mouseX();
                double y = StdDraw.mouseY();
                
                for (int i = 0; i < numBalls; i++)
                {
                    BasicBall ball = ballList.get(i);
                    if (ball.isHit(x,y)) 
                    {
                        p1.inc_currentScore(ball.getScore());
                        p1.inc_successfulHits(1);
                        // To do check instance *********
                       
                        if (ball instanceof BounceBall)
                        {
                           p1.inc_bounceBallCount(1);
                          
                        }
                        else if (ball instanceof ShrinkBall)
                        {
                           p1.inc_shrinkBallCount(1);
                           
                        }
                        else if (ball instanceof SplitBall)
                        {
                           p1.inc_splitBallCount(1);
                          
                        }
                        else
                        {
                           p1.inc_basicBallCount(1);
                           
                        } 

                        if (ball instanceof SplitBall)
                        {
                            ballList.add(new SplitBall(ballSizes[0], Color.RED));
                            numBallsinGame++;
                            numBalls++;
                        }
                        ball.reset();
                     }
                }
            }
                
            numBallsinGame = 0;
            // draw the n balls
            StdDraw.clear(StdDraw.GRAY);
            StdDraw.setPenColor(StdDraw.BLACK);
            

            for (int i = 0; i < numBalls; i++)
                {
                   BasicBall ball = ballList.get(i);
                    if (ball.isOut == false) 
                    { 
                        ball.draw();
                        numBallsinGame++;
                    }
                   
                }
          
            //Print the game progress
            StdDraw.setPenColor(StdDraw.YELLOW);
            Font font = new Font("Arial", Font.BOLD, 20);
            StdDraw.setFont(font);
            StdDraw.text(-0.65, 0.90, "Number of balls in game: "+ String.valueOf(numBallsinGame));
            //TO DO: print the rest of the player statistics
            StdDraw.text(-0.65, 0.80, "Current Score: "+String.valueOf(p1.get_currentScore()));
            StdDraw.text(-0.65, 0.70, "Num of hits: "+String.valueOf(p1.get_successfulHits()));
            StdDraw.text(-0.65, 0.60, "Basic Ball Hits: "+String.valueOf(p1.get_basicBallCount()));
            StdDraw.text(-0.65, 0.50, "Bounce Ball Hits: "+String.valueOf(p1.get_bounceBallCount()));
            StdDraw.text(-0.65, 0.40, "Shrink Ball Hits: "+String.valueOf(p1.get_shrinkBallCount()));
            StdDraw.text(-0.65, 0.30, "Split Ball Hits: "+String.valueOf(p1.get_splitBallCount()));
            StdDraw.show();
            StdDraw.pause(20);
        }
        while (true) {
            StdDraw.clear(StdDraw.GRAY);
            StdDraw.setPenColor(StdDraw.RED);
            Font font = new Font("Arial", Font.BOLD, 50);
            StdDraw.setFont(font);
            StdDraw.text(0, 0, "GAME OVER");
            //TO DO: print the rest of the player statistics
            StdDraw.setPenColor(StdDraw.PRINCETON_ORANGE);
            StdDraw.text(0, 0.80, "Current Score: "+String.valueOf(p1.get_currentScore()));
            StdDraw.setPenColor(StdDraw.CYAN);
            StdDraw.text(0, 0.70, "Num of hits: "+String.valueOf(p1.get_successfulHits()));
            StdDraw.setPenColor(StdDraw.RED);
            StdDraw.text(0, 0.60, "Basic Ball Hits: "+String.valueOf(p1.get_basicBallCount()));
            StdDraw.setPenColor(StdDraw.GREEN);
            StdDraw.text(0, 0.50, "Bounce Ball Hits: "+String.valueOf(p1.get_bounceBallCount()));
            StdDraw.setPenColor(StdDraw.BLUE);
            StdDraw.text(0, 0.40, "Shrink Ball Hits: "+String.valueOf(p1.get_shrinkBallCount()));
            StdDraw.setPenColor(StdDraw.YELLOW);
            StdDraw.text(0, 0.30, "Split Ball Hits: "+String.valueOf(p1.get_splitBallCount()));
            StdDraw.show();
            StdDraw.pause(10);           
        }

        	
        
    }
}
