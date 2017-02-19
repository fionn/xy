#include "angle.h"

Angle::Angle(int m) 
{
    n = m;
    data = new double [n * n]; 
}

double & Angle::operator() (int i, int j)
{
    i = (n + i) % n;    // this makes it
    j = (n + j) % n;    // a torus

    return data[i + n * j];
}

