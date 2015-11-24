#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include "parsedata.h"
#include <iostream>

using namespace cv;

int main(){

    //read in the datalog into odom & laser scan
    ParseData data;

    cout << "There are " << data.odoms.size() << " odom points" << endl;
    cout << "There are " << data.lasers.size() << " laser points" << endl;

    //read in occupancy map as weight?

    //for every point, transform laser distance from laser frame to odom frame

    //create mapping

    //iterate to fix weighting.

    return 0;

}

