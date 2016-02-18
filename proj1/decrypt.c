#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM 26

// Load array 'given' with letter frequences for English from LetFreq.txt 
void readFreq(float given[], char fname[]) {
    FILE *fp;
    char str1[10], str2[10];

    int id = 0;
    float freq = -1;
    fp = fopen(fname, "r");
    while(id < 25) {
        fscanf(fp, "%s %s", str1, str2);
        given[id] = atof(str2); 
        id++;
    }
}

// Read the encoded text from an input file and accumulate letter frequency 
// data for the encoded text. Store the frequency data in array found.
void calcFreq ( float found[],  char fname[] ) {
    FILE *fp;
    char c;

    int total = 0;
    fp = fopen(fname, "r");
    while((c = fgetc(fp)) != EOF) {
        printf("%c ", c);
        //found[c-'A'] = 22;
        //if(islpha(c))
            continue;
        found[c-'A'] = found[c-'A'] + 1;
        total++;
    }
    printf("\nread through\n");
    int id = 0;
    while(id < 26) {
        found[id] = found[id] / total;
        printf("%c = %f\n", 'A' + id, found[id]);
        id++;
    }
    
}
 
// Rotate the character in parameter ch down the alphabet for the number of 
// positions as given in parameter num and return the resulting character.
char rotate ( char ch, int num ) {

}

// Compare the data in array found with frequency data in given[], looking
// for a key that will give you the best match. To do this, try each of the
// 26 rotations, and remember which gives the smallest difference between
// the frequencies you observed and the frequencies given. Return the key.
int findKey ( float given[], float found[] ) {

}
 
// Decrypt the encoded text in the input file using the key and 
// display the decoded text
void decrypt ( int key,  char fname[]  ) {

}

int main() {

    float* frequencies;
    frequencies = (float*) malloc(NUM *(sizeof(float)));
    readFreq(frequencies, "LetFreq.txt"); 
    printf("\nA: %f\n", (*frequencies+0));


    float* calcfreqs;
    calcfreqs = (float*) malloc(NUM*(sizeof(float)));
    calcFreq(calcfreqs, "test1");
    
    return 0;
}
