#ifndef ODOM_H
#define ODOM_H

class Odom
{
public:
    Odom(double []);

    double x;
    double y;
    double theta;
    double timestamp;
};

#endif // ODOM_H
