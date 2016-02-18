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
    int id = 0;
    fp = fopen(fname, "r");
    while((c = getc(fp)) != EOF) {
        printf("%c ", c);
        //found[c-'A'] = 22;
        if(!isalpha(c))
            continue;
        if(islower(c))
            id = c-'a';
        else if(isupper(c))
            id = c-'A';
        found[id] = found[id] + 1;
        //printf("new found[%d] = %f\n", id, found[id]); 
        total++;
    }
    printf("\ntotal read: %d\n", total);
    id = 0;
    float sum = 0;
    while(id < 26) {
        found[id] = found[id] / total;
        sum += found[id];
        printf("%c = %f\n", 'A' + id, found[id]);
        id++;
    }
    printf("sum = %f\n", sum);
    
}
 
// Rotate the character in parameter ch down the alphabet for the number of 
// positions as given in parameter num and return the resulting character.
char rotate ( char ch, int num ) {
    if(isupper(ch))
        return ('A' + ((ch+num)-'A')%NUM);
    else if(islower(ch))
        return ('a' + ((ch+num)-'a')%NUM);
    else 
        return ch + 1;
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
    //calcFreq(calcfreqs, "test1");
    calcFreq(calcfreqs, "test2");
    printf("A: %f\n", (*calcfreqs));
    
    int delta = 3;
    char x = 'x';
    char nx = rotate(x, delta);
    printf("%c + %d = %c\n", x, delta, nx);
    return 0;
}
