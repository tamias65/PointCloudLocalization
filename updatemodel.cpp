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
    this->lambda_short = 1;
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
    VectorXf angles(this->degrees_partition);
    VectorXf vTheta(this->degrees_partition);
    angles(0) = 0;
    angles(1) = PI/16;
    angles(2) = 2*PI/16;
    angles(3) = 3*PI/16;
    angles(4) = 4*PI/16;
    angles(5) = 5*PI/16;
    angles(6) = 6*PI/16;
    angles(7) = 7*PI/16;
    angles(8) = 8*PI/16;
    angles(9) = 9*PI/16;
    angles(10) = 10*PI/16;
    angles(11) = 11*PI/16;
    angles(12) = 12*PI/16;
    angles(13) = 13*PI/16;
    angles(14) = 14*PI/16;
    angles(15) = 15*PI/16;

    vTheta.setConstant(theta);
    angles = angles-vTheta;
    angles.cwiseAbs();
    int offset;
    angles.minCoeff(offset);
    return offset;
}

float UpdateModel::compute_z_true(MatrixXf& particle, int angle, vector<vector<vector<float> > >& ray_cast){
    return ray_cast[particle(0)][particle(1)][angle];
}

double UpdateModel::calc_p_hit(){
    n = normalizer;
    if(this->curr_z >= 0 && this->curr_z <= this->z_max){
        return = n*(1/(sqrt(2*pi*var_hit))*exp(-(this->curr_z-this->curr_z_true)^2/(2*var_hit)));
    }else{
        return = 0;
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


