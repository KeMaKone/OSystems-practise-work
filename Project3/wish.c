#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <time.h>
#include "wish.h"

void errorHandle(){
    char* errMsg = "An error has occurred\n";
    write(STDERR_FILENO, errMsg, strlen(errMsg));
    exit(1);
}

int readInput(char* buffer, FILE* fp){
    size_t bufsize = BUFSIZE*sizeof(char);
    return getline(&buffer, &bufsize, fp);
}

//parses the input with strsep returns the amount of tokens
int parseInput(char* buffer, char* tokens[]){
    int i;
    char* token;
    //remove the newline character
    buffer[strlen(buffer)-1] = '\0';
    for(i = 0; (token = strsep(&buffer, " ")) != NULL; i++){
        tokens[i] = token;
    }

    return i;
}

int changeDirectory(char* tokens[]){
    if(tokens[1] == NULL){
        printf("No directory specified.\n");
        return 1;
    }

    if(chdir(tokens[1]) == -1){
        printf("Directory not found.\n");
        return 1;
    }

    return 0;
}

int setPath(char* tokens[], char* path[]){
    if(tokens[1] == NULL){
        printf("No path specified.\n");
        return 1;
    }

    //Write Tokens to path
    for(int i=0; tokens[i+1] != NULL; i++) strcpy(path[i], tokens[i+1]);

    return 0;
}


//TODO Nice to have: handle uppers and lowers
int handleShellCommands(char* tokens[], char* path[]){
    if(strcmp(tokens[0], "exit") == 0){
        exitShell();
    } else if(strcmp(tokens[0], "help") == 0){
        helpText();
        return(0);
    } else if(strcmp(tokens[0], "cd") == 0){
        changeDirectory(tokens);
        return(0);
    } else if(strcmp(tokens[0], "path") == 0){
        setPath(tokens, path);
        return(0);
    }
    return -1;
}

int checkPath(char* tokens[], char* path[]){
    char checkPath[PATHLENGTH];
    for(int i=0; path[i] != NULL ;i++){
        strcpy(checkPath, path[i]);
        strcat(checkPath, "/");
        strcat(checkPath, tokens[0]);
        if(access(checkPath, F_OK)==0){
            return(0);
        }
    }
    printf("Command not in path\n");
    return(-1);
}

int handleExternalCommands(char* tokens[], char* path[], int* bgFlag){
    int pid;
    //fork
    switch(pid = fork()){
        case -1:
            errorHandle();
        case 0:
            if(checkPath(tokens, path) == 0) if(execvp(tokens[0], tokens) == -1) errorHandle();
        default:
            if(bgFlag == 0) if(wait(&pid) == -1) errorHandle();
    }

    return(0);
}

//shell 
int main(){
    char inputBuffer[BUFSIZE]; 
    char* tokens[BUFSIZE];  //TODO CHANGE TOKENS TO LINKED LIST
    char* path[PATHSIZE]; //TODO CHANGE PATH TO LINKED LIST
    int iaFlag = 1;
    int bgFlag = 0;

    //clear arrays
    memset(inputBuffer, 0, BUFSIZE*sizeof(char));
    memset(tokens, 0, BUFSIZE*__SIZEOF_POINTER__);
    memset(path, 0, PATHSIZE*__SIZEOF_POINTER__);

    path[0] = DEFFAULTPATH;

    signal(SIGALRM, autoLogout);

    welcomeText();

    //shell loop
    while(1){
        //alarm(LOGOUTITME); //autologout
        
        if(iaFlag != 0) printf(PROMPT);

        readInput(inputBuffer, stdin);
        parseInput(inputBuffer, tokens);
        
        //debug parse
        for(int i =0;tokens[i] != NULL;i++) printf("%s", tokens[i]);
        puts("");       

        if(handleShellCommands(tokens, path) != 0){
            handleExternalCommands(tokens, path, &bgFlag);
        }

        //clearing buffers
        memset(inputBuffer, 0, BUFSIZE*sizeof(char));
        memset(tokens, 0, BUFSIZE*__SIZEOF_POINTER__);
    }
}