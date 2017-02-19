#include "angle.h"
#include "latticeupdate.h"
#include "metropolis.h"

void latticeupdate(double beta, Angle theta, int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i % 2 == j % 2)      // even 
                metropolis(beta, theta, i, j);
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i % 2 != j % 2)      // odd 
                metropolis(beta, theta, i, j);
}

