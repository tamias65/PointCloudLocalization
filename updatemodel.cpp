#include "updatemodel.h"
#include "Eigen/Dense"
#include <vector>
#include "laser.h"

#define PI 3.14159265

using namespace Eigen;
using namespace std;

UpdateModel::UpdateModel()
{
    this->n_beams = 8;
    this->degrees_partition = 16;
    this->z_max = 820; //in cm

    //need to tune these
    this->w_hit = .25;
    this->w_short = .25;
    this->w_max = .25;
    this->w_rand = .25;
    this->lambda_short = 1.0;
    this->var_hit = 1.0;
}


double UpdateModel::probability(MatrixXf& particle, Laser& scan ,
                              vector<vector<vector<float> > >& ray_cast){
    double prob = 1;
    int offset = find_offset(particle(2));
    for(int i = 0; i < this->n_beams; i++){
        int angle = offset-4+this->n_beams;
        if(angle < 0){
            angle = this->degrees_partition+angle;
        }else if(angle > this->degrees_partition-1){
            angle = angle-this->degrees_partition;
        }

        this->curr_z_true = compute_z_true(particle, angle, ray_cast);
        this->curr_z = (float)scan.distance[(int)(i*180/this->n_beams)];
        double p_hit = calc_p_hit();
        double p_max = calc_p_max();
        double p_rand = calc_p_rand();
        double p_short= calc_p_short();
        double prob_beam = this->w_hit*p_hit+this->w_short*p_short+
                            this->w_max*p_max+this->w_rand+p_rand;
        prob*=prob_beam;
    }
    return prob;
}

int UpdateModel::find_offset(float theta){
    double min_diff;
    double offset;

    for(int i = 0; i < this->degrees_partition; i++){
        double angle = i*PI/this->degrees_partition;
        double diff = fabs(angle - theta);
        if (diff < min_diff || i == 0){
            min_diff = diff;
            offset = i;
        }
    }
    return offset;
}

float UpdateModel::compute_z_true(MatrixXf& particle, int angle,
                                  vector<vector<vector<float> > >& ray_cast){
    return ray_cast[particle(0)][particle(1)][angle];
}

double UpdateModel::calc_p_hit(){
    double n = normalizer;
    if(this->curr_z >= 0 && this->curr_z <= this->z_max){
        return n*(1/(sqrt(2*PI*this->var_hit))*
                  exp(-pow(this->curr_z-this->curr_z_true,2)/(2*this->var_hit)));
    }else{
        return 0;
    }
}

double UpdateModel::calc_p_short(){
    double n = 1/(1-exp(-this->lambda_short*this->curr_z_true));
    if(this->curr_z >= 0 && this->curr_z <= this->curr_z_true){
        return n*this->lambda_short*exp(-this->lambda_short*this->curr_z);
    }else{
        return 0;
    }
}

double UpdateModel::calc_p_max(){
    if(this->curr_z == this->z_max){
        return 1;
    }else{
        return 0;
    }
}

double UpdateModel::calc_p_rand(){
    if(this->curr_z >= 0 && this->curr_z < this->z_max){
        return 1/this->z_max;
    }else{
        return 0;
    }

}


