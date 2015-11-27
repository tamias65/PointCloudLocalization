#ifndef UPDATEMODEL_H
#define UPDATEMODEL_H

#include "Eigen/Dense"
#include <vector>
#include "laser.h"

using namespace Eigen;
using namespace std;

class UpdateModel
{
public:
    UpdateModel();
protected:
    int degrees_partition;
    int n_beams;
    float z_max;
    float curr_z_true;
    float curr_z;
    double w_hit;
    double w_short;
    double w_max;
    double w_rand;
    double lambda_short;
    double var_hit;

    double probability(MatrixXf&, Laser&, vector<vector<vector<float> > >&);
    int find_offset(float);
    float compute_z_true(MatrixXf&, int, vector<vector<vector<float> > >&);
    double calc_p_hit();
    double calc_p_max();
    double calc_p_short();
    double calc_p_rand();
};

#endif // UPDATEMODEL_H
