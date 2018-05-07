import java.awt.Color;
public class ShrinkBall extends BasicBall
{
    
        protected double start_radius;
    
        protected final Color color;     // color
      
        
    
        // constructor
        public ShrinkBall(double r, Color c) {
            super(r, c);
            rx = 0.0;
            ry = 0.0;
            vx = StdRandom.uniform(-0.01, 0.01);
            vy = StdRandom.uniform(-0.01, 0.01);
            radius = r;
            start_radius=radius;
            color = c;
            isOut = false;
    }

    public int reset() {
        rx = 0.0;
        ry = 0.0;  
        vx = StdRandom.uniform(-0.01, 0.01);
        vy = StdRandom.uniform(-0.01, 0.01);	
        // TO DO: assign a random speed 
        radius = radius * .666;
        if (radius <= start_radius * .25)
        {
            radius = start_radius;
        }
        return 1;
    }


    public int getScore() {
    	return 20;
    }
}