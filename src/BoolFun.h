#ifndef BOOLFUN_H
#define BOOLFUN_H

#include <string>

#include "atmsp.h"
#include <vector>

using namespace std;

class BoolFun {

private:
    ATMSP<bool> parser;
    ATMSB<bool> byteCode;
    string boolstr;
    string varstr;
    int    numvars;

public:
    BoolFun();
    BoolFun(string s, string t);

    void loadFun(string s, string t);
    void printFun();
    int  exec(vector<int>);
};

#endif
