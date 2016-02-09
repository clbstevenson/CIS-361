#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 1

char* strnsub (char *p, int n);

int main()
{
    char line[] = "is textbook was bought from that bookstore";  
    //char line[] = "aaaaaa";
	char *p1, *p2;

	//set p1 to the beginning of string line;
    p1 = line;
	while ( *p1 != '\0' ) //more to check with p1 ) 	
	{
		//set p2 to the position immediately after p1
        p2 = p1+1;
		
		while ( *(p2+LEN) != '\0') //more to check with p2 )	
		{
			//if a match is found		
            int x = strncmp(p1, p2, LEN);
            if(x == 0)
				goto done;	
				
			//advance p2 to the next position
            p2++;
		}

		//advance p1 to the next position
        p1++;
	}

done:	printf ("the first substring: %s\n", strnsub(p1, LEN));
	printf ("the second substring: %s\n", strnsub(p2, LEN));

	return 0;
}


// returns a string with the first n characters of string p

char* strnsub (char *p, int n)
{
	// write function definition here

    char newp[n+1];
    int id = 0;
    while(id < n) {
        newp[id] = *(p+id);
        id++;
    }
    //don't forget the (null) Terminator
    newp[id] = '\0';
    p = newp;
    
    return p;
}
