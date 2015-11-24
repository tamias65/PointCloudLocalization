#ifndef PARSEDATA_H
#define PARSEDATA_H

#include <vector>
#include "odomdata.h"
#include "laserdata.h"
#include <string>

using namespace std;

class ParseData
{
public:
    ParseData();
    static string file [4];
    vector<OdomData*> odoms;
    vector<LaserData*> lasers;
    int nFilesToUse;
    void parse(char, double[]);
};

#endif // PARSEDATA_H
