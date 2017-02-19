#include <iostream>
#include "angle.h"
#include "correlation.h"
#include "correlator.h"
#include "latticeupdate.h"

void correlation(int T1, Angle theta, int n, double beta)
{
    // split this up into two functions

    using namespace std;

    for(int t = 0; t < T1; t++)
    {
        latticeupdate(beta, theta, n);
        cout << "\rMetropolising " << t + 1 << " of " << T1 << ": " 
             << ((t + 1) * 100) / T1 << "% complete." << flush;
    }
        
    cout << "\n\n" << "Metropolis is finished! \n\n" 
         << "d" << "\t" << "correlation \n-------------------" << endl;
        
    for(int d = 0; d <= n; d++)
    {
        double C = correlator(theta, n, d);
        double C_norm = C / (n * n);
        cout << d << "\t" << C_norm << endl;
    }
}

