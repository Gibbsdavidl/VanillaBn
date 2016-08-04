//
//  Node.cpp
//  bnbnbnb
//
//  Created by David L Gibbs on 8/2/16.
//  Copyright © 2016 David L Gibbs. All rights reserved.
//

#include <map>
#include <vector>
#include <stdio.h>
#include "Node.h"
#include "Utils.h"

Node::Node()
{
    val = 0;
    next = 0;
}


Node::Node(string aname, string aninput, string aboolstr)
{
    // val init?
    val  = 0;
    next = 0;

    // set the node name
    name=aname;

    // vector of input nodes, are found in nodeNames, maps to nodeList
    inputs = splitTrim(aninput, ',');

    // pass remainder of the string to bool fun
    bff.loadFun(aninput, aboolstr);
}


Node::Node(vector<string> vs)
{
    // val init?
    val  = 0;
    next = 0;

    // set the node name
    name=vs[0];

    // vector of input nodes, are found in nodeNames, maps to nodeList
    inputs = splitTrim(vs[1], ',');

    // generate the bool function
    bff.loadFun(vs[1], vs[2]);
}


void Node::compute(map<string,Node*> nodeList)
{
    // construct a vector of node values
    vector<int> vals;
    for(string &i : inputs) {
        vals.emplace_back(nodeList.at(i)->getVal());
    }

    // then ask boolfun to exec, save as next value
    next = bff.exec(vals);
}


int Node::getVal()
{
    return(val);
}

void Node::setVal(int x)
{
    val = x;
}

void Node::update()
{
    val = next;
}
