#include "worker.h"


    /* each thread will be assigned a portion of the
     * individual array to simulate */
Worker::Worker(int id, boost::mutex* lock, int begin, int end, Population *pop) :
    _id(id), _lock(lock), _begin(begin), _end(end), _pop(pop) {}

Worker::~Worker()  {
}

void Worker::operator()() {
    for (int i = _begin; i < _end; i++) {
            /* Current thread will simulate child strings from begin
             * to end */
       
            /* the simulate method runs the simulator, zfgenerator 3 times
             * lower voltage bound will be -60mV in all cases
             * (1) the upper voltage bound = -34
             * (2) the upper voltage bound = -30
             * (3) the upper voltage bound = -26
             *
             * Store the fmax shift in a variable associated with the
             * Individual object
             */
        
       
        Individual *ind = _pop->ind[i];
        ind->simulate(_id);
        _lock->lock(); //acquire lock
   
        cout << "Thread " << _id << " is simulating child at position " << i << "\n";
        _lock->unlock();  //release lock
    }
    
}
