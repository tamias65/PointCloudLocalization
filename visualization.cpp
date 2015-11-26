#include "visualization.h"
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <sstream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "Eigen/Dense"

using namespace Eigen;
using namespace cv;

Visualization::Visualization(int scale)
{
    this->mapFileName = "/home/alvin/RoboStatProject4/PointCloudLocalization/data/map/wean.png";
    this->map = read_map_image(this->mapFileName);
    this->scale = scale;
}

Mat Visualization::read_map_image(char* mapImage){
    Mat image = imread(mapImage, 1);
    if(!image.data )
    {
      printf( "No image data \n" );
    }
    return image;
}

void Visualization::create_frame(MatrixXf &particles){
    draw_particles(particles);

    std::ostringstream currFrame;
    currFrame << "/home/alvin/RoboStatProject4/PointCloudLocalization/images/frame" << this->curr_frame << ".jpg";

    const char* newFrameName = currFrame.str().c_str();
    imwrite(newFrameName, this->map);
    namedWindow(newFrameName, CV_WINDOW_AUTOSIZE );
    imshow(newFrameName, this->map);
    waitKey(0);
}

void Visualization::draw_particles(MatrixXf &particles){
    for (int i = 0; i < particles.rows(); i++){
        int x = particles(i,0)/scale;
        int y = particles(i,1)/scale;
        std::cout<<x<<std::endl;
        std::cout<<y<<std::endl;
        circle(this->map, Point(x,y), 1/2, Scalar(0,0,255));
    }
}

void Visualization::create_video(){
    VideoCapture in_capture("/home/alvin/RoboStatProject4/PointCloudLocalization/images/frame%d.jpg");
    Mat img;

    VideoWriter out_capture("/home/alvin/RoboStatProject4/PointCloudLocalization/images/video.avi", CV_FOURCC('M','J','P','G'), 30, Size(802,447));

    while (true)
    {
        in_capture >> img;
        if(img.empty())
            break;

        out_capture.write(img);
    }
}
