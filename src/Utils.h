//
//  utils.hpp
//  bnbnbnb
//
//  Created by David L Gibbs on 8/3/16.
//  Copyright © 2016 David L Gibbs. All rights reserved.
//

#ifndef Utils_h
#define Utils_h

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void splitTrim(const string &s, char delim, vector<string> &elems);
vector<string> splitTrim(const string &s, char delim);

void split(const string &s, char delim, vector<string> &elems);
vector<string> split(const string &s, char delim);

static inline std::string &rtrim(std::string &s);
static inline std::string &ltrim(std::string &s);
static inline std::string &trim(std::string &s);


#endif /* Utils_h */
