#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    int prevSpace = 1;
    int wordcount = 0;
    int totalsize = 0;
    float avgsize;

    printf ("Enter text (Ctrl-D to quit).\n");
    while(ch = getchar(), ch!=EOF){
        if(isalnum(ch)) {
            totalsize++;
            prevSpace = 0; 
        } else if(isspace(ch)) {
            if(prevSpace == 0)
                wordcount++;
            prevSpace = 1;
        }
        putchar(ch);
    }
    avgsize = 1.0 * totalsize / wordcount;
    //printf(">>> totalsize = %d\n", totalsize);
    printf("Word Count: %d \nAverage Word Length: %.03f\n", 
            wordcount, avgsize); 
    return 0;
}
