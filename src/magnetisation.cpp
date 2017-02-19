#include <cmath>
#include "angle.h"
#include "magnetisation.h"

double magnetisation(Angle theta, int n)
{
    double ReM = 0, ImM = 0;
    for(int x = 0; x < n; x++)
        for(int y = 0; y < n; y++)
        {
            ReM += cos(theta(x, y));
            ImM += sin(theta(x, y));
        }

    return ReM * ReM + ImM * ImM;
}

