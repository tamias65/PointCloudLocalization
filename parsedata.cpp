#include "parsedata.h"
#include <fstream>
#include "laserdata.h"
#include "odomdata.h"
#include <string>
#include <iostream>
#include <sstream>

ParseData::ParseData()
{
    string file [] = {"/home/alvin/RoboStatProject4/PointCloudLocalization/data/log/robotdata1.log",
                      "/home/alvin/RoboStatProject4/PointCloudLocalization/data/log/ascii-robotdata2.log",
                      "/home/alvin/RoboStatProject4/PointCloudLocalization/data/log/ascii-robotdata3.log",
                      "/home/alvin/RoboStatProject4/PointCloudLocalization/data/log/ascii-robotdata4.log"};
    int nFilesToUse = 1;

    for (int i = 0; i < nFilesToUse; i++){
        ifstream inputFile(file[i].c_str());
        string line;

        while (getline(inputFile, line)){
            istringstream ss(line);
            char sensor;
            int j = 0;
            double e;
            double data [187];

            ss >> sensor;
            while (ss >> e){
                data[j] = e;
                j++;
            }

            parse(sensor, data);
        }
    }
}

void ParseData::parse(char sensor, double data[]){
    switch (sensor){
        case 'O':
        {
            OdomData odom(data);
            odoms.push_back(&odom);
            break;
        }
        case 'L':
        {
            LaserData laser(data);
            lasers.push_back(&laser);
            break;
        }
    }
}
