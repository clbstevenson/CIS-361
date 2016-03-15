#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 80
#define MAXARG 20

void background (char*);

int main() {

    char cmd[MAXLINE];
    pid_t pid;
    int status;

    for (; ;) {
        printf("mysh$ ");
        fgets(cmd, MAXLINE, stdin);    // read a command from user

        // if the command in cmd is "exit\n", then terminate.
        // otherwise, create a child process to handle that command
        if(strcmp(cmd, "exit\n") == 0) {
           printf("Exiting.\n");
           return 0; 
        }
        // fork
        // if the current process is the child  
        if(!(pid = fork())) {
           background(cmd); 
        }
        // else, this is the parent process 
        else {
            //wait until the child has finished executing the cmd 
            wait(&status); 
            //printf("Finished waiting; status: %d\n", status);
        }
        
    }
}

void background (char* cmd) {
    int i = 0;
    char *argv[MAXARG];

    // HERE you may use strtoke(cmd, "\t \n" to get each token
    // from cmd and then store it in array agrv sequentially.
    // strtok() returns NULL when the end of cmd is reached

    char *token = strtok(cmd, "\t \n");
    while(token != NULL) {
        //printf("%d %s\n", i, token);
        argv[i] = token;
        i++;
        token = strtok(NULL, "\t \n");
    }
    argv[i++] = NULL;

    if(execvp(argv[0], argv) < 0) {
        perror("exec failed");
        exit(1);
    }


}
