#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    
    char *pharse = argv[1];
    int fd[2];
    if (pipe(fd) == -1){
        printf("не могу создать канал");
        return 1;
    }
    
    pid_t pid = fork();
    if (pid == -1){
        fprintf(stderr, "not begin process: %s\n", strerror(errno));
        return 1;
    }
    
    if(!pid){
        dup2(fd[1], 1);
        close(fd[0]);
        if(execle("/usr/bin/python3.8", "/usr/bin/python3.8", "./rsspy.py", NULL) == -1){
            fprintf(stderr, "no run python scrypt: %s\n", strerror(errno));
            return 1;
        } 
    }

    pid_t pid2 = fork();
    if (!pid2){
        dup2(fd[0], 0);
        close(fd[1]);    
        char line[255];
        while (fgets(line, 255, stdin)){
            printf ("%s\n", line);
            if (line[0] == '\t'){
                char launch[255];
                sprintf(launch, "%s", line + 1);
            
                pid_t pid3 = fork();
                if(!pid3){
                execlp("x-www-browser", "x-www-browser", launch, NULL);
                // system(launch);
            }
        }
    }    
    }
    

    puts("WORK MUTHER FUCKER!!!");
    return 0;
}
