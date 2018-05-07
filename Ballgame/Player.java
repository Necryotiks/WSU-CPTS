

public class Player
{
	private int successfulHits;
	private int currentScore;
	private int basicBallCount;
	private int shrinkBallCount;
	private int bounceBallCount;
	private int splitBallCount;


	Player()
	{
		successfulHits=0;
		currentScore=0;
		basicBallCount=0;
		bounceBallCount=0;
		splitBallCount=0;
	}

	//Setters
	public void inc_successfulHits(int a)
	{
		successfulHits+=a;
	}



	public void inc_currentScore(int b)
	{
		currentScore+=b;
	}

	public void inc_basicBallCount(int d)
	{
		basicBallCount+=d;
	}

	public void inc_bounceBallCount(int e)
	{
		bounceBallCount+=e;
	}

	public void inc_splitBallCount(int f)
	{
		splitBallCount+=f;
	}

	public void inc_shrinkBallCount(int g)
	{
		shrinkBallCount += g;
	}

	//Getters
	public int get_successfulHits()
	{
		return successfulHits;
	}

	public int get_currentScore()
	{
		return currentScore;
	}


	public int get_basicBallCount()
	{
		return basicBallCount;
	}

	public int get_bounceBallCount()
	{
		return bounceBallCount;
	}

	public int get_splitBallCount()
	{
		return splitBallCount;
	}

	public int get_shrinkBallCount()
	{
		return shrinkBallCount;
	}


}


