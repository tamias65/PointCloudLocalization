#ifndef OCCUPANCYMAP_H
#define OCCUPANCYMAP_H

#include <string>
#include "Eigen/Dense"

class OccupancyMap
{
public:
    OccupancyMap();
    Eigen::MatrixXf prob;


protected:
    int resolution;
    int size_x;
    int size_y;
    float offset_x;
    float offset_y;
    int min_x;
    int max_x;
    int min_y;
    int max_y;

    void read_map(char *mapName);
};

#endif // OCCUPANCYMAP_H
