//
//  node.h
//  bnbnbnb
//
//  Created by David L Gibbs on 8/2/16.
//  Copyright © 2016 David L Gibbs. All rights reserved.
//

#ifndef node_h
#define node_h

#import <vector>
#import <map>
#import "BoolFun.h"

class Node {
    
private:
    BoolFun bff;
    string  name;
    vector<string> inputs;
    int     val;
    int     next;
    
public:
    Node();
    Node(string n, string i, string s);
    Node(vector<string>);


    void compute(map<string,Node*> nodeList);
    int  getVal();
    void setVal(int);
    void update();
};



#endif /* node_h */
