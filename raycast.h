#ifndef RAYCAST_H
#define RAYCAST_H

#include "Eigen/Dense"
#include <vector>

using namespace Eigen;
using namespace std;

class RayCast
{
public:
    RayCast(MatrixXf &);
    vector<vector<vector<float> > > ray_cast;

    //MatrixXf<Array(360)> ray_cast;

protected:
    MatrixXf* map_ptr;
    int degrees_partition;
    int width;
    int height;

    int x0;
    int y0;
    int x1;
    int y1;
    int curr_i;
    int curr_j;
    int curr_k;

    float distance();
    bool check_target();
    bool in_map();
    void compute_ray_cast();
};

#endif // RAYCAST_H
