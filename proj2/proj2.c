#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "queue.c"
//#include "stats.c"

#define AVG_SERVICE 2.0
#define NUM_ENTRIES 5

int permin_arr[NUM_ENTRIES];

void simulation(int numOfTellers);

double expdist (double mean) {
    //TODO improve random
    double r = rand();
    r /= RAND_MAX;
    return -mean * log(r);
}

int main(int argc, char* argv[]) {

    srand(time(NULL));

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
    // read data from the file
    FILE *fp;
    fp = fopen(argv[1], "r");
    int id = 0;
    int permin, percent;
    int prev = 0;
    while (id < NUM_ENTRIES ) {
        fscanf(fp, "%d  %d\n", &permin, &percent);
        printf("Read: %d    %d\n", permin, percent);
        permin_arr[id] = prev + percent;
        prev += percent;
        id++;
    }

    printf("permin_arr[0] = %d\n", permin_arr[0]);
    printf("permin_arr[1] = %d\n", permin_arr[1]);
    printf("permin_arr[2] = %d\n", permin_arr[2]);
    printf("permin_arr[3] = %d\n", permin_arr[3]);
    printf("permin_arr[4] = %d\n", permin_arr[4]);

    int num_tellers = argv[2];
    simulation(num_tellers);


    return 0;
}

void simulation(int numOfTellers) {
    queue line;
    initialize(&line);

    int id = 0;
    while(id < 10) {
        int c = get_customers();
        printf("c:%d\n", c);
        id++;
    }

}

int get_customers() {

    int random = rand() % 100 + 1;
    printf("random:%d\n", random);
    int id = 0;
    while(id < NUM_ENTRIES) {
        if(random <= permin_arr[id])
            return id;
        id++;
    }

    return 0;
}
