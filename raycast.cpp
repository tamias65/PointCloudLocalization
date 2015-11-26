#include "raycast.h"
#include "Eigen/Dense"
#include <stdio.h>
#include <iostream>

#define PI 3.14159265

using namespace Eigen;

RayCast::RayCast(MatrixXf &map)
{
    this->map_ptr = &map;
    this->width = this->map_ptr->cols();
    this->height = this->map_ptr->rows();
    this->degrees_partition = 16;
    this->ray_cast.resize(this->height);
    for (int i = 0; i < this->height; ++i) {
        this->ray_cast[i].resize(this->width);
        for (int j = 0; j < this->width; ++j)
            this->ray_cast[i][j].resize(this->degrees_partition);
    }

    compute_ray_cast();
}

void RayCast::compute_ray_cast(){
     for(int i = 0; i < this->width; i++){
         for(int j = 0; j < this->height; j++){
             if(this->map_ptr->coeff(i,j)==-1.0){
                 for(int k = 0; k < this->degrees_partition; k++){
                     this->ray_cast[i][j][k] = -1;
                 }
             }else{

                 this->x0 = i;
                 this->y0 = j;

                 for(int k =0; k < this->degrees_partition; k++){
                     this->curr_i = i;
                     this->curr_j = j;
                     this->curr_k = k;

                     this->x1 = this->x0;
                     this->y1 = this->y0;
                     int tmp = x0;
                     bool hit = false;
                     int degrees =  360/this->degrees_partition*k;

                     while(hit == false){
                         if(degrees >= 0 && degrees < 45){
                             this->x1 = tmp + 1;
                             tmp = this->x1;
                             this->y1 = tan(degrees*PI/180)*(this->x1-this->x0)+(this->y0);
                         }else if(degrees >= 45 && degrees < 90){
                             this->y1 = tmp + 1;
                             tmp = this->y1;
                             this->x1 = (this->y1-this->y0)/tan(degrees*PI/180)+this->x0;
                         }else if(degrees >= 90 && degrees < 135){
                             this->y1 = tmp + 1;
                             tmp = this->y1;
                             this->x1 = (this->y1-this->y0)/tan(degrees*PI/180)+this->x0;
                         }else if(degrees >= 135 && degrees < 180){
                             this->x1 = tmp - 1;
                             tmp = this->x1;
                             this->y1 = tan(degrees*PI/180)*(this->x1-this->x0)+this->y0;
                         }else if(degrees >= 180 && degrees < 225){
                             this->x1 = tmp - 1;
                             tmp = this->x1;
                             this->y1 = tan(degrees*PI/180)*(this->x1-this->x0)+this->y0;
                         }else if(degrees >= 225 && degrees < 270){
                             this->y1 = tmp - 1;
                             tmp = this->y1;
                             this->x1 = (this->y1-this->y0)/tan(degrees*PI/180)+this->x0;
                         }else if(degrees >= 270 && degrees < 315){
                             this->y1 = tmp - 1;
                             tmp = this->y1;
                             this->x1 = ((this->y1-this->y0)/tan(degrees*PI/180))+this->x0;
                         }else if(degrees >= 315 && degrees < 360){
                             this->x1 = tmp - 1;
                             tmp = this->x1;
                             this->y1 = tan(degrees*PI/180)*(this->x1-this->x0)+this->y0;
                         }
                         hit = check_target();
                     }
                }
             }
         }
     }
     std::cout<<"Done building ray map"<<std::endl;
}

float RayCast::distance(){
    return sqrt(pow((float)(this->x1-this->x0),2)+pow((float)(this->y1-this->y0),2));
}

bool RayCast::check_target(){
    if(this->map_ptr->coeff(this->x1,this->y1) == 1.0 ||
             this->map_ptr->coeff(this->x1,this->y1) == -1.0 || !in_map()){
        this->ray_cast[this->curr_i][this->curr_j][this->curr_k] = distance();
        return true;
    }else{
        return false;
    }
}

bool RayCast::in_map(){
    if(this->x1 >= 0 && this->x0 < this->map_ptr->cols() &&
        this->y1 >= 0 && this->y1 < this->map_ptr->rows()){
        return true;
    }else{
        return false;
    }
}
