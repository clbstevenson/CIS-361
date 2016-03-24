#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "queue.c"
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

    queue testq;
    initialize(&testq);
    printf("testq: cnt=%d\n", testq.cnt);

    return 0;
}

void simulation(int numOfTellers) {

}
