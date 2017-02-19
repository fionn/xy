#include <iostream>
#include <argp.h>
#include "angle.h"
#include "arguments.h"
#include "parse.h"
#include "hot_start.h"
#include "metropolis.h"
#include "latticeupdate.h"
#include "magnetisation.h"
#include "correlator.h"
#include "correlation.h"
#include "betamag.h"

/*
double action(int n, Angle theta)
{
    double S = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            S += (1 - cos(theta(i, j) - theta(i + 1, j))) 
               + (1 - cos(theta(i, j) - theta(i - 1, j))) 
               + (1 - cos(theta(i, j) - theta(i, j + 1))) 
               + (1 - cos(theta(i, j) - theta(i, j - 1)));
    
    return S;
}

void markov(int n, Angle theta)
{
    for(int x = 0; x < n; x++)
        for(int y = 0; y < n; y++)
            std::cout << x << "\t" << y << "\t" << theta(x, y) << std::endl;
}
*/

int main(int argc, char* argv[])
{
    struct arguments args = parser(argc, argv);
    if(args.beta < 0 || args.size <= 0 || args.correlate <= 0)
        return 1;

    const double beta = args.beta;
    const int n = args.size, c = args.correlate;

    Angle theta(n), theta_prime(n);

    srand48((unsigned)time(NULL));
    hot_start(n, theta);
    
    //markov(n, theta);
    if(args.mag)
        betamag(n, theta, 60000, 10000);
    else
    {
        std::cout << "n = " << n << ", β = " << beta  << ", c = " << c << std::endl;
        correlation(c, theta, n, beta);
    }

    return 0;
}

