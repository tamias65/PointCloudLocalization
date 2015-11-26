#ifndef MAP_H
#define MAP_H

#include <string>
#include "Eigen/Dense"

class Map
{
public:
    Map();

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

    Eigen::MatrixXf prob;

    int read_map(char *mapName);
};

#endif // MAP_H
