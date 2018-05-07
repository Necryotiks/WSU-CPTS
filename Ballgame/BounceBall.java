import java.awt.Color;

public class BounceBall extends BasicBall
{
    protected final Color color;     // color

    private int bounceCount;
    

    // constructor
    public BounceBall(double r, Color c) 
    {
        super(r,c);
        rx = 0.0;
        ry = 0.0;
        vx = StdRandom.uniform(-0.01, 0.01);
        vy = StdRandom.uniform(-0.01, 0.01);
        radius = r;
        color = c;
        isOut = false;
        bounceCount=0;
    }


    public void move() 
    {
        rx = rx + vx;
        ry = ry + vy;
        if ((Math.abs(rx) >= 1.0) || (Math.abs(ry) >= 1.0)) 
        {
            vx = -vx;
            vy = -vy;
            rx = rx + vx;
            ry = ry + vy;
            if (bounceCount ==3)
            {
                isOut = true;
            }
            else 
            {
                bounceCount++;
            }
        }
        	
    }

    public int getScore() {
    	return 15;
    }
}