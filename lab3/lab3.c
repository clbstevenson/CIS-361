// lab3.c - measure execution time of C code

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main ()
{
	const int MaxSize = 25000;
	int i, j, temp;


	// Part one: processing a statically allocated array


    //start time for initializing static array
    clock_t s_total_begin = clock();
    clock_t s_init_begin = clock();
	int staticArray[MaxSize];		// declare an array 

	for (i=0; i<MaxSize; i++)		// initialize the array with a
		staticArray[i] = MaxSize-i;	// descending sequence of values
    clock_t s_init_end = clock();

    //start time for sorting static array
    clock_t s_begin = clock();
	for (i=0; i<MaxSize-1; i++)		// bubble sort data in the array
		for (j=MaxSize-1; j>i; j--)
			if (staticArray[j-1] > staticArray[j])
			{
				temp = staticArray[j-1];
				staticArray[j-1] = staticArray[j];
				staticArray[j] = temp;
			}

    //end time for sorting static array
    clock_t s_end = clock();
    clock_t s_total_end = clock();

	// Part two: processing a dynamically allocated array

    //start time for initializing dynamic array
    clock_t d_total_begin = clock();
    clock_t d_init_begin = clock();
    int * dynamicArray;
    dynamicArray = (int*) malloc(MaxSize * sizeof(int));

    if(dynamicArray == NULL) {
        //ran out of memory
        exit(1);
    }

    //intialize the dynamic array
	for (i=0; i<MaxSize; i++)		// initialize the array with a
        *(dynamicArray+i) = MaxSize - i; // descending sequence of values
    clock_t d_init_end = clock();

    //start time for sorting dynamic array
    clock_t d_begin = clock();
    //bubble sort the dynamic array
    for(i=0; i < MaxSize-1; i++) {
        for(j=MaxSize-1; j>i; j--) {
            if(*(dynamicArray+(j-1)) > *(dynamicArray+j)) {
                temp = *(dynamicArray+(j-1));
                *(dynamicArray+(j-1)) = *(dynamicArray+j);
                *(dynamicArray+j) = temp;
            }
        }
    }
    //end time for sorting dynamic array
    clock_t d_end = clock();
    clock_t d_total_end = clock();

    //remember to free the dynamic array
    free(dynamicArray);


	// Display the amount of time used for each part above
    printf("Static: Initialize Time used: %lf%s\n", 
            (double)(s_init_end - s_init_begin) / CLOCKS_PER_SEC, ", Seconds");
    printf("Dynamic: Iniitialize Time used: %lf%s\n", 
            (double)(d_init_end - d_init_begin) / CLOCKS_PER_SEC, ", Seconds");
    printf("Static: Sorting Time used: %lf%s\n", 
            (double)(s_end - s_begin) / CLOCKS_PER_SEC, ", Seconds");
    printf("Dynamic: Sorting Time used: %lf%s\n", 
            (double)(d_end - d_begin) / CLOCKS_PER_SEC, ", Seconds");
    printf("Static: Total Time used: %lf%s\n", 
            (double)(s_total_end - s_total_begin) / CLOCKS_PER_SEC, ", Seconds");
    printf("Dynamic: Total Time used: %lf%s\n", 
            (double)(d_total_end - d_total_begin) / CLOCKS_PER_SEC, ", Seconds");

	return 0;
}
