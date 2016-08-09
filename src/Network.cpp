//
//  Network.cpp
//  bnbnbnb
//
//  Created by David L Gibbs on 8/2/16.
//  Copyright © 2016 David L Gibbs. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Network.h"
#include "Utils.h"
#include <random>

Network::Network()
{
    netname = "net1";
}


Network::Network(std::string anetname)
{
    netname = anetname;
}


void Network::run(int runs, int steps)
{
    for (int ri = 0; ri < runs; ++ri){
        initState();
        for (int si = 0; si < steps; ++si) {
            printState(si);
            step();
        }
    }


}


void Network::step()
{
    // for each node
    //  compute and set next
    for( map<string,Node*>::iterator it = nodeList.begin(); it != nodeList.end(); ++it )
    {
        it->second->compute(nodeList);
    }

    // then update each node.
    for( map<string,Node*>::iterator it = nodeList.begin(); it != nodeList.end(); ++it )
    {
        it->second->update();
    }

}


void Network::load_file(std::string filein)
{
    std::ifstream fin (filein);

    for (std::string line; getline(fin, line); ) {
        vector<string> nodeData = splitTrim(line, ';');
        Node* n = new Node(nodeData);
        nodeList.insert(std::pair<string, Node*>(nodeData[0], n));
        nodeNames.push_back(nodeData[0]);
    }

    return;
}


void Network::load_list(std::vector<std::string> strings)
{
    for (string &s : strings) {
        vector<string> thisData = splitTrim(s, ';');
        Node* n = new Node(thisData);
        nodeList.insert(std::pair<string, Node*>(thisData[0], n));
        nodeNames.push_back(thisData[0]);
    }
}

void Network::initState()
{
    //http://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist01(0,1);

    for( map<string,Node*>::iterator it = nodeList.begin(); it != nodeList.end(); ++it )
    {
        it->second->setVal(dist01(rng));
    }
}


void Network::printState(int i)
{
    stringstream state;

    if (i == 0) {
        for( map<string,Node*>::iterator it = nodeList.begin(); it != nodeList.end(); ++it )
        {
            state << it->second->getName() << "\t";
        }
    }

    for( map<string,Node*>::iterator it = nodeList.begin(); it != nodeList.end(); ++it )
    {
        state << it->second->getVal() << "\t";
    }

    state << "\n";
    std::cout << state.str();
}
