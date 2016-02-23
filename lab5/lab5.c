#include <stdio.h>
#include <stdlib.h>

struct Mark {
	int x;
	int y;
};

typedef struct Mark Mark;

/* load the structure that p points to with the date from f */
void getInfo (FILE * f, Mark * p);

/* write the data stored in structure item into output file f */
void printInfo (FILE * f, Mark item);

/* compare what pointers a and b point to; to be used by qsort() */
int compare (const void * a, const void * b);

int main()
{
	Mark list[100];
	Mark mark;
	int size = 0, i, col = 0;
	FILE * fin;

	fin = fopen ("lab5.dat", "r");
	if ( fin == NULL )
	{
		printf ("Cannot open file.\n");
		exit(1);
	}

	while ( !feof(fin) )
	{
		getInfo (fin, &mark);
		list[size++] = mark;
        //printf("\t (%d, %d)\n", mark.x, mark.y);
	}

	// use qsort() to sort data in list
    qsort(list, size, sizeof(Mark), compare);

	for (i = 0; i < size; i++)
	{
		printInfo (stdout, list[i]);
		if ( ++col % 5 == 0 )
			printf("\n");
	}

	fclose (fin);

	return 0;
}

/* complete the following helper functions */

void getInfo (FILE * f, Mark * p)
{
    //File f is already opened in main()
    //while(1) {
    int res = fscanf(f, "%d %d", &(p->x), &(p->y));
    /*
    if(res == 2)
        printf("IN: (%d, %d)", p->x, p->y);
    else 
        printf("No match.\n");
    */
        

    //}

}

void printInfo (FILE * f, Mark item)
{
	// display each mark in format of (x, y) 
	// and five marks per line 
    //fprintf(f, "(%d, %d)\n", item.x, item.y);
    fprintf(f, "*");

}

int compare (const void * a, const void * b){

    Mark * ma = (Mark *) a;
    Mark * mb = (Mark *) b;
    if(ma->x == mb->x)
        return (ma->y > mb->y);
    else
        return (ma->x > mb->x);
}


