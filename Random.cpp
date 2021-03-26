// Random.cpp

#include "Random.h"
#include <cstdlib>

// Returns a random number in r.
int Random(Range r)
{
    return r.getLow() + rand() % ((r.getHigh() + 1) - r.getLow());
}

// Returns a random number in [low, high].
int Random(int low, int high)
{
    return low + rand() % ((high + 1) - low);
}



