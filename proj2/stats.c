/* Implementation of the stats header */

#include "stats.h"

void initialize(day_stats *d) {
    
    d -> num_customers = 0;
    d -> avg_wait = 0.0;
    d -> max_wait = 0;
    d -> avg_len = 0.0;
    d -> max_len = 0;
}

void reset(day_stats *d) {
    initialize(d);
}

void update(int n, double avg_w, int max_w, double avg_l, int max_l,
        day_stats *d) {
    d -> num_customers = n;
    d -> avg_wait = avg_w;
    d -> max_wait = max_w;
    d -> avg_len = avg_l;
    d -> max_len = max_l;
}

void update_wait(int n, int new_wait, day_stats *d) {
    d -> num_customers += n; 
    if(new_wait > d -> max_wait)
       d -> max_wait = new_wait;
    double new_avg = (d -> avg_wait + new_wait) / 2;
    d -> avg_wait = new_avg;
}

void update_line(int new_len) {
    if(new_len > d -> max_len)
       d -> max_len = new_len;
    double new_avg = (d -> avg_len + new_len) / 2;
    d -> avg_len = new_avg;
}

void print_info(day_stats *d) {
    printf("Stats: %d customers\n\taverage wait: %f, max wait: %d\n\taverage line length: %f, max line length: %d\n",
            d -> num_customers, d -> avg_wait, d -> max_wait,
            d -> avg_len, d -> max_len);
}


