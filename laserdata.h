#ifndef LASERDATA_H
#define LASERDATA_H

class LaserData
{
public:
    LaserData(double []);

    double x;
    double y;
    double theta;
    double xl;
    double yl;
    double thetal;
    double distance [180];
    double timestamp;
};

#endif // LASERDATA_H
