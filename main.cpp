#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <iostream>
#include "data.h"
#include "occupancymap.h"
#include "visualization.h"
#include <Eigen/Dense>

using namespace Eigen;

int main(){

    //read in the datalog into odom & laser scan
    Data data;

    cout << "There are " << data.odoms.size() << " odom particles" << endl;
    cout << "There are " << data.lasers.size() << " laser particles" << endl;

    //create occupancy map
    OccupancyMap map;

    //for every point, transform laser distance from laser frame to odom frame

    //create mapping

    //iterate to fix weighting.

    MatrixXf particles(1,3);
    particles(0,0) = 2000;
    particles(0,1) = 2000;
    particles(0,2) = 0;

    //create image using particles
    Visualization frame(10);
    frame.curr_frame = 1;
    frame.create_frame(particles);

    //create video
    frame.create_video();

    return 0;

}

