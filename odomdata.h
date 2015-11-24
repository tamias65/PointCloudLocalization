#ifndef ODOMDATA_H
#define ODOMDATA_H

class OdomData
{
public:
    OdomData(double []);

    double x;
    double y;
    double theta;
    double timestamp;
};

#endif // ODOMDATA_H
