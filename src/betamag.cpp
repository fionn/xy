#include <iostream>
#include "angle.h"
#include "betamag.h"
#include "latticeupdate.h"
#include "magnetisation.h"

void betamag(int n, Angle theta, int T1, int T2)
{
    using namespace std;

    double ktstart = 0.3, ktend = 1.0;
    
    for(double beta = 0; beta <= 5;)
    {   
        for(int t = 0; t <= T1; t++)
            latticeupdate(beta, theta, n);
        
        double M2 = 0;
        for(int t = 0; t <= T2; t++)
        { 
            latticeupdate(beta, theta, n);
            M2 += magnetisation(theta, n);
        }

        M2 /= T2;
        cout << beta << "\t" << M2 << endl;

        if(beta < ktstart || beta > ktend)
            beta += 0.05; // low resolution
        else
            beta += 0.01; // high resolution
    }
}

