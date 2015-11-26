#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "Eigen/Dense"

using namespace cv;

class Visualization
{
public:
    Visualization(int);
    void create_frame(Eigen::MatrixXf &);
    void create_video(int, int);

    int curr_frame;
    Mat map;

protected:
    char* mapFileName;
    int scale;

    Mat read_map_image(char*);
    void draw_particles(Eigen::MatrixXf &);
};

#endif // VISUALIZATION_H
