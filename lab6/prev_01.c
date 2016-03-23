#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
    char* argArray[1024];
    char line[1024];

    pid_t pid;
    //pid_t child;
    int status;

    struct rusage prev_usage;
    struct rusage curr_usage;

    do {
        printf("Enter a command:  ");
        fgets(line, 1024, stdin);
        //printf("You entered %s\n", line);

        int err = getrusage(RUSAGE_CHILDREN, &prev_usage);
        if(err == -1) 
            printf("Error in calling getrusage on SELF\n");

        if((pid = fork()) < 0) {
            perror("fork failure");
            exit(1);
        }
        else if(pid == 0) {
            //this is the child process
            //call exec
            //printf("line %s\n", line);
            strtok(line, "\n");
            int index = 0;
            char *token = strtok(line, " ");
            if(strcmp(token, "quit") == 0) 
                exit(88);
            while(token != NULL) {
               argArray[index] = token; 
               index++;
               token = strtok(NULL, " ");
            }
            /*
            while((argArray[index]=strtok(line, " ")) != NULL) {
                index++;
            }
            */

            if(execvp(argArray[0], &argArray[0]) < 0) {
                perror("exec failed");
                exit(1);
            }
            //exit
        } else {
            // this is the parent process
            // wait 
            //printf("PID is not 0?  %d", pid); 
            wait(&status);
            int err_child = getrusage(RUSAGE_CHILDREN, &curr_usage);
            if(err_child == -1)
                printf("Error in getrusage on CHILDREN\n");

            //printf("status = %d\n", status);
            double prev_time = prev_usage.ru_utime.tv_sec +
                (prev_usage.ru_utime.tv_usec/1000000.0);
            double curr_time = curr_usage.ru_utime.tv_sec +
                (curr_usage.ru_utime.tv_usec/1000000.0);
            //printf("prev_time: %.6lf\n", prev_time);
            //printf("curr_time: %.6lf\n", curr_time);
            printf("User CPU time used: %.6lf seconds\n", 
                    curr_time-prev_time);
            
            printf("Involuntary Context Switches: %lu\n\n", 
                    curr_usage.ru_nivcsw - prev_usage.ru_nivcsw);

            if(status == 88 * 256){
                printf("Exiting.\n");
                return 0;
            }
            //read in the next line at the end
        }
    } while(strcmp(line, "quit") != 0);

    return 0;
}
