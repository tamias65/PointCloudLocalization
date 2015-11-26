#include "data.h"
#include <fstream>
#include "laser.h"
#include "odom.h"
#include <string>
#include <iostream>
#include <sstream>

Data::Data()
{
    this->file[0] = "../PointCloudLocalization/data/log/robotdata1.log";
    this->file[1] = "../PointCloudLocalization/data/log/ascii-robotdata2.log";
    this->file[2] = "../PointCloudLocalization/data/log/ascii-robotdata3.log";
    this->file[3] = "../PointCloudLocalization/data/log/ascii-robotdata4.log";

    this->nFilesToUse = 4;

    read_data();
}

void Data::read_data(){
    for (int i = 0; i < this->nFilesToUse; i++){
        ifstream inputFile(this->file[i].c_str());
        if(!inputFile.is_open()) {
            fprintf(stderr, "# Could not open file %s\n", this->file[i].c_str());
        }
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

void Data::parse(char sensor, double data[]){
    switch (sensor){
        case 'O':
        {
            Odom odom(data);
            this->odoms.push_back(&odom);
            break;
        }
        case 'L':
        {
            Laser laser(data);
            this->lasers.push_back(&laser);
            break;
        }
    }
}
