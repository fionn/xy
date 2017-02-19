#include <cmath>
#include <cstdlib>
#include "angle.h"
#include "metropolis.h"

void metropolis(double beta, Angle theta, int i, int j)
{
    const double pi = M_PI;
    const double delta = 1.0;
    double theta_prime = theta(i, j) + delta * pi * (2 * drand48() - 1);

    double S = 1 - cos(theta(i, j) - theta(i + 1, j)) 
             + 1 - cos(theta(i, j) - theta(i - 1, j)) 
             + 1 - cos(theta(i, j) - theta(i, j + 1)) 
             + 1 - cos(theta(i, j) - theta(i, j - 1));
    
    double S_prime = 1 - cos(theta_prime - theta(i + 1, j)) 
                   + 1 - cos(theta_prime - theta(i - 1, j)) 
                   + 1 - cos(theta_prime - theta(i, j + 1)) 
                   + 1 - cos(theta_prime - theta(i, j - 1));
    
    double r = exp(beta * 2 * (S - S_prime)); 

    if(r > 1.0)
        theta(i, j) = theta_prime;

    if(r > drand48())
        theta(i, j) = theta_prime;
}

