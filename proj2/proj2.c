#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "queue.h"
//#include "stats.c"

#define AVG_SERVICE 2.0
#define TOTAL_TIME 480
#define NUM_ENTRIES 5

struct teller {
    int busy;
    data customer;
    double next_service_time;
    double exit_time;
};

typedef struct teller teller;

int permin_arr[NUM_ENTRIES];

void simulation(int numOfTellers);

double expdist (double mean) {
    //TODO improve random
    double r = rand();
    r /= RAND_MAX;
    return -mean * log(r);
}

void initialize_tellers(teller * tellers, int size) {
    printf("start init tellers \n");
    int id = 0;
    while(id < size) {
        (*(tellers + id)).busy = 0;
        (*(tellers + id)).customer = NULL;
        (*(tellers + id)).next_service_time = expdist(AVG_SERVICE);
        (*(tellers + id)).exit_time = 0;
        id++;
    }
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

    //simulation(num_tellers);
    simulation(4);
    //print stats
    //simulation(5);
    //print stats
    //simulation(6);
    //print stats
    //simulation(7);
    //print stats


    return 0;
}

void simulation(int numOfTellers) {
    queue line;
    initialize(&line);
    printf("after init\n");

    
    printf("A\n");
    //boolean * tellers;
    //int tellers[numOfTellers];
    //teller tellers[numOfTellers]; 
    teller * tellers;
    printf("B\n");
    //initialize_tellers(tellers, numOfTellers);
    printf("C\n");
    int id = 0; teller tellers2[numOfTellers];
    printf("E\n");
    for(id=0; id < numOfTellers; id++) {
        tellers2[id].busy = 0;
    }
    printf("D\n");
    //initialize array of bools to false
    /*
    while(id < numOfTellers) {
        tellers[id] = 0;
        id++;
    }
    */

    int min = 0;
    //continue for the whole day
    while (min < TOTAL_TIME) {
        int c = get_customers();
        printf("c:%d;\n", c);
        while(c > 0) {
            data d = min + "" + c;
            printf("enqueue \n");
            enqueue(d, &line);
            c --;
        }
        printf("line size = %d\n", line.cnt);

        min++;
    }

    /*
    int id = 0;
    while(id < 10) {
        int c = get_customers();
        printf("c:%d\n", c);
        id++;
    }
    */

}

int get_customers() {

    int random = rand() % 100 + 1;
    printf("random:%d\n", random);
    int id = 0;
    while(id < NUM_ENTRIES) {
        if(random <= permin_arr[id]) {
            printf("return: %d\n", id);
            return id;
        }
        id++;
    }
    printf("return: %d\n", id);

    return id;
}
