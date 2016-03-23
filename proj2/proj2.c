#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <queue.h>
//#include <stats.h>

#define AVG_SERVICE 2.0

void simulation(int numOfTellers);

double expdist (double mean) {
    //TODO improve random
    double r = rand();
    r /= RAND_MAX;
    return -mean * log(r);
}

int main(int argc, char* argv[]) {

    double t;
    // ...
    t = expdist (AVG_SERVICE);
    printf("t:%f\n", t);
    // ..

}

void simulation(int numOfTellers) {

}
