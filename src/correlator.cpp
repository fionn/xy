#include <cmath>
#include "angle.hpp"
#include "correlator.hpp"

double correlator(Angle theta, int n, int d)
{
    double C = 0;
    for(int x = 0; x < n; x++)
        for(int y = 0; y < n; y++)
            C += cos(theta(x, y) - theta(x + d, y));
    
    return C;
}

