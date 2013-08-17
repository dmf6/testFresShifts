#include "population.h"

using namespace std;

int main() {
        /* create population object */
    Population p1(16, 15);
    
        /* read in parameters */
    ifstream test("test.dat");
    p1.readPars(test);
    test.close();

        //Run thousands of simulations as fast as possible!!!!!
    p1.simulate();

        /* for each model, print fmax for each upper voltage bound */
    ofstream o1;
    o1.open("fmax_data.dat", ios::app);
    p1.printFmax(o1);
    
    return 0;

}
