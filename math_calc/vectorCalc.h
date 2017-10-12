
class vectorCalc
{
  public:
    vectorCalc(void);
    ~vectorCalc(void);
    void initializeVectorCalculator(void);

  private:
    void dotProduct(void);
    void dotProduct(std::string IV1,std::string IV2);
    void crossProduct(void);
    void matrixReduce(void);
    void matrixMultiplication(void);
};