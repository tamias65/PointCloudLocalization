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
    Data();
    static string file [4];
    vector<Odom*> odoms;
    vector<Laser*> lasers;
    int nFilesToUse;
    void parse(char, double[]);
};

#endif // DATA_H
