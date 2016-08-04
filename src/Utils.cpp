//
//  utils.cpp
//  bnbnbnb
//
//  Created by David L Gibbs on 8/3/16.
//  Copyright © 2016 David L Gibbs. All rights reserved.
//


//http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring

//http://stackoverflow.com/questions/236129/split-a-string-in-c

#include "Utils.h"
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

using namespace std;



void splitTrim(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(trim(item));
    }
}


vector<string> splitTrim(const string &s, char delim) {
    vector<string> elems;
    splitTrim(s, delim, elems);
    return elems;
}



void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

// trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}


// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
