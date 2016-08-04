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

class Network {


private:
    std::string netname;
    std::vector<std::string> nodeNames;
    std::map<std::string, Node*> nodeList;

public:
    Network();
    Network(std::string);
    void run(int, int);
    void load_file(std::string filein);
    void load_list(std::vector<std::string>);
    void initState();
    void step();
    void printState();
};


#endif /* Network_h */
