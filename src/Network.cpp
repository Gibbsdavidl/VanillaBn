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
#include <Rcpp.h>

Network::Network()
{
    netname = "net1";
}


Network::Network(std::string anetname)
{
    netname = anetname;
}


Rcpp::List Network::run(int runs, int steps)
{
    Rcpp::List states(runs);
    string curr = "x"; // current network state
    string last = "y"; // network state at last step
    for (int ri = 0; ri < runs; ++ri){
        vector<string> res0;  // this trajectory
        res0.push_back(initState());
        for (int si = 0; si < steps; ++si) {
            curr = step();
            res0.push_back(curr);
            if (last == curr) {break;}
            else {last = curr;}
        }
        states[ri] = res0;
    }
    return(states);
}


string Network::step()
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

    return(stringState(0));
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


string Network::initState()
{
    //http://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist01(0,1);

    for( map<string,Node*>::iterator it = nodeList.begin(); it != nodeList.end(); ++it )
    {
        it->second->setVal(dist01(rng));
    }

    return(stringState(0));
}


string Network::stringState(int i)
{
    string state;

    for( map<string,Node*>::iterator it = nodeList.begin(); it != nodeList.end(); ++it )
    {
        state += std::to_string(it->second->getVal());
    }

    return(state);
}


void Network::printState(int i)
{
    stringstream state;

    if (i == 0) {
        for( map<string,Node*>::iterator it = nodeList.begin(); it != nodeList.end(); ++it )
        {
            state << it->second->getName() << "\t";
        }
        state << "\n";
    }

    for( map<string,Node*>::iterator it = nodeList.begin(); it != nodeList.end(); ++it )
    {
        state << it->second->getVal() << "\t";
    }

    state << "\n";
    std::cout << state.str();
}
