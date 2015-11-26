//#include "updatemodel.h"
//#include "Eigen/Dense"

//using namespace Eigen;

//UpdateModel::UpdateModel()
//{
//    z_max = 820; //in cm
//}


//void probability(){
//    float prob = 1;
//    for(int i = 1; i < nBeam; i++){
//        float z_true = compute_z_true();
//        prob_beam = w_hit*p_hit+w_short*p_short+w_max*p_max+w_rand+p_rand;
//        prob*=prob_beam;
//    }
//    return prob;
//}

//void compute_z_true(MatrixXf& particle){

//}

//void p_hit(){
//    n = normalizer;
//    if(z >= 0 && z <= z_max){
//        p_hit = n*(1/(sqrt(2*pi*var_hit))*exp(-(z-z_true)^2/(2*var_hit)));
//    }else{
//        p_hit = 0;
//    }
//}

//void p_short(){
//    n = 1/(1-exp(-lambda_short*z_true));
//    if(z >= 0 && z <= z_true){
//        p_short = n*lambda_short*exp(-lambda_short*z);
//    }else{
//        p_short = 0;
//    }
//}

//void p_max(){
//    if(z == z_max){
//        p_max = 1;
//    }else{
//        p_max = 0;
//    }
//}

//void p_rand(){
//    if(z >= 0 && z < z_max){
//        p_rand = 1/z_max
//    }else{
//        p_rand = 0;
//    }

//}


