#include "odomdata.h"

OdomData::OdomData(double data[])
{
    x = data[0];
    y = data[1];
    theta = data[2];
    timestamp = data[3];
}
