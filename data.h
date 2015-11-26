#ifndef DATA_H
#define DATA_H

#include <vector>
#include "odom.h"
#include "laser.h"
#include <string>

using namespace std;

class Data
{
public:
    vector<Odom*> odoms;
    vector<Laser*> lasers;

    Data();
    void read_data();

protected:
    string file [4];
    int nFilesToUse;

    void parse(char, double[]);
};

#endif // DATA_H
