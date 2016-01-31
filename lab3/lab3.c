// lab3.c - measure execution time of C code

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main ()
{
	const int MaxSize = 25000;
	int i, j, temp;


	// Part one: processing a statically allocated array


	int staticArray[MaxSize];		// declare an array 

	for (i=0; i<MaxSize; i++)		// initialize the array with a
		staticArray[i] = MaxSize-i;	// descending sequence of values

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

    /*
	// Part two: processing a dynamically allocated array

    int * dynamicArray;
    dynamicArray = (int*) malloc(MaxSize * sizeof(int));

    if(dynamicArray == NULL) {
        //ran out of memory
        exit(1);
    }

    //intialize the dynamic array
	for (i=0; i<MaxSize; i++)		// initialize the array with a
        *(dynamicArray+i) = MaxSize - i; // descending sequence of values

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
    }
    //end time for sorting dynamic array
    clock_t d_end = clock();

    //remember to free the dynamic array
    free(dynamicArray);

    */

	// Display the amount of time used for each part above
    printf("Static: Time used: %lf%s\n", 
            (double)(s_end - s_begin) / CLOCKS_PER_SEC, ", Seconds");
    //printf("Dynamic: Time used: %lf%s\n", 
    //        (double)(d_end - d_end) / CLOCKS_PER_SEC, ", Seconds");

	return 0;
}
