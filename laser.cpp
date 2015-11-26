#include "laser.h"

Laser::Laser(double data[])
{
    x = data[0];
    y = data[1];
    theta = data[2];
    xl = data[3];
    yl = data[4];
    thetal = data[5];

    for(int i = 0; i < 180; i++){
        distance[i] = data[6+i];
    }

    timestamp = data[186];
}
