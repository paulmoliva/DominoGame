#include "crandom.h"

CRandom::CRandom()
{

}

int CRandom::getRandomPublic(int rangeLow, int rangeHigh)
{
    int myRand_scaled;

    myRand_scaled=getRandomPrivate(rangeLow, rangeHigh);

    return myRand_scaled;
}

int CRandom::getRandomPrivate(int rangeLow, int rangeHigh)
{
    double myRand = rand()/(1.0 + RAND_MAX);
    int range = rangeHigh - rangeLow + 1;
    int myRand_scaled = (myRand * range) + rangeLow;
    return myRand_scaled;
}

int CRandom::getRandomProtected(int rangeLow, int rangeHigh)
{
    double myRand = rand()/(1.0 + RAND_MAX);
    int range = rangeHigh - rangeLow + 1;
    int myRand_scaled = (myRand * range) + rangeLow;
    return myRand_scaled;
}





