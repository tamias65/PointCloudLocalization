#include "odom.h"

Odom::Odom(double data[])
{
    x = data[0];
    y = data[1];
    theta = data[2];
    timestamp = data[3];
}
