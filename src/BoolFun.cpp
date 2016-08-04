
#include <string>
#include <iostream>
#include "BoolFun.h"
#include "Utils.h"

using namespace std;


BoolFun::BoolFun()
{
    boolstr = "";
    numvars = 0;
}


BoolFun::BoolFun(string vars, string fun){
    numvars = (int) splitTrim(vars,',').size();
    loadFun(vars,fun);
}


void BoolFun::loadFun(string vars, string fun){
    
    boolstr = fun;
    varstr  = vars;
    
    // compile the function
    // the vars are the order that we need to set var values
    size_t err = parser.parse(byteCode, boolstr, varstr);
    
    if (err) {
        cout << "Error parsing expression: " << fun << " with vars: " << vars << "\n";
        parser.errMessage(err);
        exit(1);
    }
}


int BoolFun::exec(vector<int> vals)
{

    // Set variable values BEFORE final bytecode execution. Same principle for more variables
    for(int i = 0; i < vals.size(); ++i) {
        byteCode.var[i] = vals.at(i);   // x is 1st in the above variables list, so it has index 0
    }
    // And execute the bytecode with the variable/constant values set above
    int result = (int) byteCode.run();
    return(result);
}


void BoolFun::printFun() {
    cout << boolstr << "\n";
}

