#include "individual.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Individual::Individual(int nreal) {
    numvars = nreal;
    vars = new double[nreal];
        
}

Individual::~Individual() {
    delete [] vars;
}


// /* id is the thread number */
void Individual::simulate(int id) {
        /* run simulations with vub = -34, 30, 26 */
    double vub[3] = {-34, -30, -26};
    string prog, sid, string, params, par, prog2, myfile;
    
    int i;
    
    for (int i = 0; i < 3; i ++) {
        prog = "./neuralsim -i";
        sid = to_string(id);
        params = " -vlb -60 -vub " + to_string(vub[i]) + " -p ";
            
        for (int j = 0; j < numvars; j++) {
            par = to_string(vars[j]);
            params += " " + par;
        }
        prog += " " + sid;
        prog += params;
        cout << prog << "\n";

        cout << endl;
        boost::scoped_array<char> writable(new char[prog.size() + 1]);
        std::copy(prog.begin(), prog.end(), writable.get());
        writable[prog.size()] = '\0'; // don't forget the terminating 0
        
        i = system(writable.get());
        if (i == 0) {
            cout << "Call to neuralsim successful\n";
        }
            //     /* call zfgenerator */
            //     //string prog2 = "./zfgenerator -f ";
        prog2 = "./zfgenerator -f SC";
        prog2 += sid;
        prog2 += ".asc";
        
        cout << prog2 << "\n";

        boost::scoped_array<char> writable2(new char[prog2.size() + 1]);
        std::copy(prog2.begin(), prog2.end(), writable2.get());
        writable2[prog2.size()] = '\0'; // don't forget the terminating 0
        i = system(writable2.get());
        if (i == 0) {
            cout << "Call to zfgenerator successful\n";
        }

        myfile = "SC";
        myfile += sid;
        myfile += "_zfstats.dat";
        
        cout << "Extracting zf curve attributes from " << myfile << "\n";
        cout << "Fmax is " <<  getFmax(myfile) << "\n";

    }
}




double Individual::getFmax(string myfile) {
    string line;
    ifstream zfstats(myfile);
    double *buff = new double[5];
    double fmax;
    
    if (zfstats.is_open()) {
        while ( zfstats.good()) {
            getline(zfstats, line);
            stringstream sstr2(line);
            double val;  
            int j = 0;
            
            while( sstr2 >> val) {
                buff[j++] = val;  /* stored as zmax,fmax, q, z10, fhalfwidth */
            }
        }    
    }
    zfstats.close();
    fmax = buff[1];
    delete [] buff;
    return fmax;
    
}


    
   
    
    
 

   
