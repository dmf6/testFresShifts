#ifndef __INDIVIDUAL_H
#define __INDIVIDUAL_H

#include <boost/smart_ptr.hpp>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace boost;

class Individual {
  public:
    double *vars; // stores params
    int numvars;
    double fmax[3];
    
    Individual(int nreal);
    ~Individual();
    void initialize();
    void evaluate();
    void simulate(int id);
    double getFmax(string myfile);
};
#endif
