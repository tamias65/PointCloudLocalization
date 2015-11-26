#include "visualization.h"
#include "stdio.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "Eigen/Dense"

using namespace Eigen;
using namespace cv;

Visualization::Visualization()
{
    this->mapImage = "/home/alvin/RoboStatProject4/PointCloudLocalization/data/map/wean.png";
    this->map = read_map_image(this->mapImage);
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
//    char currFrame = itoa()
    imwrite( "/home/alvin/RoboStatProject4/PointCloudLocalization/images/frame1.jpg", this->map);
    namedWindow( "Map", CV_WINDOW_AUTOSIZE );
    imshow( "Map", this->map);
    waitKey(0);
}
