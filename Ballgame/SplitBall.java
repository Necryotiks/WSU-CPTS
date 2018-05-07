import java.awt.Color;

public class SplitBall extends BasicBall 
{
    protected final Color color;     // color

    public SplitBall (double r, Color c)
    {
        super(r,c);
        rx = 0.0;
        ry = 0.0;
        vx = StdRandom.uniform(-0.01, 0.01);
        vy = StdRandom.uniform(-0.01, 0.01);
        radius = r;
        color = c;
        isOut = false;
    }

    public int getScore() {
    	return 10;
    }


}