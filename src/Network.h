//
//  Network.hpp
//  bnbnbnb
//
//  Created by David L Gibbs on 8/2/16.
//  Copyright © 2016 David L Gibbs. All rights reserved.
//

#ifndef Network_h
#define Network_h

#include "Node.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <Rcpp.h>

class Network {


private:
    std::string netname;
    std::vector<std::string> nodeNames;
    std::map<std::string, Node*> nodeList;

public:
    Network();
    Network(std::string);
    Rcpp::List run(int runs, int steps);
    void load_file(std::string filein);
    void load_list(std::vector<std::string>);
    string initState();
    string step();
    string stringState(int i);
    void printState(int);
};


#endif /* Network_h */
