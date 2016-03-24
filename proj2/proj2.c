#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "queue.c"
//#include "stats.c"

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

    /*
    queue testq;
    initialize(&testq);
    printf("testq: cnt=%d\n", testq.cnt);
    */

    if(argc < 3) {
        printf("Not enough parameters: file_name num_tellers\n");
        return 1;
    }
    char fname[1024];
    fname[0] = argv[1];
    // read data from the file
    FILE *fp;
    fp = fopen(fname, "r");
    int id = 5;
    int permin, percent;
    while (id > 0 ) {
        fscanf(fp, "%d  %d", &permin, &percent);
        printf("Read: %d    %d", permin, percent);
        id--;
    }


    return 0;
}

void simulation(int numOfTellers) {
    queue line;
    initialize(&line);

}
