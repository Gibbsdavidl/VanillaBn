#include <iostream>
#include <fstream>
#include <string>
#include "BoolFun.h"
#include "atmsp.h"
#include "Network.h"
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
List runNet(const StringVector& nodeData,
            const NumericVector& runs,
            const NumericVector& steps)
{
    std::vector<std::string> nodeStrings = Rcpp::as<std::vector<std::string>>(nodeData);
    int runInt = Rcpp::as<int>(runs);
    int stepInt = Rcpp::as<int>(steps);

    List states(runs);

    Network n("");
    n.load_list(nodeStrings);
    states = n.run(runInt, stepInt);

    return(states);
}
