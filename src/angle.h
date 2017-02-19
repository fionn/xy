#ifndef ANGLE_H
#define ANGLE_H

class Angle
{
    public:
        double *data;
        int n;
        Angle(int m);
        double& operator() (int i, int j);
};

#endif

