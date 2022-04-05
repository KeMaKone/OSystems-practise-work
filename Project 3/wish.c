#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <time.h>

#define BUFSIZE 256

void autoLogout(){
    printf("You have been logged out due to inactivity.\n");
    exit(0);
}

//shell 
int main(){
    char inputBuffer[BUFSIZE];

    char* arguments[BUFSIZE];
    char* token;
    int bgFlag = 0;
    int pid;
    int logoutTimer = 60;


    signal(SIGALRM, autoLogout);

    //Welcome
    fputs("Welcome to the shell!\n$ ", stdout);

    //shell loop
    while(1){
        alarm(logoutTimer); //alarm for auto logout

        //get input
        fgets(inputBuffer, BUFSIZE, stdin);

        //parse input with strtok
        token = strtok(inputBuffer, " \n");
        for(int i = 0;token != NULL; i++){
            arguments[i] = token;
            token = strtok(NULL, " \n");
        }

        //check for exit
        if(strcmp(arguments[0], "exit") == 0) exit(0);

        for(int i = 0; arguments[i] != NULL; i++) if(strcmp(arguments[i], "&")==0){
            bgFlag = 1;
            arguments[i] = NULL;
        }
        
        //fork
        switch(pid = fork()){
            case -1:
                perror("fork");
            case 0:
                if(execvp(arguments[0], arguments) == -1){
                    perror("execvp");
                    exit(1);
                }
                break;
            default:
                if(bgFlag == 0){
                    if(wait(&pid) == -1){
                        perror("wait");
                        exit(1);
                    }
                }
                break;
        }
        fputs("$ ", stdout);
        memset(arguments, 0, sizeof(arguments));
    }
}