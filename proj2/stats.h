/* Header for displaying statistics about the day */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct day_stats {
    int  num_customers;
    double  avg_wait;
    int  max_wait;
    double avg_len; 
    int max_len;
};
typedef  struct day_sats  day_stats;

void initialize(day_stats *d);
void reset(day_stats *d);
void update(int n, double avg_w, int max_w, double avg_l, int max_l, 
    day_stats *d);
void update_wait(int n, int new_wait);
void update_line(int new_len);

void print_info(day_stats *d); 
