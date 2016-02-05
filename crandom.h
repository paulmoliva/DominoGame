#ifndef CRANDOM_H
#define CRANDOM_H
#include <sys/time.h>
#include <time.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <iostream>


class CRandom
{
public:
    CRandom();  // constructor
    ~CRandom(){}; // destructor

    int getRandomPublic(int rangeLow, int rangeHigh);

private:
    int getRandomPrivate(int rangeLow, int rangeHigh);

protected:
    int getRandomProtected(int rangeLow, int rangeHigh);

};

#endif // CRANDOM_H
