#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "Eigen/Dense"

using namespace cv;

class Visualization
{
public:
    Visualization();
    void create_frame(Eigen::MatrixXf &);

    int curr_frame;

protected:
    char* mapImage;
    Mat map;

    Mat read_map_image(char*);
};

#endif // VISUALIZATION_H
